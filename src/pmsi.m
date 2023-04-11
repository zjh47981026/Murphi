
-- PMSI protocol

----------------------------------------------------------------------
-- Constants
----------------------------------------------------------------------
const
  --ProcCount: 3;          -- number processors
  ProcCount: 3;          -- number processors
  ValueCount:   2;       -- number of data values.
  MemCount: 2;
  --VC0: 0;                -- msg channel
  BufferSize: 4;   -- buffer size
  
  CoreReqBuffer_size: ProcCount; -- core request buffer
  CoreWBBuffer_size: ProcCount;  -- core write-back buffer
  PRLUT_size: ProcCount; --pending request lookup table

----------------------------------------------------------------------
-- Types
----------------------------------------------------------------------
type
  Proc: scalarset(ProcCount);   -- unordered range of processors
  Value: scalarset(ValueCount); -- arbitrary values for tracking coherence
  

  Home: enum { HomeType };      -- need enumeration for IsMember calls
  Node: union { Home , Proc };
  
  LUTindex:0..BufferSize-1;
  reissue: boolean;
  channelType: 0..ProcCount+1;
  canUpg: boolean;
  watchdogType: 0..12; 

  -- HeadPtr: 0...(ProcCount + ProcCount - 1);
  -- tailPtr: -1...(ProcCount + ProcCount - 1);

  MessageType: enum {  GetM,
                       GetS,
                       Upg,
                       PutM,
                       Data
                    };

  Message:
    Record
      mtype: MessageType;
      src: Node;
      dest: Node;
      -- do not need a destination for verification; the destination is indicated by which array entry in the Net the message is placed
      --vc: VCType;
      val: Value;
      --addr: addrType;
      rei : reissue;
    End;

  fifo:
    Record
      buf: array [0..BufferSize-1] of Message;
      head: 0..BufferSize-1;
      tail: 0..BufferSize-1;
    end;

  HomeState:
    Record
      state: enum { 
        H_IorS, 
        H_M,
        H_IorS_D,
        H_IorS_A,
        H_M_D,
        H_IorS_req,
        H_M_req
      }; 								--transient states during recall
    val: Value; 
    PRLUT: fifo;
    channel: channelType;
    requestor: Node;
    owner: Node;
    End;

  ProcState:
    Record
      state: enum { 
            Proc_I,
            Proc_S,
            Proc_M,
            Proc_IS_D,
            Proc_IM_D,
            Proc_SM_W,
            Proc_MI_WB,
            Proc_MS_WB,
            Proc_IM_D_I,
            Proc_IS_D_I,
            Proc_IM_D_S
      };
      val: Value;
      PR:fifo;
      PWB:fifo;
      channel: channelType;
      reiss: reissue;
      canUPG:canUpg;
      --watchdog: watchdogType;
    End;

----------------------------------------------------------------------
-- Variables
----------------------------------------------------------------------
var
  HomeNode:  HomeState;
  Procs: array [Proc] of ProcState;
  msg_processed: boolean;
  LastWrite: Value; -- Used to confirm that writes are not lost; this variable would not exist in real hardware
  --memcnt:0..MemCount;
  current_channel: channelType;
  channelNum:channelType; --temp value only
  temp_msg: Message;
  temp_msg_home: Message;
  home_send_msg: Message;
   --true for PR, false for PWB

----------------------------------------------------------------------
-- Procedures
----------------------------------------------------------------------
Procedure WatchdogIncrement(var watchdog_loc:watchdogType);
Begin
  assert (watchdog_loc <= 12) "watchdog timed out";
  watchdog_loc := watchdog_loc + 1;
End;

Procedure Enqueue(var f:fifo; msg: Message);
Begin
  assert (f.head != (f.tail + 1) % BufferSize) "a fifo overflowed!"; -- check if the queue is full
  f.buf[f.tail] := msg;
  f.tail := (f.tail + 1) % BufferSize;
End;

Function Dequeue(var f:fifo): Message;
  var msg: Message;
Begin
  --assert f.head != f.tail; -- check if the queue is not empty
  if (f.head = f.tail) then
    msg.mtype := UNDEFINED;
    return msg;
  endif;  
  msg := f.buf[f.head];
  undefine f.buf[f.head];
  f.head := (f.head + 1) % BufferSize;
  return msg;
End;


Function isBufferEmpty(var f:fifo): boolean;
Begin
  return (f.head = f.tail);
End;

Function Peek(var f:fifo): Message;
var msg:Message;
Begin
  --assert f.head != f.tail; -- check if the queue is not empty
  if (f.head = f.tail) then
    msg.mtype := UNDEFINED;
    return msg;
  endif;  
  msg := f.buf[f.head];
  return msg;
End;

Function checkLUT (var f:fifo ; p:Proc) : boolean;
Begin
 for i: LUTindex do
 if (f.buf[i].src = p) then  
   return true;
 endif;
 endfor;
 return false;
End;


Procedure ToBuffer(
            var f:fifo;
            mtype:MessageType;
            dest: Node;
            src:Node;
            val:Value
            
          );
var msg:Message; 
Begin
  -- data msg counts as WB, everything else counts as pending request
  --Assert (MultiSetCount(i:Net[dst], true) < NetMax) "Too many messages";
  msg.mtype := mtype;
  msg.dest := dest;
  msg.src   := src;
  msg.val   := val;
  Enqueue(f, msg);
End;

Procedure BufferReissue(var f:fifo);
Begin
  assert (f.head != f.tail) "Reiss called but buffer empty!";
  f.tail := (f.tail + BufferSize - 1) % BufferSize;
  undefine  f.buf[f.tail];
End;

Procedure ABSelect(channel:channelType);
begin
    if channel = 0 then
      for i:Node do
        if(Ismember(i, Proc)) then
          if (Procs[i].channel = 3 & (!isBufferEmpty(Procs[i].PR) | !isBufferEmpty(Procs[i].PWB))) then
            current_channel := Procs[i].channel;
          endif;
        endif;
        endfor;
      for i:Node do
        if(Ismember(i, Proc)) then
          if (Procs[i].channel = 2 & (!isBufferEmpty(Procs[i].PR) | !isBufferEmpty(Procs[i].PWB))) then
            current_channel := Procs[i].channel;
          endif;
        endif;
        endfor;
      for i:Node do
        if(Ismember(i, Proc)) then
          if (Procs[i].channel = 1 & (!isBufferEmpty(Procs[i].PR) | !isBufferEmpty(Procs[i].PWB))) then
            current_channel := Procs[i].channel;
          endif;
        endif;
        endfor;  
          
    elsif channel = 3 then
        for i:Node do
          if(Ismember(i, Proc)) then
            if(Procs[i].channel = 2 & (!isBufferEmpty(Procs[i].PR) | !isBufferEmpty(Procs[i].PWB))) then
              current_channel := Procs[i].channel;
            endif;
          endif;
        endfor;
        for i:Node do
          if(Ismember(i, Proc)) then
            if(Procs[i].channel = 1 & (!isBufferEmpty(Procs[i].PR) | !isBufferEmpty(Procs[i].PWB))) then
              current_channel := Procs[i].channel;
            endif;
          endif;
        endfor;
        for i:Node do 
          if(Ismember(i, Home)) then
            if (!isBufferEmpty(HomeNode.PRLUT) | HomeNode.state = H_IorS_req | HomeNode.state = H_M_req) then
              current_channel := 0;
            endif;
          endif;
        endfor;

    elsif channel = 1 then 
        for i:Node do
          if(Ismember(i, Home)) then
            if (!isBufferEmpty(HomeNode.PRLUT) | HomeNode.state = H_IorS_req | HomeNode.state = H_M_req) then
              current_channel := 0;
            endif;
          endif;
        endfor;
        for i:Node do
          if(Ismember(i, Proc)) then
            if(Procs[i].channel = 3 & (!isBufferEmpty(Procs[i].PR) | !isBufferEmpty(Procs[i].PWB))) then
              current_channel := Procs[i].channel;
            endif;
          endif;
        endfor;
        for i:Node do 
          if(Ismember(i,Proc)) then
            if(Procs[i].channel = 2 & (!isBufferEmpty(Procs[i].PR) | !isBufferEmpty(Procs[i].PWB))) then
              current_channel := Procs[i].channel;
            endif;
          endif;
        endfor;

      elsif channel =2 then
        for i:Node do 
            if(Ismember(i, Proc)) then
              if(Procs[i].channel = 1 & (!isBufferEmpty(Procs[i].PR) | !isBufferEmpty(Procs[i].PWB))) then
                current_channel := Procs[i].channel;
                endif;
            endif;
          endfor;
        for i:Node do
          if(Ismember(i,Home)) then
            if (!isBufferEmpty(HomeNode.PRLUT) | HomeNode.state = H_IorS_req | HomeNode.state = H_M_req) then
              current_channel := 0;
            endif;
          endif;
        endfor;
        for i:Node do 
            if(Ismember(i, Proc)) then
              if(Procs[i].channel = 3 & (!isBufferEmpty(Procs[i].PR) | !isBufferEmpty(Procs[i].PWB))) then
                current_channel := Procs[i].channel;
                endif;
            endif;
          endfor;
     
      endif;
end;
Procedure ErrorUnhandledMsg(msg:Message; n:Node);
Begin
  put "@ Error: Unhandled message type!\n";
  put "mtype: ";
  put msg.mtype;
  put "; ";

  put "src state: ";
  if (IsMember(msg.src, Proc)) then
    put Procs[msg.src].state;
  else
    put HomeNode.state;
  endif;

  put "dest state: ";
  if (IsMember(n, Proc)) then
    put Procs[n].state;
  else
    put HomeNode.state;
  endif;
  put "\n";

  error "Unhandled message type!";
End;

Procedure ErrorUnhandledState();
Begin
  error "Unhandled state!";
End;


Procedure ProcReceive(msg:Message; p:Proc);
Begin
--  put "Receiving "; put msg.mtype; put " on VC"; put msg.vc; 
--  put " at proc "; put p; put "\n";

  -- default to 'processing' message.  set to false otherwise
  msg_processed := true;

  alias ps:Procs[p].state do
  alias pv:Procs[p].val do
  alias pwbuffer: Procs[p].PWB do
  alias prebuffer: Procs[p].PR do
  alias preissue: Procs[p].reiss do
  --alias watch:Procs[p].watchdog do
  
  switch ps
    case Proc_I:
      --watch := 0;
      if ((msg.src = p & msg.mtype != Data) | (msg.src = HomeType & msg.dest = p)) then --own
      switch msg.mtype
      case Data:
      case Upg:

      else
        ErrorUnhandledMsg(msg, p);
      endswitch;
      else --other
        --do nothing
      endif;

    case Proc_S:
      --watch := 0;
      if ((msg.src = p & msg.mtype != Data) | (msg.src = HomeType & msg.dest = p)) then --own
        switch msg.mtype
          case Upg:
            ErrorUnhandledMsg(msg, p);
          case PutM:
            ErrorUnhandledMsg(msg, p);
          case Data:
            -- ErrorUnhandledMsg(msg, p);
          else
            ErrorUnhandledMsg(msg, p);

        endswitch;
      else --other
        switch msg.mtype
          case GetM:
           undefine pv;
            ps := Proc_I;
          case Upg:
          undefine pv;
            ps := Proc_I;
          case GetS:

          case Data:
            
          else
            ErrorUnhandledMsg(msg, p);
        endswitch;
      endif;

    case Proc_M:
      -- watch := 0;
      if ((msg.src = p & msg.mtype != Data) | (msg.src = HomeType & msg.dest = p)) then --own
        switch msg.mtype
          case Data:
            ErrorUnhandledMsg(msg, p);
          case Upg:
            ErrorUnhandledMsg(msg, p);
          case PutM:
            ErrorUnhandledMsg(msg, p);
          else
            ErrorUnhandledMsg(msg, p);
        endswitch;
      else --other
        switch msg.mtype
          case GetS:
            ps := Proc_MS_WB;
            ToBuffer(prebuffer, PutM, HomeType, p, pv);
          case GetM:
            ps := Proc_MI_WB;
            ToBuffer(prebuffer, PutM, HomeType, p, pv);
          case Upg:
            ErrorUnhandledMsg(msg, p);
          case PutM:
            ErrorUnhandledMsg(msg, p);
          case Data:
          else
            ErrorUnhandledMsg(msg, p);
        endswitch;
      endif;

    case Proc_IS_D:
      --WatchdogIncrement(watch);
      if ((msg.src = p & msg.mtype != Data) |(msg.src = HomeType & msg.dest = p)) then --own
        switch msg.mtype
          case GetS:

          case Data:
            if (msg.src = p) then
            else
            ps := Proc_S;
            pv := msg.val;
            endif;
          case Upg:
            ErrorUnhandledMsg(msg, p);
          case PutM:
            ErrorUnhandledMsg(msg, p);
          else
            ErrorUnhandledMsg(msg, p);
        endswitch;
      else --other
        switch msg.mtype
          case GetS:
            
          case GetM:
            ps := Proc_IS_D_I;
          case Upg:
            ps := Proc_IS_D_I;
          case PutM:

          case Data:
          
          else
            ErrorUnhandledMsg(msg, p);
        endswitch;
      endif;

    case Proc_IM_D:
      --WatchdogIncrement(watch);
      if ((msg.src = p & msg.mtype != Data) | (msg.src = HomeType & msg.dest = p)) then --own
        switch msg.mtype
          case GetM:

          case Data:
            if (msg.src = p) then 
            else
            LastWrite := pv;
              ps := Proc_M;
              -- LastWrite := msg.val; --write
            endif;
          case Upg:
            ErrorUnhandledMsg(msg, p);
          case PutM:
            ErrorUnhandledMsg(msg, p);
          else
            ErrorUnhandledMsg(msg, p);
        endswitch;
      else --other
        switch msg.mtype
          case GetS:
            ps := Proc_IM_D_S;
          case GetM:
            ps :=Proc_IM_D_I;
          case Upg:
            -- ErrorUnhandledMsg(msg, p);
          case PutM:
          
          case Data:
          else
            ErrorUnhandledMsg(msg, p);
        endswitch;
      endif;

    case Proc_SM_W:
      --WatchdogIncrement(watch);  
      if ((msg.src = p & msg.mtype != Data) | (msg.src = HomeType & msg.dest = p)) then --own
        switch msg.mtype
          case Data:
            if (msg.src = p) then
            else 
            ErrorUnhandledMsg(msg, p);
           endif;
          case Upg:
            ps := Proc_M;
            pv := msg.val;
            LastWrite := msg.val; --write
          case PutM:
            ErrorUnhandledMsg(msg, p);
          else
            ErrorUnhandledMsg(msg, p);
        endswitch;
      else --other
        switch msg.mtype
          case GetS:
            
          case GetM:
          undefine pv;
            ps := Proc_I;
            --reissue: not last write
            preissue := true;
            BufferReissue(prebuffer);
          case Upg:
          undefine pv;
            ps := Proc_I;
            preissue := true;
            BufferReissue(prebuffer);
            --reissue: not last write
          case PutM:
            ErrorUnhandledMsg(msg, p);
          case Data:

          else
            ErrorUnhandledMsg(msg, p);
        endswitch;
      endif;

    case Proc_MI_WB:
      --WatchdogIncrement(watch);
      if ((msg.src = p & msg.mtype != Data) | (msg.src = HomeType & msg.dest = p)) then --own
        switch msg.mtype
          case Data:

          case Upg:
            ErrorUnhandledMsg(msg, p);
          case PutM:
          
            ps := Proc_I;
            ToBuffer(pwbuffer, Data, HomeType, p, pv);
            undefine pv;
          else
            ErrorUnhandledMsg(msg, p);
        endswitch;
      else --other
        switch msg.mtype
          case GetS:
            
          case GetM:
            
          case Upg:
            ErrorUnhandledMsg(msg, p);
          case PutM:
            ErrorUnhandledMsg(msg, p);
          case Data:

          else
            ErrorUnhandledMsg(msg, p);
        endswitch;
      endif;

      case Proc_MS_WB:
      --WatchdogIncrement(watch);
      if ((msg.src = p & msg.mtype != Data) | (msg.src = HomeType & msg.dest = p)) then --own
        switch msg.mtype
          case Data:

          case Upg:
            ErrorUnhandledMsg(msg, p);
          case PutM:
            ps := Proc_S;
            ToBuffer(pwbuffer, Data, HomeType, p, pv);
          else
            ErrorUnhandledMsg(msg, p);
        endswitch;
      else --other
        switch msg.mtype
          case GetS:
            
          case GetM:
            ps := Proc_MI_WB;
          case Upg:
            ErrorUnhandledMsg(msg, p);
          case PutM:
            ErrorUnhandledMsg(msg, p);
          case Data:

          else
            ErrorUnhandledMsg(msg, p);
        endswitch;
      endif;

    case Proc_IM_D_I:
      --WatchdogIncrement(watch);
      if ((msg.src = p & msg.mtype != Data) | (msg.src = HomeType & msg.dest = p)) then --own
        switch msg.mtype
          case GetM:

          case Data:
            ps := Proc_MI_WB;
            ToBuffer(prebuffer, PutM, HomeType, p, UNDEFINED);
            LastWrite := msg.val; --write
          case Upg:
            ErrorUnhandledMsg(msg, p);
          case PutM:
            ErrorUnhandledMsg(msg, p);
          else
            ErrorUnhandledMsg(msg, p);
        endswitch;
      else --other
        switch msg.mtype
          case GetS:
            
          case GetM:
            
          case Upg:
            ErrorUnhandledMsg(msg, p);
          case PutM:

          case Data:

          else
            ErrorUnhandledMsg(msg, p);
        endswitch;
      endif;

    case Proc_IS_D_I:
      -- WatchdogIncrement(watch);
      if ((msg.src = p & msg.mtype != Data) | (msg.src = HomeType & msg.dest = p)) then --own
        switch msg.mtype
          case GetS:

          case Data:
            if (msg.src = p)then
            else

              
              pv := msg.val;
              undefine pv;
              ps := Proc_I;
            endif;
          case Upg:
            ErrorUnhandledMsg(msg, p);
          case PutM:
            ErrorUnhandledMsg(msg, p);
          else
            ErrorUnhandledMsg(msg, p);
        endswitch;
      else --other
        switch msg.mtype
          case GetS:
            
          case GetM:
            
          case Upg:
            
          case PutM:

          case Data:

          else
            ErrorUnhandledMsg(msg, p);
        endswitch;
      endif;

    case Proc_IM_D_S:
      -- WatchdogIncrement(watch);
      if ((msg.src = p & msg.mtype != Data) | (msg.src = HomeType & msg.dest = p)) then --own
        switch msg.mtype
          case GetM:

          case Data:
            ps := Proc_MS_WB;
            ToBuffer(prebuffer, PutM, HomeType, p, UNDEFINED);
          case Upg:
            ErrorUnhandledMsg(msg, p);
          case PutM:
            ErrorUnhandledMsg(msg, p);
          else
            ErrorUnhandledMsg(msg, p);
        endswitch;
      else --other
        switch msg.mtype
          case GetS:
            
          case GetM:
            ps := Proc_IM_D_I;
          case Upg:
            -- ErrorUnhandledMsg(msg, p);
          case PutM:
          
          case Data:

          else
            ErrorUnhandledMsg(msg, p);
        endswitch;
      endif;
  else
    ErrorUnhandledState();

  endswitch;
  
  endalias;
  endalias;
  endalias;
  endalias;
  endalias;

End;



Procedure HomeSend(
                  mtype:MessageType;
                  dest: Node;
                  val:Value
                );
var msg:Message; 
begin
  msg.mtype := mtype;
  msg.dest := dest;
  msg.src   := HomeType;
  msg.val   := val;
  home_send_msg := msg;
  for i:Proc do
    ProcReceive(msg, i);
  endfor;
end;

-- These aren't needed for Valid/Invalid protocol, but this is a good way of writing these functions




Procedure HomeReceive(msg:Message);
Begin
-- Debug output may be helpful:
--  put "Receiving "; put msg.mtype; put " on VC"; put msg.vc; 
--  put " at home -- "; put HomeNode.state;

  -- The line below is not needed in Valid/Invalid protocol.  However, the 
  -- compiler barfs if we put this inside a switch, so it is useful to
  -- pre-calculate the sharer count here
  
   
  -- default to 'processing' message.  set to false otherwise
  msg_processed := true;

  switch HomeNode.state
  case H_IorS:
    switch msg.mtype
      case GetS:
        HomeSend(Data, msg.src, HomeNode.val);

      case GetM:
        HomeNode.state := H_M;
        HomeSend(Data, msg.src, HomeNode.val);
        HomeNode.owner := msg.src;

      case Upg:
        HomeNode.state := H_M;
        HomeNode.owner := msg.src;


      case PutM:
        if (msg.src = HomeNode.owner) then
          ErrorUnhandledMsg(msg, HomeType);
        else
 
        endif;
      
      case Data:
        if (IsUndefined(HomeNode.requestor)) then
          HomeNode.val := msg.val; 
          -- ErrorUnhandledMsg(msg, HomeType);
        else 
          ErrorUnhandledMsg(msg, HomeType);
        endif;

      else
        ErrorUnhandledMsg(msg, HomeType);
    endswitch;
    

    case H_M:
      switch msg.mtype
        case GetS:
          undefine HomeNode.owner;
          HomeNode.requestor := msg.src;
          HomeNode.state := H_IorS_D;      
        case GetM:
          HomeNode.owner := msg.src;
          HomeNode.requestor := msg.src;
          HomeNode.state :=H_M_D;
          
        case Upg :
          ErrorUnhandledMsg(msg, HomeType);

        case PutM:
          if (msg.src = HomeNode.owner) then
            undefine HomeNode.owner;
            HomeNode.state := H_IorS_D;           
          endif;

        
        case Data:
          if(isundefined(HomeNode.requestor)) then
            HomeNode.state := H_IorS_A;
            undefine HomeNode.owner;
            HomeNode.val := msg.val;
          else
             ErrorUnhandledMsg(msg, HomeType);
          endif;
          
        else
          ErrorUnhandledMsg(msg, HomeType);
    endswitch;
    

  case H_IorS_D:
    switch msg.mtype
      case GetS:
        msg_processed := false;

      case GetM:
        msg_processed := false;
        
      case Upg:
        ErrorUnhandledMsg(msg, HomeType);

      case PutM:
        if (msg.src = HomeNode.owner) then
          msg_processed := false;
        else

        endif;
      
      case Data:
        if (IsUndefined(HomeNode.requestor)) then 
          HomeNode.state := H_IorS;
          HomeNode.val := msg.val;
          
        else 
          HomeNode.state := H_IorS_req;
          HomeNode.val := msg.val;
        endif;

      else
        ErrorUnhandledMsg(msg, HomeType);
    endswitch;
    

    case H_IorS_A:
      switch msg.mtype
        case GetS:
          HomeNode.state := H_IorS;
          HomeSend(Data, msg.src, HomeNode.val);
        case GetM:
          HomeNode.state := H_M;
          HomeNode.owner := msg.src;
          HomeSend(Data, msg.src, HomeNode.val);
        case Upg:
          ErrorUnhandledMsg(msg, HomeType);
        case PutM:
          -- if (msg.src = HomeNode.owner) then

            HomeNode.state := H_IorS;

          -- else
          --   -- ErrorUnhandledMsg(msg, HomeType);
          -- endif;
        case Data:
          if (IsUndefined(HomeNode.requestor)) then 
            ErrorUnhandledMsg(msg, HomeType);
          else 
            ErrorUnhandledMsg(msg, HomeType);
          endif;
        else
          ErrorUnhandledMsg(msg, HomeType);
    endswitch;
    

  case H_M_D:
    switch msg.mtype
      case GetS:
        msg_processed := false;

      case GetM:
        msg_processed := false;

      case Upg:
        ErrorUnhandledMsg(msg, HomeType);

      case PutM:
        if (msg.src = HomeNode.owner) then
          ErrorUnhandledMsg(msg, HomeType);
        else

        endif;
      
      case Data:
        if (IsUndefined(HomeNode.requestor)) then 
          HomeNode.state := H_M;
        else 
          HomeNode.state := H_M_req;
        endif;

      else
        ErrorUnhandledMsg(msg, HomeType);
    endswitch;
    

  case H_IorS_req:
    switch msg.mtype
      case GetS:
        msg_processed := false;

      case GetM:
        msg_processed := false;

      case Upg:
        ErrorUnhandledMsg(msg, HomeType);

      case PutM:
        if (msg.src = HomeNode.owner) then
          ErrorUnhandledMsg(msg, HomeType);
        else

        endif;
      
      case Data:
        if (IsUndefined(HomeNode.requestor)) then 
          ErrorUnhandledMsg(msg, HomeType);
        else 
          ErrorUnhandledMsg(msg, HomeType);
        endif;

      else
        ErrorUnhandledMsg(msg, HomeType);

    endswitch;
    

    case H_M_req:
      switch msg.mtype
        case GetS:
          msg_processed := false;

        case GetM:
          msg_processed := false;

        case Upg:
          ErrorUnhandledMsg(msg, HomeType);

        case PutM:
          if (msg.src = HomeNode.owner) then
            ErrorUnhandledMsg(msg, HomeType);
          else

          endif;
        
        case Data:
            ErrorUnhandledMsg(msg, HomeType);

        else
          ErrorUnhandledMsg(msg, HomeType);

    endswitch;

  endswitch;
  
End;



----------------------------------------------------------------------
-- Rules
----------------------------------------------------------------------

-- core events

ruleset n:Proc Do
  alias p:Procs[n] Do


	ruleset v:Value Do
  	rule "@ P store"
   	 ((p.state = Proc_I & !p.reiss)) -- |  p.state = Proc_M | p.state = Proc_MI_WB | p.state = Proc_MS_WB)
    	==>
      switch p.state
        case Proc_I:
          --p.watchdog := 0;
          ToBuffer(p.PR, GetM, HomeType, n, UNDEFINED);
          p.state := Proc_IM_D;
          p.val := v;
 /*
        case Proc_M:
          --p.watchdog := 0;
          p.val := v;
          LastWrite := v;

        case Proc_MI_WB:
          p.val := v;
          LastWrite := v;

        case Proc_MS_WB:
          p.val := v;
          LastWrite := v;
*/
        else
      endswitch;
  	endrule;
	endruleset;

  ruleset v:Value do
    rule "reissue"
  (p.state = Proc_I & p.reiss) 
  ==>
    --p.watchdog := 0;
    ToBuffer(p.PR, GetM, HomeType, n, UNDEFINED);
    p.state := Proc_IM_D;
    p.reiss := false;
    p.val := v;
  	endrule;
	endruleset;

  
  rule "@ P load"
    ((p.state = Proc_I & !p.reiss))
  ==>
    switch p.state
      case Proc_I:
        --p.watchdog := 0;
        ToBuffer(p.PR, GetS, HomeType, n, UNDEFINED);
        p.state := Proc_IS_D;
      else

    endswitch;
  endrule;

  rule "@ P evict"
    ( p.state = Proc_S |  p.state = Proc_MS_WB )
  ==>
    switch p.state
      case Proc_S:
        --p.watchdog := 0;
        undefine p.val;
        p.state := Proc_I;

      case Proc_M:
        --p.watchdog := 0;
        ToBuffer(p.PR, PutM, HomeType, n, p.val);      
        p.state := Proc_MI_WB;

      case Proc_MS_WB:
        p.state := Proc_MI_WB;
      
      else

    endswitch;
  endrule;



 rule "@ M evict"
    ( p.state = Proc_M & !checkLUT(HomeNode.PRLUT,n))
  ==>
    --p.watchdog := 0;
    ToBuffer(p.PR, PutM, HomeType, n, p.val);      
    p.state := Proc_MI_WB;
endrule;

ruleset v:Value Do
  	rule "@ In S upg"
    (p.state = Proc_S & !checkLUT(HomeNode.PRLUT,n))
    ==>   
      --p.watchdog := 0;
      p.canUPG := true;
      for i:Proc do --all proc receive message
        if (Procs[i].state = Proc_IM_D |  Procs[i].state = Proc_IM_D_I |  Procs[i].state = Proc_IM_D_S) then
          p.canUPG := false;
          -- assert (p.state != Proc_S) "asad!";
        endif;
      endfor;
      if (p.canUPG) then 
          ToBuffer(p.PR, Upg, HomeType, n, v); --forward value to itself
          p.state := Proc_SM_W;
          p.canUPG := false;
      endif;
  	endrule;
	endruleset;

  endalias;
endruleset;
----------- new bus msg passing rules ----------------------
-- procs can only send one message per window

ruleset n:Proc Do
  alias p:Procs[n] Do
    rule "proc send to bus"
      (current_channel = p.channel)
    ==>
      if ( !isBufferEmpty(p.PWB)) then
        --PWB dequeue
        temp_msg := Dequeue(p.PWB);
        if(!isundefined(temp_msg.mtype)) then
          for i:Proc do --all proc receive message
            ProcReceive(temp_msg, i);
          endfor;
          HomeReceive(temp_msg); --mem LUT don't enqueue data, immediatly process
          -- Enqueue(HomeNode.PRLUT, temp_msg); --mem LUT enqueue data
        endif;
      elsif (!isBufferEmpty(p.PR) & isBufferEmpty(p.PWB)) then 
        if (!checkLUT(HomeNode.PRLUT,n)) then
        --PR dequeue 
          temp_msg := Dequeue(p.PR);
          if(!isundefined(temp_msg.mtype)) then
            for i:Proc do --all proc receive message
              ProcReceive(temp_msg, i);
            endfor;
            Enqueue(HomeNode.PRLUT, temp_msg);  --mem LUT enqueue msg
          endif;
        endif;
      else
        endif;
    ABSelect(current_channel); -- all nodes arbitor (proc and home rotate)/
    endrule;
  endalias;
endruleset;

--mem consume LUT (can it consume multiple?)
rule "mem consume LUT"
    (current_channel = 0)
  ==>
    temp_msg_home := Peek(HomeNode.PRLUT);
    if(HomeNode.state = H_IorS_req) then
      HomeSend(Data,HomeNode.requestor,HomeNode.val);
      undefine HomeNode.requestor;
      HomeNode.state := H_IorS;
    else
      if(HomeNode.state = H_M_req) then
        HomeSend(Data,HomeNode.requestor,HomeNode.val);
        undefine HomeNode.requestor;
        HomeNode.state := H_M;   
      else 
        if(!isundefined(temp_msg_home.mtype)) then
          HomeReceive(temp_msg_home);
          if (msg_processed) then
            temp_msg_home := Dequeue(HomeNode.PRLUT);
          endif;
        endif;
      endif;
    endif;
    -- if memcnt = 2 then
    --   memcnt := 0;
    ABSelect(current_channel);
    -- else 
    --   memcnt := memcnt + 1;
    -- endif;
endrule;

----------------------------------------------------------------------
-- Startstate
----------------------------------------------------------------------
startstate
	For v:Value do
    -- home node initialization
    HomeNode.state := H_IorS;
    undefine HomeNode.owner;
    undefine HomeNode.requestor;
    HomeNode.val := v;
	endfor;
  HomeNode.channel := 0;
  HomeNode.PRLUT.head := 0;
  HomeNode.PRLUT.tail := 0;
  --memcnt := 0;
	LastWrite := HomeNode.val;

  current_channel := 0;
  
  -- processor initialization
  channelNum := 1;
  for i:Proc do
    Procs[i].state := Proc_I;
    undefine Procs[i].val;
    Procs[i].channel := channelNum;
    Procs[i].PR.head := 0;
    Procs[i].PR.tail := 0;
    Procs[i].PWB.head := 0;
    Procs[i].PWB.tail := 0;
    Procs[i].reiss := false;
    Procs[i].canUPG :=false;
    --Procs[i].watchdog := 0;

    channelNum := channelNum+1;
  endfor;
endstartstate;

----------------------------------------------------------------------
-- Invariants
----------------------------------------------------------------------
invariant "Invalid implies empty owner"
  HomeNode.state = H_IorS
    ->
      IsUndefined(HomeNode.owner);

  invariant "processor in Modified state,  no Sharers"
  Forall n : Proc Do
    Forall m : Proc Do
      ((Procs[n].state = Proc_M) & (n != m)) 
        -> 
          (Procs[m].state != Proc_S & Procs[m].state != Proc_M)
    end
  end;
invariant "values in m state match last write"
  Forall n : Proc Do	
     Procs[n].state = Proc_M
    ->
			Procs[n].val = LastWrite --LastWrite is updated whenever a new value is created 
	end;
invariant "value is undefined while invalid"
  Forall n : Proc Do	
     Procs[n].state = Proc_I
    ->
			IsUndefined(Procs[n].val)
	end;
	

invariant "values in shared state match memory"
  Forall n : Proc Do	
     HomeNode.state = H_IorS & Procs[n].state = Proc_S
    ->
			HomeNode.val = Procs[n].val
	end;


/*

invariant "Invalid implies empty owner"
  HomeNode.state = H_Invalid | HomeNode.state = H_Shared
    ->
      IsUndefined(HomeNode.owner);

-- invariant "value in memory matches value of last write, when invalid"
--      HomeNode.state = H_Invalid 
--     ->
-- 			HomeNode.val = LastWrite;

invariant "values in valid state match last write"
  Forall n : Proc Do	
     Procs[n].state = P_Modified
    ->
			Procs[n].val = LastWrite --LastWrite is updated whenever a new value is created 
	end;
	
invariant "value is undefined while invalid"
  Forall n : Proc Do	
     Procs[n].state = P_Invalid
    ->
			IsUndefined(Procs[n].val)
	end;
	

-- Here are some invariants that are helpful for validating shared state.

invariant "modified implies empty sharers list"
  HomeNode.state = H_Modified
    ->
      MultiSetCount(i:HomeNode.sharers, true) = 0;

invariant "Invalid implies empty sharer list"
  HomeNode.state = H_Invalid
    ->
      MultiSetCount(i:HomeNode.sharers, true) = 0;

invariant "values in memory matches value of last write, when shared or invalid"
  Forall n : Proc Do	
     HomeNode.state = H_Shared | HomeNode.state = H_Invalid
    ->
			HomeNode.val = LastWrite
	end;

invariant "values in shared state match memory"
  Forall n : Proc Do	
     HomeNode.state = H_Shared & Procs[n].state = P_Shared
    ->
			HomeNode.val = Procs[n].val
	end;

invariant "home in M state implies owner exists"
  HomeNode.state = H_Modified
    ->
      HomeNode.owner != HomeType;

invariant "home in S state implies non-empty sharer list"
  HomeNode.state = H_Shared
    ->
      MultiSetCount(i: HomeNode.sharers, true) != 0;

  invariant "processor in Modified state,  no Sharers"
  Forall n : Proc Do
    Forall m : Proc Do
      ((Procs[n].state = P_Modified) & (n != m)) 
        -> 
          (Procs[m].state != P_Shared & Procs[m].state != P_Modified)
    end
  end;
*/



