/******************************
  Program "pmsi.m" compiled by "Caching Murphi Release 5.4.9"

  Murphi Last Compiled date: "Apr 10 2023"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Caching Murphi Release 5.4.9"
#define MURPHI_DATE "Apr 10 2023"
#define PROTOCOL_NAME "pmsi"
#define BITS_IN_WORLD 1544
#define ALIGN

/********************
  Include
 ********************/
#include "mu_prolog.hpp"

/********************
  Decl declaration
 ********************/

class mu_1_Proc: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Proc& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Proc& val)
    {
      if (val.defined())
	return ( s << mu_1_Proc::values[ int(val) - 1 ] );
      else
	return ( s << "Undefined" );
    };

  mu_1_Proc (const char *name, int os): mu__byte(1, 3, 2, name, os) {};
  mu_1_Proc (void): mu__byte(1, 3, 2) {};
  mu_1_Proc (int val): mu__byte(1, 3, 2, "Parameter or function result.", 0)
    { operator=(val); };
  const char * Name() { return values[ value() -1]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 1] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_Proc& a, mu_1_Proc& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
const char *mu_1_Proc::values[] =
  { "Proc_1","Proc_2","Proc_3",NULL };

/*** end scalarset declaration ***/
mu_1_Proc mu_1_Proc_undefined_var;

class mu_1_Value: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Value& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Value& val)
    {
      if (val.defined())
	return ( s << mu_1_Value::values[ int(val) - 4 ] );
      else
	return ( s << "Undefined" );
    };

  mu_1_Value (const char *name, int os): mu__byte(4, 5, 2, name, os) {};
  mu_1_Value (void): mu__byte(4, 5, 2) {};
  mu_1_Value (int val): mu__byte(4, 5, 2, "Parameter or function result.", 0)
    { operator=(val); };
  const char * Name() { return values[ value() -4]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 4] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_Value& a, mu_1_Value& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
const char *mu_1_Value::values[] =
  { "Value_1","Value_2",NULL };

/*** end scalarset declaration ***/
mu_1_Value mu_1_Value_undefined_var;

class mu_1_Home: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Home& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Home& val)
  {
    if (val.defined())
      return ( s << mu_1_Home::values[ int(val) - 6] );
    else return ( s << "Undefined" );
  };

  mu_1_Home (const char *name, int os): mu__byte(6, 6, 1, name, os) {};
  mu_1_Home (void): mu__byte(6, 6, 1) {};
  mu_1_Home (int val): mu__byte(6, 6, 1, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -6]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -6] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1_Home::values[] = {"HomeType",NULL };

/*** end of enum declaration ***/
mu_1_Home mu_1_Home_undefined_var;

class mu_1_Node: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Node& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Node& val)
    {
      if (val.defined())
	return ( s << mu_1_Node::values[ val.indexvalue() ] );
      else
	return ( s << "Undefined" );
    };

  // note thate lb and ub are not used if we have byte compacted state.
  mu_1_Node (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1_Node (void): mu__byte(0, 3, 3) {};
  mu_1_Node (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
    { operator=(val); };
  int indexvalue()
  {
    if ((value() >= 6) && (value() <= 6)) return (value() - 6);
    if ((value() >= 1) && (value() <= 3)) return (value() - 0);
  return 0;
  };
  inline int unionassign(int val)
  {
    if (val >= 0 && val <= 0) return value(val+6);
    if (val >= 1 && val <= 3) return value(val+0);
  return 0;
  };
  const char * Name() { return values[ indexvalue() ]; };
friend int CompareWeight(mu_1_Node& a, mu_1_Node& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ indexvalue() ] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
};
const char *mu_1_Node::values[] = {"HomeType","Proc_1","Proc_2","Proc_3",NULL };

/*** end union declaration ***/
mu_1_Node mu_1_Node_undefined_var;

class mu_1_LUTindex: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_LUTindex& val) { return mu__byte::operator=((int) val); };
  mu_1_LUTindex (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1_LUTindex (void): mu__byte(0, 3, 3) {};
  mu_1_LUTindex (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_LUTindex mu_1_LUTindex_undefined_var;

class mu_1_channelType: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_channelType& val) { return mu__byte::operator=((int) val); };
  mu_1_channelType (const char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu_1_channelType (void): mu__byte(0, 4, 3) {};
  mu_1_channelType (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_channelType mu_1_channelType_undefined_var;

class mu_1_watchdogType: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_watchdogType& val) { return mu__byte::operator=((int) val); };
  mu_1_watchdogType (const char *name, int os): mu__byte(0, 12, 4, name, os) {};
  mu_1_watchdogType (void): mu__byte(0, 12, 4) {};
  mu_1_watchdogType (int val): mu__byte(0, 12, 4, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_watchdogType mu_1_watchdogType_undefined_var;

class mu_1_MessageType: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_MessageType& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_MessageType& val)
  {
    if (val.defined())
      return ( s << mu_1_MessageType::values[ int(val) - 7] );
    else return ( s << "Undefined" );
  };

  mu_1_MessageType (const char *name, int os): mu__byte(7, 11, 3, name, os) {};
  mu_1_MessageType (void): mu__byte(7, 11, 3) {};
  mu_1_MessageType (int val): mu__byte(7, 11, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -7]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -7] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1_MessageType::values[] = {"GetM","GetS","Upg","PutM","Data",NULL };

/*** end of enum declaration ***/
mu_1_MessageType mu_1_MessageType_undefined_var;

class mu_1_Message
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1_MessageType mu_mtype;
  mu_1_Node mu_src;
  mu_1_Node mu_dest;
  mu_1_Value mu_val;
  mu_0_boolean mu_rei;
  mu_1_Message ( const char *n, int os ) { set_self(n,os); };
  mu_1_Message ( void ) {};

  virtual ~mu_1_Message(); 
friend int CompareWeight(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = CompareWeight(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = CompareWeight(a.mu_src, b.mu_src);
    if (w!=0) return w;
    w = CompareWeight(a.mu_dest, b.mu_dest);
    if (w!=0) return w;
    w = CompareWeight(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = CompareWeight(a.mu_rei, b.mu_rei);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = Compare(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = Compare(a.mu_src, b.mu_src);
    if (w!=0) return w;
    w = Compare(a.mu_dest, b.mu_dest);
    if (w!=0) return w;
    w = Compare(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = Compare(a.mu_rei, b.mu_rei);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_mtype.MultisetSort();
    mu_src.MultisetSort();
    mu_dest.MultisetSort();
    mu_val.MultisetSort();
    mu_rei.MultisetSort();
  }
  void print_statistic()
  {
    mu_mtype.print_statistic();
    mu_src.print_statistic();
    mu_dest.print_statistic();
    mu_val.print_statistic();
    mu_rei.print_statistic();
  }
  void clear() {
    mu_mtype.clear();
    mu_src.clear();
    mu_dest.clear();
    mu_val.clear();
    mu_rei.clear();
 };
  void undefine() {
    mu_mtype.undefine();
    mu_src.undefine();
    mu_dest.undefine();
    mu_val.undefine();
    mu_rei.undefine();
 };
  void reset() {
    mu_mtype.reset();
    mu_src.reset();
    mu_dest.reset();
    mu_val.reset();
    mu_rei.reset();
 };
  void print() {
    mu_mtype.print();
    mu_src.print();
    mu_dest.print();
    mu_val.print();
    mu_rei.print();
  };
  void print_diff(state *prevstate) {
    mu_mtype.print_diff(prevstate);
    mu_src.print_diff(prevstate);
    mu_dest.print_diff(prevstate);
    mu_val.print_diff(prevstate);
    mu_rei.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_mtype.to_state(thestate);
    mu_src.to_state(thestate);
    mu_dest.to_state(thestate);
    mu_val.to_state(thestate);
    mu_rei.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Message& operator= (const mu_1_Message& from) {
    mu_mtype.value(from.mu_mtype.value());
    mu_src.value(from.mu_src.value());
    mu_dest.value(from.mu_dest.value());
    mu_val.value(from.mu_val.value());
    mu_rei.value(from.mu_rei.value());
    return *this;
  };
};

  void mu_1_Message::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Message::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Message::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_mtype.set_self_2(name, ".mtype", os + 0 ); else mu_mtype.set_self_2(NULL, NULL, 0);
  if (name) mu_src.set_self_2(name, ".src", os + 8 ); else mu_src.set_self_2(NULL, NULL, 0);
  if (name) mu_dest.set_self_2(name, ".dest", os + 16 ); else mu_dest.set_self_2(NULL, NULL, 0);
  if (name) mu_val.set_self_2(name, ".val", os + 24 ); else mu_val.set_self_2(NULL, NULL, 0);
  if (name) mu_rei.set_self_2(name, ".rei", os + 32 ); else mu_rei.set_self_2(NULL, NULL, 0);
}

mu_1_Message::~mu_1_Message()
{
}

/*** end record declaration ***/
mu_1_Message mu_1_Message_undefined_var;

class mu__subrange_12: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_12& val) { return mu__byte::operator=((int) val); };
  mu__subrange_12 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_12 (void): mu__byte(0, 3, 3) {};
  mu__subrange_12 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_12 mu__subrange_12_undefined_var;

class mu_1__type_0
{
 public:
  mu_1_Message array[ 4 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_0 (const char *n, int os) { set_self(n, os); };
  mu_1__type_0 ( void ) {};
  virtual ~mu_1__type_0 ();
  mu_1_Message& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 3 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1__type_0& operator= (const mu_1__type_0& from)
  {
    for (int i = 0; i < 4; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<4; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<4; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 4; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 4; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 4; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 4; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 4; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 4; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_0::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_0::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_0::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 4; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 40 + os);
    delete[] s;
  }
};
mu_1__type_0::~mu_1__type_0()
{
}
/*** end array declaration ***/
mu_1__type_0 mu_1__type_0_undefined_var;

class mu_1__type_1: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_1& val) { return mu__byte::operator=((int) val); };
  mu_1__type_1 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_1 (void): mu__byte(0, 3, 3) {};
  mu_1__type_1 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1__type_2: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_2& val) { return mu__byte::operator=((int) val); };
  mu_1__type_2 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_2 (void): mu__byte(0, 3, 3) {};
  mu_1__type_2 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_2 mu_1__type_2_undefined_var;

class mu_1_fifo
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1__type_0 mu_buf;
  mu_1__type_1 mu_head;
  mu_1__type_2 mu_tail;
  mu_1_fifo ( const char *n, int os ) { set_self(n,os); };
  mu_1_fifo ( void ) {};

  virtual ~mu_1_fifo(); 
friend int CompareWeight(mu_1_fifo& a, mu_1_fifo& b)
  {
    int w;
    w = CompareWeight(a.mu_buf, b.mu_buf);
    if (w!=0) return w;
    w = CompareWeight(a.mu_head, b.mu_head);
    if (w!=0) return w;
    w = CompareWeight(a.mu_tail, b.mu_tail);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_fifo& a, mu_1_fifo& b)
  {
    int w;
    w = Compare(a.mu_buf, b.mu_buf);
    if (w!=0) return w;
    w = Compare(a.mu_head, b.mu_head);
    if (w!=0) return w;
    w = Compare(a.mu_tail, b.mu_tail);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_buf.MultisetSort();
    mu_head.MultisetSort();
    mu_tail.MultisetSort();
  }
  void print_statistic()
  {
    mu_buf.print_statistic();
    mu_head.print_statistic();
    mu_tail.print_statistic();
  }
  void clear() {
    mu_buf.clear();
    mu_head.clear();
    mu_tail.clear();
 };
  void undefine() {
    mu_buf.undefine();
    mu_head.undefine();
    mu_tail.undefine();
 };
  void reset() {
    mu_buf.reset();
    mu_head.reset();
    mu_tail.reset();
 };
  void print() {
    mu_buf.print();
    mu_head.print();
    mu_tail.print();
  };
  void print_diff(state *prevstate) {
    mu_buf.print_diff(prevstate);
    mu_head.print_diff(prevstate);
    mu_tail.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_buf.to_state(thestate);
    mu_head.to_state(thestate);
    mu_tail.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_fifo& operator= (const mu_1_fifo& from) {
    mu_buf = from.mu_buf;
    mu_head.value(from.mu_head.value());
    mu_tail.value(from.mu_tail.value());
    return *this;
  };
};

  void mu_1_fifo::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_fifo::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_fifo::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_buf.set_self_2(name, ".buf", os + 0 ); else mu_buf.set_self_2(NULL, NULL, 0);
  if (name) mu_head.set_self_2(name, ".head", os + 160 ); else mu_head.set_self_2(NULL, NULL, 0);
  if (name) mu_tail.set_self_2(name, ".tail", os + 168 ); else mu_tail.set_self_2(NULL, NULL, 0);
}

mu_1_fifo::~mu_1_fifo()
{
}

/*** end record declaration ***/
mu_1_fifo mu_1_fifo_undefined_var;

class mu_1__type_3: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_3& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_3& val)
  {
    if (val.defined())
      return ( s << mu_1__type_3::values[ int(val) - 12] );
    else return ( s << "Undefined" );
  };

  mu_1__type_3 (const char *name, int os): mu__byte(12, 18, 3, name, os) {};
  mu_1__type_3 (void): mu__byte(12, 18, 3) {};
  mu_1__type_3 (int val): mu__byte(12, 18, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -12]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -12] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1__type_3::values[] = {"H_IorS","H_M","H_IorS_D","H_IorS_A","H_M_D","H_IorS_req","H_M_req",NULL };

/*** end of enum declaration ***/
mu_1__type_3 mu_1__type_3_undefined_var;

class mu_1_HomeState
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1__type_3 mu_state;
  mu_1_Value mu_val;
  mu_1_fifo mu_PRLUT;
  mu_1_channelType mu_channel;
  mu_1_Node mu_requestor;
  mu_1_Node mu_owner;
  mu_1_HomeState ( const char *n, int os ) { set_self(n,os); };
  mu_1_HomeState ( void ) {};

  virtual ~mu_1_HomeState(); 
friend int CompareWeight(mu_1_HomeState& a, mu_1_HomeState& b)
  {
    int w;
    w = CompareWeight(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = CompareWeight(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = CompareWeight(a.mu_PRLUT, b.mu_PRLUT);
    if (w!=0) return w;
    w = CompareWeight(a.mu_channel, b.mu_channel);
    if (w!=0) return w;
    w = CompareWeight(a.mu_requestor, b.mu_requestor);
    if (w!=0) return w;
    w = CompareWeight(a.mu_owner, b.mu_owner);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_HomeState& a, mu_1_HomeState& b)
  {
    int w;
    w = Compare(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = Compare(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = Compare(a.mu_PRLUT, b.mu_PRLUT);
    if (w!=0) return w;
    w = Compare(a.mu_channel, b.mu_channel);
    if (w!=0) return w;
    w = Compare(a.mu_requestor, b.mu_requestor);
    if (w!=0) return w;
    w = Compare(a.mu_owner, b.mu_owner);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_state.MultisetSort();
    mu_val.MultisetSort();
    mu_PRLUT.MultisetSort();
    mu_channel.MultisetSort();
    mu_requestor.MultisetSort();
    mu_owner.MultisetSort();
  }
  void print_statistic()
  {
    mu_state.print_statistic();
    mu_val.print_statistic();
    mu_PRLUT.print_statistic();
    mu_channel.print_statistic();
    mu_requestor.print_statistic();
    mu_owner.print_statistic();
  }
  void clear() {
    mu_state.clear();
    mu_val.clear();
    mu_PRLUT.clear();
    mu_channel.clear();
    mu_requestor.clear();
    mu_owner.clear();
 };
  void undefine() {
    mu_state.undefine();
    mu_val.undefine();
    mu_PRLUT.undefine();
    mu_channel.undefine();
    mu_requestor.undefine();
    mu_owner.undefine();
 };
  void reset() {
    mu_state.reset();
    mu_val.reset();
    mu_PRLUT.reset();
    mu_channel.reset();
    mu_requestor.reset();
    mu_owner.reset();
 };
  void print() {
    mu_state.print();
    mu_val.print();
    mu_PRLUT.print();
    mu_channel.print();
    mu_requestor.print();
    mu_owner.print();
  };
  void print_diff(state *prevstate) {
    mu_state.print_diff(prevstate);
    mu_val.print_diff(prevstate);
    mu_PRLUT.print_diff(prevstate);
    mu_channel.print_diff(prevstate);
    mu_requestor.print_diff(prevstate);
    mu_owner.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_state.to_state(thestate);
    mu_val.to_state(thestate);
    mu_PRLUT.to_state(thestate);
    mu_channel.to_state(thestate);
    mu_requestor.to_state(thestate);
    mu_owner.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_HomeState& operator= (const mu_1_HomeState& from) {
    mu_state.value(from.mu_state.value());
    mu_val.value(from.mu_val.value());
    mu_PRLUT = from.mu_PRLUT;
    mu_channel.value(from.mu_channel.value());
    mu_requestor.value(from.mu_requestor.value());
    mu_owner.value(from.mu_owner.value());
    return *this;
  };
};

  void mu_1_HomeState::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_HomeState::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_HomeState::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_state.set_self_2(name, ".state", os + 0 ); else mu_state.set_self_2(NULL, NULL, 0);
  if (name) mu_val.set_self_2(name, ".val", os + 8 ); else mu_val.set_self_2(NULL, NULL, 0);
  if (name) mu_PRLUT.set_self_2(name, ".PRLUT", os + 16 ); else mu_PRLUT.set_self_2(NULL, NULL, 0);
  if (name) mu_channel.set_self_2(name, ".channel", os + 192 ); else mu_channel.set_self_2(NULL, NULL, 0);
  if (name) mu_requestor.set_self_2(name, ".requestor", os + 200 ); else mu_requestor.set_self_2(NULL, NULL, 0);
  if (name) mu_owner.set_self_2(name, ".owner", os + 208 ); else mu_owner.set_self_2(NULL, NULL, 0);
}

mu_1_HomeState::~mu_1_HomeState()
{
}

/*** end record declaration ***/
mu_1_HomeState mu_1_HomeState_undefined_var;

class mu_1__type_4: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_4& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_4& val)
  {
    if (val.defined())
      return ( s << mu_1__type_4::values[ int(val) - 19] );
    else return ( s << "Undefined" );
  };

  mu_1__type_4 (const char *name, int os): mu__byte(19, 29, 4, name, os) {};
  mu_1__type_4 (void): mu__byte(19, 29, 4) {};
  mu_1__type_4 (int val): mu__byte(19, 29, 4, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -19]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -19] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1__type_4::values[] = {"Proc_I","Proc_S","Proc_M","Proc_IS_D","Proc_IM_D","Proc_SM_W","Proc_MI_WB","Proc_MS_WB","Proc_IM_D_I","Proc_IS_D_I","Proc_IM_D_S",NULL };

/*** end of enum declaration ***/
mu_1__type_4 mu_1__type_4_undefined_var;

class mu_1_ProcState
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1__type_4 mu_state;
  mu_1_Value mu_val;
  mu_1_fifo mu_PR;
  mu_1_fifo mu_PWB;
  mu_1_channelType mu_channel;
  mu_0_boolean mu_reiss;
  mu_0_boolean mu_canUPG;
  mu_1_ProcState ( const char *n, int os ) { set_self(n,os); };
  mu_1_ProcState ( void ) {};

  virtual ~mu_1_ProcState(); 
friend int CompareWeight(mu_1_ProcState& a, mu_1_ProcState& b)
  {
    int w;
    w = CompareWeight(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = CompareWeight(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = CompareWeight(a.mu_PR, b.mu_PR);
    if (w!=0) return w;
    w = CompareWeight(a.mu_PWB, b.mu_PWB);
    if (w!=0) return w;
    w = CompareWeight(a.mu_channel, b.mu_channel);
    if (w!=0) return w;
    w = CompareWeight(a.mu_reiss, b.mu_reiss);
    if (w!=0) return w;
    w = CompareWeight(a.mu_canUPG, b.mu_canUPG);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_ProcState& a, mu_1_ProcState& b)
  {
    int w;
    w = Compare(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = Compare(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = Compare(a.mu_PR, b.mu_PR);
    if (w!=0) return w;
    w = Compare(a.mu_PWB, b.mu_PWB);
    if (w!=0) return w;
    w = Compare(a.mu_channel, b.mu_channel);
    if (w!=0) return w;
    w = Compare(a.mu_reiss, b.mu_reiss);
    if (w!=0) return w;
    w = Compare(a.mu_canUPG, b.mu_canUPG);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_state.MultisetSort();
    mu_val.MultisetSort();
    mu_PR.MultisetSort();
    mu_PWB.MultisetSort();
    mu_channel.MultisetSort();
    mu_reiss.MultisetSort();
    mu_canUPG.MultisetSort();
  }
  void print_statistic()
  {
    mu_state.print_statistic();
    mu_val.print_statistic();
    mu_PR.print_statistic();
    mu_PWB.print_statistic();
    mu_channel.print_statistic();
    mu_reiss.print_statistic();
    mu_canUPG.print_statistic();
  }
  void clear() {
    mu_state.clear();
    mu_val.clear();
    mu_PR.clear();
    mu_PWB.clear();
    mu_channel.clear();
    mu_reiss.clear();
    mu_canUPG.clear();
 };
  void undefine() {
    mu_state.undefine();
    mu_val.undefine();
    mu_PR.undefine();
    mu_PWB.undefine();
    mu_channel.undefine();
    mu_reiss.undefine();
    mu_canUPG.undefine();
 };
  void reset() {
    mu_state.reset();
    mu_val.reset();
    mu_PR.reset();
    mu_PWB.reset();
    mu_channel.reset();
    mu_reiss.reset();
    mu_canUPG.reset();
 };
  void print() {
    mu_state.print();
    mu_val.print();
    mu_PR.print();
    mu_PWB.print();
    mu_channel.print();
    mu_reiss.print();
    mu_canUPG.print();
  };
  void print_diff(state *prevstate) {
    mu_state.print_diff(prevstate);
    mu_val.print_diff(prevstate);
    mu_PR.print_diff(prevstate);
    mu_PWB.print_diff(prevstate);
    mu_channel.print_diff(prevstate);
    mu_reiss.print_diff(prevstate);
    mu_canUPG.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_state.to_state(thestate);
    mu_val.to_state(thestate);
    mu_PR.to_state(thestate);
    mu_PWB.to_state(thestate);
    mu_channel.to_state(thestate);
    mu_reiss.to_state(thestate);
    mu_canUPG.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_ProcState& operator= (const mu_1_ProcState& from) {
    mu_state.value(from.mu_state.value());
    mu_val.value(from.mu_val.value());
    mu_PR = from.mu_PR;
    mu_PWB = from.mu_PWB;
    mu_channel.value(from.mu_channel.value());
    mu_reiss.value(from.mu_reiss.value());
    mu_canUPG.value(from.mu_canUPG.value());
    return *this;
  };
};

  void mu_1_ProcState::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_ProcState::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_ProcState::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_state.set_self_2(name, ".state", os + 0 ); else mu_state.set_self_2(NULL, NULL, 0);
  if (name) mu_val.set_self_2(name, ".val", os + 8 ); else mu_val.set_self_2(NULL, NULL, 0);
  if (name) mu_PR.set_self_2(name, ".PR", os + 16 ); else mu_PR.set_self_2(NULL, NULL, 0);
  if (name) mu_PWB.set_self_2(name, ".PWB", os + 192 ); else mu_PWB.set_self_2(NULL, NULL, 0);
  if (name) mu_channel.set_self_2(name, ".channel", os + 368 ); else mu_channel.set_self_2(NULL, NULL, 0);
  if (name) mu_reiss.set_self_2(name, ".reiss", os + 376 ); else mu_reiss.set_self_2(NULL, NULL, 0);
  if (name) mu_canUPG.set_self_2(name, ".canUPG", os + 384 ); else mu_canUPG.set_self_2(NULL, NULL, 0);
}

mu_1_ProcState::~mu_1_ProcState()
{
}

/*** end record declaration ***/
mu_1_ProcState mu_1_ProcState_undefined_var;

class mu_1__type_5
{
 public:
  mu_1_ProcState array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_5 (const char *n, int os) { set_self(n, os); };
  mu_1__type_5 ( void ) {};
  virtual ~mu_1__type_5 ();
  mu_1_ProcState& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 3 ) )
      return array[ index - 1 ];
    else
      {
	if (index==UNDEFVAL) 
	  Error.Error("Indexing to %s using an undefined value.", name);
	else
	  Error.Error("Funny index value %d for %s: Proc is internally represented from 3 to 1.\nInternal Error in Type checking.",index, name);
	return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_5& operator= (const mu_1__type_5& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_5& a, mu_1__type_5& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_5& a, mu_1__type_5& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_5::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_5::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_5::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"Proc_1", i * 392 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"Proc_2", i * 392 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"Proc_3", i * 392 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1__type_5::~mu_1__type_5()
{
}
/*** end array declaration ***/
mu_1__type_5 mu_1__type_5_undefined_var;

const int mu_ProcCount = 3;
const int mu_ValueCount = 2;
const int mu_MemCount = 2;
const int mu_BufferSize = 4;
const int mu_CoreReqBuffer_size = 3;
const int mu_CoreWBBuffer_size = 3;
const int mu_PRLUT_size = 3;
const int mu_Proc_1 = 1;
const int mu_Proc_2 = 2;
const int mu_Proc_3 = 3;
const int mu_Value_1 = 4;
const int mu_Value_2 = 5;
const int mu_HomeType = 6;
const int mu_GetM = 7;
const int mu_GetS = 8;
const int mu_Upg = 9;
const int mu_PutM = 10;
const int mu_Data = 11;
const int mu_H_IorS = 12;
const int mu_H_M = 13;
const int mu_H_IorS_D = 14;
const int mu_H_IorS_A = 15;
const int mu_H_M_D = 16;
const int mu_H_IorS_req = 17;
const int mu_H_M_req = 18;
const int mu_Proc_I = 19;
const int mu_Proc_S = 20;
const int mu_Proc_M = 21;
const int mu_Proc_IS_D = 22;
const int mu_Proc_IM_D = 23;
const int mu_Proc_SM_W = 24;
const int mu_Proc_MI_WB = 25;
const int mu_Proc_MS_WB = 26;
const int mu_Proc_IM_D_I = 27;
const int mu_Proc_IS_D_I = 28;
const int mu_Proc_IM_D_S = 29;
/*** Variable declaration ***/
mu_1_HomeState mu_HomeNode("HomeNode",0);

/*** Variable declaration ***/
mu_1__type_5 mu_Procs("Procs",216);

/*** Variable declaration ***/
mu_0_boolean mu_msg_processed("msg_processed",1392);

/*** Variable declaration ***/
mu_1_Value mu_LastWrite("LastWrite",1400);

/*** Variable declaration ***/
mu_1_channelType mu_current_channel("current_channel",1408);

/*** Variable declaration ***/
mu_1_channelType mu_channelNum("channelNum",1416);

/*** Variable declaration ***/
mu_1_Message mu_temp_msg("temp_msg",1424);

/*** Variable declaration ***/
mu_1_Message mu_temp_msg_home("temp_msg_home",1464);

/*** Variable declaration ***/
mu_1_Message mu_home_send_msg("home_send_msg",1504);

void mu_WatchdogIncrement(mu_1_watchdogType& mu_watchdog_loc)
{
if ( !((mu_watchdog_loc) <= (12)) ) Error.Error("Assertion failed: watchdog timed out");
mu_watchdog_loc = (mu_watchdog_loc) + (1);
};
/*** end procedure declaration ***/

void mu_Enqueue(mu_1_fifo& mu_f, mu_1_Message& mu_msg)
{
if ( !((mu_f.mu_head) != (((mu_f.mu_tail) + (1)) % (mu_BufferSize))) ) Error.Error("Assertion failed: a fifo overflowed!");
mu_f.mu_buf[mu_f.mu_tail] = mu_msg;
mu_f.mu_tail = ((mu_f.mu_tail) + (1)) % (mu_BufferSize);
};
/*** end procedure declaration ***/

mu_1_Message mu_Dequeue(mu_1_fifo& mu_f)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

if ( (mu_f.mu_head) == (mu_f.mu_tail) )
{
mu_msg.mu_mtype.undefine();
return mu_msg;
}
mu_msg = mu_f.mu_buf[mu_f.mu_head];
mu_f.mu_buf[mu_f.mu_head].undefine();
mu_f.mu_head = ((mu_f.mu_head) + (1)) % (mu_BufferSize);
return mu_msg;
	Error.Error("The end of function Dequeue reached without returning values.");
};
/*** end function declaration ***/

mu_0_boolean mu_isBufferEmpty(mu_1_fifo& mu_f)
{
return (mu_f.mu_head) == (mu_f.mu_tail);
	Error.Error("The end of function isBufferEmpty reached without returning values.");
};
/*** end function declaration ***/

mu_1_Message mu_Peek(mu_1_fifo& mu_f)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

if ( (mu_f.mu_head) == (mu_f.mu_tail) )
{
mu_msg.mu_mtype.undefine();
return mu_msg;
}
mu_msg = mu_f.mu_buf[mu_f.mu_head];
return mu_msg;
	Error.Error("The end of function Peek reached without returning values.");
};
/*** end function declaration ***/

mu_0_boolean mu_checkLUT(mu_1_fifo& mu_f,const mu_1_Proc& mu_p)
{
{
for(int mu_i = 0; mu_i <= 3; mu_i++) {
if ( (mu_f.mu_buf[mu_i].mu_src) == (mu_p) )
{
return mu_true;
}
};
};
return mu_false;
	Error.Error("The end of function checkLUT reached without returning values.");
};
/*** end function declaration ***/

void mu_ToBuffer(mu_1_fifo& mu_f, const mu_1_MessageType& mu_mtype, const mu_1_Node& mu_dest, const mu_1_Node& mu_src, const mu_1_Value& mu_val)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

if (mu_mtype.isundefined())
  mu_msg.mu_mtype.undefine();
else
  mu_msg.mu_mtype = mu_mtype;
if (mu_dest.isundefined())
  mu_msg.mu_dest.undefine();
else
  mu_msg.mu_dest = mu_dest;
if (mu_src.isundefined())
  mu_msg.mu_src.undefine();
else
  mu_msg.mu_src = mu_src;
if (mu_val.isundefined())
  mu_msg.mu_val.undefine();
else
  mu_msg.mu_val = mu_val;
mu_Enqueue ( mu_f, mu_msg );
};
/*** end procedure declaration ***/

void mu_BufferReissue(mu_1_fifo& mu_f)
{
if ( !((mu_f.mu_head) != (mu_f.mu_tail)) ) Error.Error("Assertion failed: Reiss called but buffer empty!");
mu_f.mu_tail = (((mu_f.mu_tail) + (mu_BufferSize)) - (1)) % (mu_BufferSize);
mu_f.mu_buf[mu_f.mu_tail].undefine();
};
/*** end procedure declaration ***/

void mu_ABSelect(const mu_1_channelType& mu_channel)
{
if ( (mu_channel) == (0) )
{
{
for(int mu_i = 1; mu_i <= 6; mu_i++)
  if (( ( mu_i >= 1 ) && ( mu_i <= 3 ) )|| ( ( mu_i >= 6 ) && ( mu_i <= 6 ) )) {
if ( (mu_i>=1 && mu_i<=3) )
{
bool mu__boolexpr6;
  if (!((mu_Procs[mu_i].mu_channel) == (3))) mu__boolexpr6 = FALSE ;
  else {
bool mu__boolexpr7;
  if (!(mu_isBufferEmpty( mu_Procs[mu_i].mu_PR ))) mu__boolexpr7 = TRUE ;
  else {
  mu__boolexpr7 = (!(mu_isBufferEmpty( mu_Procs[mu_i].mu_PWB ))) ; 
}
  mu__boolexpr6 = (mu__boolexpr7) ; 
}
if ( mu__boolexpr6 )
{
mu_current_channel = mu_Procs[mu_i].mu_channel;
}
}
};
};
{
for(int mu_i = 1; mu_i <= 6; mu_i++)
  if (( ( mu_i >= 1 ) && ( mu_i <= 3 ) )|| ( ( mu_i >= 6 ) && ( mu_i <= 6 ) )) {
if ( (mu_i>=1 && mu_i<=3) )
{
bool mu__boolexpr8;
  if (!((mu_Procs[mu_i].mu_channel) == (2))) mu__boolexpr8 = FALSE ;
  else {
bool mu__boolexpr9;
  if (!(mu_isBufferEmpty( mu_Procs[mu_i].mu_PR ))) mu__boolexpr9 = TRUE ;
  else {
  mu__boolexpr9 = (!(mu_isBufferEmpty( mu_Procs[mu_i].mu_PWB ))) ; 
}
  mu__boolexpr8 = (mu__boolexpr9) ; 
}
if ( mu__boolexpr8 )
{
mu_current_channel = mu_Procs[mu_i].mu_channel;
}
}
};
};
{
for(int mu_i = 1; mu_i <= 6; mu_i++)
  if (( ( mu_i >= 1 ) && ( mu_i <= 3 ) )|| ( ( mu_i >= 6 ) && ( mu_i <= 6 ) )) {
if ( (mu_i>=1 && mu_i<=3) )
{
bool mu__boolexpr10;
  if (!((mu_Procs[mu_i].mu_channel) == (1))) mu__boolexpr10 = FALSE ;
  else {
bool mu__boolexpr11;
  if (!(mu_isBufferEmpty( mu_Procs[mu_i].mu_PR ))) mu__boolexpr11 = TRUE ;
  else {
  mu__boolexpr11 = (!(mu_isBufferEmpty( mu_Procs[mu_i].mu_PWB ))) ; 
}
  mu__boolexpr10 = (mu__boolexpr11) ; 
}
if ( mu__boolexpr10 )
{
mu_current_channel = mu_Procs[mu_i].mu_channel;
}
}
};
};
}
else
{
if ( (mu_channel) == (3) )
{
{
for(int mu_i = 1; mu_i <= 6; mu_i++)
  if (( ( mu_i >= 1 ) && ( mu_i <= 3 ) )|| ( ( mu_i >= 6 ) && ( mu_i <= 6 ) )) {
if ( (mu_i>=1 && mu_i<=3) )
{
bool mu__boolexpr12;
  if (!((mu_Procs[mu_i].mu_channel) == (2))) mu__boolexpr12 = FALSE ;
  else {
bool mu__boolexpr13;
  if (!(mu_isBufferEmpty( mu_Procs[mu_i].mu_PR ))) mu__boolexpr13 = TRUE ;
  else {
  mu__boolexpr13 = (!(mu_isBufferEmpty( mu_Procs[mu_i].mu_PWB ))) ; 
}
  mu__boolexpr12 = (mu__boolexpr13) ; 
}
if ( mu__boolexpr12 )
{
mu_current_channel = mu_Procs[mu_i].mu_channel;
}
}
};
};
{
for(int mu_i = 1; mu_i <= 6; mu_i++)
  if (( ( mu_i >= 1 ) && ( mu_i <= 3 ) )|| ( ( mu_i >= 6 ) && ( mu_i <= 6 ) )) {
if ( (mu_i>=1 && mu_i<=3) )
{
bool mu__boolexpr14;
  if (!((mu_Procs[mu_i].mu_channel) == (1))) mu__boolexpr14 = FALSE ;
  else {
bool mu__boolexpr15;
  if (!(mu_isBufferEmpty( mu_Procs[mu_i].mu_PR ))) mu__boolexpr15 = TRUE ;
  else {
  mu__boolexpr15 = (!(mu_isBufferEmpty( mu_Procs[mu_i].mu_PWB ))) ; 
}
  mu__boolexpr14 = (mu__boolexpr15) ; 
}
if ( mu__boolexpr14 )
{
mu_current_channel = mu_Procs[mu_i].mu_channel;
}
}
};
};
{
for(int mu_i = 1; mu_i <= 6; mu_i++)
  if (( ( mu_i >= 1 ) && ( mu_i <= 3 ) )|| ( ( mu_i >= 6 ) && ( mu_i <= 6 ) )) {
if ( (mu_i>=6 && mu_i<=6) )
{
bool mu__boolexpr16;
bool mu__boolexpr17;
  if (!(mu_isBufferEmpty( mu_HomeNode.mu_PRLUT ))) mu__boolexpr17 = TRUE ;
  else {
  mu__boolexpr17 = ((mu_HomeNode.mu_state) == (mu_H_IorS_req)) ; 
}
  if (mu__boolexpr17) mu__boolexpr16 = TRUE ;
  else {
  mu__boolexpr16 = ((mu_HomeNode.mu_state) == (mu_H_M_req)) ; 
}
if ( mu__boolexpr16 )
{
mu_current_channel = 0;
}
}
};
};
}
else
{
if ( (mu_channel) == (1) )
{
{
for(int mu_i = 1; mu_i <= 6; mu_i++)
  if (( ( mu_i >= 1 ) && ( mu_i <= 3 ) )|| ( ( mu_i >= 6 ) && ( mu_i <= 6 ) )) {
if ( (mu_i>=6 && mu_i<=6) )
{
bool mu__boolexpr18;
bool mu__boolexpr19;
  if (!(mu_isBufferEmpty( mu_HomeNode.mu_PRLUT ))) mu__boolexpr19 = TRUE ;
  else {
  mu__boolexpr19 = ((mu_HomeNode.mu_state) == (mu_H_IorS_req)) ; 
}
  if (mu__boolexpr19) mu__boolexpr18 = TRUE ;
  else {
  mu__boolexpr18 = ((mu_HomeNode.mu_state) == (mu_H_M_req)) ; 
}
if ( mu__boolexpr18 )
{
mu_current_channel = 0;
}
}
};
};
{
for(int mu_i = 1; mu_i <= 6; mu_i++)
  if (( ( mu_i >= 1 ) && ( mu_i <= 3 ) )|| ( ( mu_i >= 6 ) && ( mu_i <= 6 ) )) {
if ( (mu_i>=1 && mu_i<=3) )
{
bool mu__boolexpr20;
  if (!((mu_Procs[mu_i].mu_channel) == (3))) mu__boolexpr20 = FALSE ;
  else {
bool mu__boolexpr21;
  if (!(mu_isBufferEmpty( mu_Procs[mu_i].mu_PR ))) mu__boolexpr21 = TRUE ;
  else {
  mu__boolexpr21 = (!(mu_isBufferEmpty( mu_Procs[mu_i].mu_PWB ))) ; 
}
  mu__boolexpr20 = (mu__boolexpr21) ; 
}
if ( mu__boolexpr20 )
{
mu_current_channel = mu_Procs[mu_i].mu_channel;
}
}
};
};
{
for(int mu_i = 1; mu_i <= 6; mu_i++)
  if (( ( mu_i >= 1 ) && ( mu_i <= 3 ) )|| ( ( mu_i >= 6 ) && ( mu_i <= 6 ) )) {
if ( (mu_i>=1 && mu_i<=3) )
{
bool mu__boolexpr22;
  if (!((mu_Procs[mu_i].mu_channel) == (2))) mu__boolexpr22 = FALSE ;
  else {
bool mu__boolexpr23;
  if (!(mu_isBufferEmpty( mu_Procs[mu_i].mu_PR ))) mu__boolexpr23 = TRUE ;
  else {
  mu__boolexpr23 = (!(mu_isBufferEmpty( mu_Procs[mu_i].mu_PWB ))) ; 
}
  mu__boolexpr22 = (mu__boolexpr23) ; 
}
if ( mu__boolexpr22 )
{
mu_current_channel = mu_Procs[mu_i].mu_channel;
}
}
};
};
}
else
{
if ( (mu_channel) == (2) )
{
{
for(int mu_i = 1; mu_i <= 6; mu_i++)
  if (( ( mu_i >= 1 ) && ( mu_i <= 3 ) )|| ( ( mu_i >= 6 ) && ( mu_i <= 6 ) )) {
if ( (mu_i>=1 && mu_i<=3) )
{
bool mu__boolexpr24;
  if (!((mu_Procs[mu_i].mu_channel) == (1))) mu__boolexpr24 = FALSE ;
  else {
bool mu__boolexpr25;
  if (!(mu_isBufferEmpty( mu_Procs[mu_i].mu_PR ))) mu__boolexpr25 = TRUE ;
  else {
  mu__boolexpr25 = (!(mu_isBufferEmpty( mu_Procs[mu_i].mu_PWB ))) ; 
}
  mu__boolexpr24 = (mu__boolexpr25) ; 
}
if ( mu__boolexpr24 )
{
mu_current_channel = mu_Procs[mu_i].mu_channel;
}
}
};
};
{
for(int mu_i = 1; mu_i <= 6; mu_i++)
  if (( ( mu_i >= 1 ) && ( mu_i <= 3 ) )|| ( ( mu_i >= 6 ) && ( mu_i <= 6 ) )) {
if ( (mu_i>=6 && mu_i<=6) )
{
bool mu__boolexpr26;
bool mu__boolexpr27;
  if (!(mu_isBufferEmpty( mu_HomeNode.mu_PRLUT ))) mu__boolexpr27 = TRUE ;
  else {
  mu__boolexpr27 = ((mu_HomeNode.mu_state) == (mu_H_IorS_req)) ; 
}
  if (mu__boolexpr27) mu__boolexpr26 = TRUE ;
  else {
  mu__boolexpr26 = ((mu_HomeNode.mu_state) == (mu_H_M_req)) ; 
}
if ( mu__boolexpr26 )
{
mu_current_channel = 0;
}
}
};
};
{
for(int mu_i = 1; mu_i <= 6; mu_i++)
  if (( ( mu_i >= 1 ) && ( mu_i <= 3 ) )|| ( ( mu_i >= 6 ) && ( mu_i <= 6 ) )) {
if ( (mu_i>=1 && mu_i<=3) )
{
bool mu__boolexpr28;
  if (!((mu_Procs[mu_i].mu_channel) == (3))) mu__boolexpr28 = FALSE ;
  else {
bool mu__boolexpr29;
  if (!(mu_isBufferEmpty( mu_Procs[mu_i].mu_PR ))) mu__boolexpr29 = TRUE ;
  else {
  mu__boolexpr29 = (!(mu_isBufferEmpty( mu_Procs[mu_i].mu_PWB ))) ; 
}
  mu__boolexpr28 = (mu__boolexpr29) ; 
}
if ( mu__boolexpr28 )
{
mu_current_channel = mu_Procs[mu_i].mu_channel;
}
}
};
};
}
}
}
}
};
/*** end procedure declaration ***/

void mu_ErrorUnhandledMsg(mu_1_Message& mu_msg, const mu_1_Node& mu_n)
{
cout << "@ Error: Unhandled message type!\n";
cout << "mtype: ";
cout << ( mu_msg.mu_mtype );
cout << "; ";
cout << "src state: ";
if ( (mu_msg.mu_src>=1 && mu_msg.mu_src<=3) )
{
mu_Procs[mu_msg.mu_src].mu_state.print();
}
else
{
mu_HomeNode.mu_state.print();
}
cout << "dest state: ";
if ( (mu_n>=1 && mu_n<=3) )
{
mu_Procs[mu_n].mu_state.print();
}
else
{
mu_HomeNode.mu_state.print();
}
cout << "\n";
Error.Error("Error: Unhandled message type!");
};
/*** end procedure declaration ***/

void mu_ErrorUnhandledState()
{
Error.Error("Error: Unhandled state!");
};
/*** end procedure declaration ***/

void mu_ProcReceive(mu_1_Message& mu_msg, const mu_1_Proc& mu_p)
{
mu_msg_processed = mu_true;
{
  mu_1__type_4& mu_ps = mu_Procs[mu_p].mu_state;
{
  mu_1_Value& mu_pv = mu_Procs[mu_p].mu_val;
{
  mu_1_fifo& mu_pwbuffer = mu_Procs[mu_p].mu_PWB;
{
  mu_1_fifo& mu_prebuffer = mu_Procs[mu_p].mu_PR;
{
  mu_0_boolean& mu_preissue = mu_Procs[mu_p].mu_reiss;
switch ((int) mu_ps) {
case mu_Proc_I:
bool mu__boolexpr30;
bool mu__boolexpr31;
  if (!((mu_msg.mu_src) == (mu_p))) mu__boolexpr31 = FALSE ;
  else {
  mu__boolexpr31 = ((mu_msg.mu_mtype) != (mu_Data)) ; 
}
  if (mu__boolexpr31) mu__boolexpr30 = TRUE ;
  else {
bool mu__boolexpr32;
  if (!((mu_msg.mu_src) == (mu_HomeType))) mu__boolexpr32 = FALSE ;
  else {
  mu__boolexpr32 = ((mu_msg.mu_dest) == (mu_p)) ; 
}
  mu__boolexpr30 = (mu__boolexpr32) ; 
}
if ( mu__boolexpr30 )
{
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
break;
case mu_Upg:
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
break;
case mu_Proc_S:
bool mu__boolexpr33;
bool mu__boolexpr34;
  if (!((mu_msg.mu_src) == (mu_p))) mu__boolexpr34 = FALSE ;
  else {
  mu__boolexpr34 = ((mu_msg.mu_mtype) != (mu_Data)) ; 
}
  if (mu__boolexpr34) mu__boolexpr33 = TRUE ;
  else {
bool mu__boolexpr35;
  if (!((mu_msg.mu_src) == (mu_HomeType))) mu__boolexpr35 = FALSE ;
  else {
  mu__boolexpr35 = ((mu_msg.mu_dest) == (mu_p)) ; 
}
  mu__boolexpr33 = (mu__boolexpr35) ; 
}
if ( mu__boolexpr33 )
{
switch ((int) mu_msg.mu_mtype) {
case mu_Upg:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
case mu_PutM:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
case mu_Data:
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
else
{
switch ((int) mu_msg.mu_mtype) {
case mu_GetM:
mu_pv.undefine();
mu_ps = mu_Proc_I;
break;
case mu_Upg:
mu_pv.undefine();
mu_ps = mu_Proc_I;
break;
case mu_GetS:
break;
case mu_Data:
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
break;
case mu_Proc_M:
bool mu__boolexpr36;
bool mu__boolexpr37;
  if (!((mu_msg.mu_src) == (mu_p))) mu__boolexpr37 = FALSE ;
  else {
  mu__boolexpr37 = ((mu_msg.mu_mtype) != (mu_Data)) ; 
}
  if (mu__boolexpr37) mu__boolexpr36 = TRUE ;
  else {
bool mu__boolexpr38;
  if (!((mu_msg.mu_src) == (mu_HomeType))) mu__boolexpr38 = FALSE ;
  else {
  mu__boolexpr38 = ((mu_msg.mu_dest) == (mu_p)) ; 
}
  mu__boolexpr36 = (mu__boolexpr38) ; 
}
if ( mu__boolexpr36 )
{
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
case mu_Upg:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
case mu_PutM:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
else
{
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
mu_ps = mu_Proc_MS_WB;
mu_ToBuffer ( mu_prebuffer, mu_PutM, (int)mu_HomeType, (int)mu_p, mu_pv );
break;
case mu_GetM:
mu_ps = mu_Proc_MI_WB;
mu_ToBuffer ( mu_prebuffer, mu_PutM, (int)mu_HomeType, (int)mu_p, mu_pv );
break;
case mu_Upg:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
case mu_PutM:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
case mu_Data:
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
break;
case mu_Proc_IS_D:
bool mu__boolexpr39;
bool mu__boolexpr40;
  if (!((mu_msg.mu_src) == (mu_p))) mu__boolexpr40 = FALSE ;
  else {
  mu__boolexpr40 = ((mu_msg.mu_mtype) != (mu_Data)) ; 
}
  if (mu__boolexpr40) mu__boolexpr39 = TRUE ;
  else {
bool mu__boolexpr41;
  if (!((mu_msg.mu_src) == (mu_HomeType))) mu__boolexpr41 = FALSE ;
  else {
  mu__boolexpr41 = ((mu_msg.mu_dest) == (mu_p)) ; 
}
  mu__boolexpr39 = (mu__boolexpr41) ; 
}
if ( mu__boolexpr39 )
{
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
break;
case mu_Data:
if ( (mu_msg.mu_src) == (mu_p) )
{
}
else
{
mu_ps = mu_Proc_S;
mu_pv = mu_msg.mu_val;
}
break;
case mu_Upg:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
case mu_PutM:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
else
{
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
break;
case mu_GetM:
mu_ps = mu_Proc_IS_D_I;
break;
case mu_Upg:
mu_ps = mu_Proc_IS_D_I;
break;
case mu_PutM:
break;
case mu_Data:
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
break;
case mu_Proc_IM_D:
bool mu__boolexpr42;
bool mu__boolexpr43;
  if (!((mu_msg.mu_src) == (mu_p))) mu__boolexpr43 = FALSE ;
  else {
  mu__boolexpr43 = ((mu_msg.mu_mtype) != (mu_Data)) ; 
}
  if (mu__boolexpr43) mu__boolexpr42 = TRUE ;
  else {
bool mu__boolexpr44;
  if (!((mu_msg.mu_src) == (mu_HomeType))) mu__boolexpr44 = FALSE ;
  else {
  mu__boolexpr44 = ((mu_msg.mu_dest) == (mu_p)) ; 
}
  mu__boolexpr42 = (mu__boolexpr44) ; 
}
if ( mu__boolexpr42 )
{
switch ((int) mu_msg.mu_mtype) {
case mu_GetM:
break;
case mu_Data:
if ( (mu_msg.mu_src) == (mu_p) )
{
}
else
{
mu_LastWrite = mu_pv;
mu_ps = mu_Proc_M;
}
break;
case mu_Upg:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
case mu_PutM:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
else
{
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
mu_ps = mu_Proc_IM_D_S;
break;
case mu_GetM:
mu_ps = mu_Proc_IM_D_I;
break;
case mu_Upg:
break;
case mu_PutM:
break;
case mu_Data:
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
break;
case mu_Proc_SM_W:
bool mu__boolexpr45;
bool mu__boolexpr46;
  if (!((mu_msg.mu_src) == (mu_p))) mu__boolexpr46 = FALSE ;
  else {
  mu__boolexpr46 = ((mu_msg.mu_mtype) != (mu_Data)) ; 
}
  if (mu__boolexpr46) mu__boolexpr45 = TRUE ;
  else {
bool mu__boolexpr47;
  if (!((mu_msg.mu_src) == (mu_HomeType))) mu__boolexpr47 = FALSE ;
  else {
  mu__boolexpr47 = ((mu_msg.mu_dest) == (mu_p)) ; 
}
  mu__boolexpr45 = (mu__boolexpr47) ; 
}
if ( mu__boolexpr45 )
{
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
if ( (mu_msg.mu_src) == (mu_p) )
{
}
else
{
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
}
break;
case mu_Upg:
mu_ps = mu_Proc_M;
mu_pv = mu_msg.mu_val;
mu_LastWrite = mu_msg.mu_val;
break;
case mu_PutM:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
else
{
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
break;
case mu_GetM:
mu_pv.undefine();
mu_ps = mu_Proc_I;
mu_preissue = mu_true;
mu_BufferReissue ( mu_prebuffer );
break;
case mu_Upg:
mu_pv.undefine();
mu_ps = mu_Proc_I;
mu_preissue = mu_true;
mu_BufferReissue ( mu_prebuffer );
break;
case mu_PutM:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
case mu_Data:
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
break;
case mu_Proc_MI_WB:
bool mu__boolexpr48;
bool mu__boolexpr49;
  if (!((mu_msg.mu_src) == (mu_p))) mu__boolexpr49 = FALSE ;
  else {
  mu__boolexpr49 = ((mu_msg.mu_mtype) != (mu_Data)) ; 
}
  if (mu__boolexpr49) mu__boolexpr48 = TRUE ;
  else {
bool mu__boolexpr50;
  if (!((mu_msg.mu_src) == (mu_HomeType))) mu__boolexpr50 = FALSE ;
  else {
  mu__boolexpr50 = ((mu_msg.mu_dest) == (mu_p)) ; 
}
  mu__boolexpr48 = (mu__boolexpr50) ; 
}
if ( mu__boolexpr48 )
{
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
break;
case mu_Upg:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
case mu_PutM:
mu_ps = mu_Proc_I;
mu_ToBuffer ( mu_pwbuffer, mu_Data, (int)mu_HomeType, (int)mu_p, mu_pv );
mu_pv.undefine();
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
else
{
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
break;
case mu_GetM:
break;
case mu_Upg:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
case mu_PutM:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
case mu_Data:
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
break;
case mu_Proc_MS_WB:
bool mu__boolexpr51;
bool mu__boolexpr52;
  if (!((mu_msg.mu_src) == (mu_p))) mu__boolexpr52 = FALSE ;
  else {
  mu__boolexpr52 = ((mu_msg.mu_mtype) != (mu_Data)) ; 
}
  if (mu__boolexpr52) mu__boolexpr51 = TRUE ;
  else {
bool mu__boolexpr53;
  if (!((mu_msg.mu_src) == (mu_HomeType))) mu__boolexpr53 = FALSE ;
  else {
  mu__boolexpr53 = ((mu_msg.mu_dest) == (mu_p)) ; 
}
  mu__boolexpr51 = (mu__boolexpr53) ; 
}
if ( mu__boolexpr51 )
{
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
break;
case mu_Upg:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
case mu_PutM:
mu_ps = mu_Proc_S;
mu_ToBuffer ( mu_pwbuffer, mu_Data, (int)mu_HomeType, (int)mu_p, mu_pv );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
else
{
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
break;
case mu_GetM:
mu_ps = mu_Proc_MI_WB;
break;
case mu_Upg:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
case mu_PutM:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
case mu_Data:
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
break;
case mu_Proc_IM_D_I:
bool mu__boolexpr54;
bool mu__boolexpr55;
  if (!((mu_msg.mu_src) == (mu_p))) mu__boolexpr55 = FALSE ;
  else {
  mu__boolexpr55 = ((mu_msg.mu_mtype) != (mu_Data)) ; 
}
  if (mu__boolexpr55) mu__boolexpr54 = TRUE ;
  else {
bool mu__boolexpr56;
  if (!((mu_msg.mu_src) == (mu_HomeType))) mu__boolexpr56 = FALSE ;
  else {
  mu__boolexpr56 = ((mu_msg.mu_dest) == (mu_p)) ; 
}
  mu__boolexpr54 = (mu__boolexpr56) ; 
}
if ( mu__boolexpr54 )
{
switch ((int) mu_msg.mu_mtype) {
case mu_GetM:
break;
case mu_Data:
mu_ps = mu_Proc_MI_WB;
mu_ToBuffer ( mu_prebuffer, mu_PutM, (int)mu_HomeType, (int)mu_p, mu_1_Value_undefined_var );
mu_LastWrite = mu_msg.mu_val;
break;
case mu_Upg:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
case mu_PutM:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
else
{
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
break;
case mu_GetM:
break;
case mu_Upg:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
case mu_PutM:
break;
case mu_Data:
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
break;
case mu_Proc_IS_D_I:
bool mu__boolexpr57;
bool mu__boolexpr58;
  if (!((mu_msg.mu_src) == (mu_p))) mu__boolexpr58 = FALSE ;
  else {
  mu__boolexpr58 = ((mu_msg.mu_mtype) != (mu_Data)) ; 
}
  if (mu__boolexpr58) mu__boolexpr57 = TRUE ;
  else {
bool mu__boolexpr59;
  if (!((mu_msg.mu_src) == (mu_HomeType))) mu__boolexpr59 = FALSE ;
  else {
  mu__boolexpr59 = ((mu_msg.mu_dest) == (mu_p)) ; 
}
  mu__boolexpr57 = (mu__boolexpr59) ; 
}
if ( mu__boolexpr57 )
{
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
break;
case mu_Data:
if ( (mu_msg.mu_src) == (mu_p) )
{
}
else
{
mu_pv = mu_msg.mu_val;
mu_pv.undefine();
mu_ps = mu_Proc_I;
}
break;
case mu_Upg:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
case mu_PutM:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
else
{
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
break;
case mu_GetM:
break;
case mu_Upg:
break;
case mu_PutM:
break;
case mu_Data:
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
break;
case mu_Proc_IM_D_S:
bool mu__boolexpr60;
bool mu__boolexpr61;
  if (!((mu_msg.mu_src) == (mu_p))) mu__boolexpr61 = FALSE ;
  else {
  mu__boolexpr61 = ((mu_msg.mu_mtype) != (mu_Data)) ; 
}
  if (mu__boolexpr61) mu__boolexpr60 = TRUE ;
  else {
bool mu__boolexpr62;
  if (!((mu_msg.mu_src) == (mu_HomeType))) mu__boolexpr62 = FALSE ;
  else {
  mu__boolexpr62 = ((mu_msg.mu_dest) == (mu_p)) ; 
}
  mu__boolexpr60 = (mu__boolexpr62) ; 
}
if ( mu__boolexpr60 )
{
switch ((int) mu_msg.mu_mtype) {
case mu_GetM:
break;
case mu_Data:
mu_ps = mu_Proc_MS_WB;
mu_ToBuffer ( mu_prebuffer, mu_PutM, (int)mu_HomeType, (int)mu_p, mu_1_Value_undefined_var );
break;
case mu_Upg:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
case mu_PutM:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
else
{
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
break;
case mu_GetM:
mu_ps = mu_Proc_IM_D_I;
break;
case mu_Upg:
break;
case mu_PutM:
break;
case mu_Data:
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
}
break;
default:
mu_ErrorUnhandledState (  );
break;
}
}
}
}
}
}
};
/*** end procedure declaration ***/

void mu_HomeSend(const mu_1_MessageType& mu_mtype, const mu_1_Node& mu_dest, const mu_1_Value& mu_val)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

if (mu_mtype.isundefined())
  mu_msg.mu_mtype.undefine();
else
  mu_msg.mu_mtype = mu_mtype;
if (mu_dest.isundefined())
  mu_msg.mu_dest.undefine();
else
  mu_msg.mu_dest = mu_dest;
mu_msg.mu_src = mu_HomeType;
if (mu_val.isundefined())
  mu_msg.mu_val.undefine();
else
  mu_msg.mu_val = mu_val;
mu_home_send_msg = mu_msg;
{
for(int mu_i = 1; mu_i <= 3; mu_i++) {
mu_ProcReceive ( mu_msg, mu_i );
};
};
};
/*** end procedure declaration ***/

void mu_HomeReceive(mu_1_Message& mu_msg)
{
mu_msg_processed = mu_true;
switch ((int) mu_HomeNode.mu_state) {
case mu_H_IorS:
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
mu_HomeSend ( mu_Data, mu_msg.mu_src, mu_HomeNode.mu_val );
break;
case mu_GetM:
mu_HomeNode.mu_state = mu_H_M;
mu_HomeSend ( mu_Data, mu_msg.mu_src, mu_HomeNode.mu_val );
mu_HomeNode.mu_owner = mu_msg.mu_src;
break;
case mu_Upg:
mu_HomeNode.mu_state = mu_H_M;
mu_HomeNode.mu_owner = mu_msg.mu_src;
break;
case mu_PutM:
if ( (mu_msg.mu_src) == (mu_HomeNode.mu_owner) )
{
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
}
break;
case mu_Data:
if ( mu_HomeNode.mu_requestor.isundefined() )
{
mu_HomeNode.mu_val = mu_msg.mu_val;
}
else
{
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
}
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
break;
}
break;
case mu_H_M:
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
mu_HomeNode.mu_owner.undefine();
mu_HomeNode.mu_requestor = mu_msg.mu_src;
mu_HomeNode.mu_state = mu_H_IorS_D;
break;
case mu_GetM:
mu_HomeNode.mu_owner = mu_msg.mu_src;
mu_HomeNode.mu_requestor = mu_msg.mu_src;
mu_HomeNode.mu_state = mu_H_M_D;
break;
case mu_Upg:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
break;
case mu_PutM:
if ( (mu_msg.mu_src) == (mu_HomeNode.mu_owner) )
{
mu_HomeNode.mu_owner.undefine();
mu_HomeNode.mu_state = mu_H_IorS_D;
}
break;
case mu_Data:
if ( mu_HomeNode.mu_requestor.isundefined() )
{
mu_HomeNode.mu_state = mu_H_IorS_A;
mu_HomeNode.mu_owner.undefine();
mu_HomeNode.mu_val = mu_msg.mu_val;
}
else
{
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
}
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
break;
}
break;
case mu_H_IorS_D:
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
mu_msg_processed = mu_false;
break;
case mu_GetM:
mu_msg_processed = mu_false;
break;
case mu_Upg:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
break;
case mu_PutM:
if ( (mu_msg.mu_src) == (mu_HomeNode.mu_owner) )
{
mu_msg_processed = mu_false;
}
break;
case mu_Data:
if ( mu_HomeNode.mu_requestor.isundefined() )
{
mu_HomeNode.mu_state = mu_H_IorS;
mu_HomeNode.mu_val = mu_msg.mu_val;
}
else
{
mu_HomeNode.mu_state = mu_H_IorS_req;
mu_HomeNode.mu_val = mu_msg.mu_val;
}
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
break;
}
break;
case mu_H_IorS_A:
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
mu_HomeNode.mu_state = mu_H_IorS;
mu_HomeSend ( mu_Data, mu_msg.mu_src, mu_HomeNode.mu_val );
break;
case mu_GetM:
mu_HomeNode.mu_state = mu_H_M;
mu_HomeNode.mu_owner = mu_msg.mu_src;
mu_HomeSend ( mu_Data, mu_msg.mu_src, mu_HomeNode.mu_val );
break;
case mu_Upg:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
break;
case mu_PutM:
mu_HomeNode.mu_state = mu_H_IorS;
break;
case mu_Data:
if ( mu_HomeNode.mu_requestor.isundefined() )
{
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
}
else
{
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
}
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
break;
}
break;
case mu_H_M_D:
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
mu_msg_processed = mu_false;
break;
case mu_GetM:
mu_msg_processed = mu_false;
break;
case mu_Upg:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
break;
case mu_PutM:
if ( (mu_msg.mu_src) == (mu_HomeNode.mu_owner) )
{
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
}
break;
case mu_Data:
if ( mu_HomeNode.mu_requestor.isundefined() )
{
mu_HomeNode.mu_state = mu_H_M;
}
else
{
mu_HomeNode.mu_state = mu_H_M_req;
}
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
break;
}
break;
case mu_H_IorS_req:
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
mu_msg_processed = mu_false;
break;
case mu_GetM:
mu_msg_processed = mu_false;
break;
case mu_Upg:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
break;
case mu_PutM:
if ( (mu_msg.mu_src) == (mu_HomeNode.mu_owner) )
{
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
}
break;
case mu_Data:
if ( mu_HomeNode.mu_requestor.isundefined() )
{
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
}
else
{
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
}
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
break;
}
break;
case mu_H_M_req:
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
mu_msg_processed = mu_false;
break;
case mu_GetM:
mu_msg_processed = mu_false;
break;
case mu_Upg:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
break;
case mu_PutM:
if ( (mu_msg.mu_src) == (mu_HomeNode.mu_owner) )
{
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
}
break;
case mu_Data:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_HomeType );
break;
}
break;
}
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_HomeNode.clear();
  mu_Procs.clear();
  mu_msg_processed.clear();
  mu_LastWrite.clear();
  mu_current_channel.clear();
  mu_channelNum.clear();
  mu_temp_msg.clear();
  mu_temp_msg_home.clear();
  mu_home_send_msg.clear();
}
void world_class::undefine()
{
  mu_HomeNode.undefine();
  mu_Procs.undefine();
  mu_msg_processed.undefine();
  mu_LastWrite.undefine();
  mu_current_channel.undefine();
  mu_channelNum.undefine();
  mu_temp_msg.undefine();
  mu_temp_msg_home.undefine();
  mu_home_send_msg.undefine();
}
void world_class::reset()
{
  mu_HomeNode.reset();
  mu_Procs.reset();
  mu_msg_processed.reset();
  mu_LastWrite.reset();
  mu_current_channel.reset();
  mu_channelNum.reset();
  mu_temp_msg.reset();
  mu_temp_msg_home.reset();
  mu_home_send_msg.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_HomeNode.print();
  mu_Procs.print();
  mu_msg_processed.print();
  mu_LastWrite.print();
  mu_current_channel.print();
  mu_channelNum.print();
  mu_temp_msg.print();
  mu_temp_msg_home.print();
  mu_home_send_msg.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_HomeNode.print_statistic();
  mu_Procs.print_statistic();
  mu_msg_processed.print_statistic();
  mu_LastWrite.print_statistic();
  mu_current_channel.print_statistic();
  mu_channelNum.print_statistic();
  mu_temp_msg.print_statistic();
  mu_temp_msg_home.print_statistic();
  mu_home_send_msg.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_HomeNode.print_diff(prevstate);
    mu_Procs.print_diff(prevstate);
    mu_msg_processed.print_diff(prevstate);
    mu_LastWrite.print_diff(prevstate);
    mu_current_channel.print_diff(prevstate);
    mu_channelNum.print_diff(prevstate);
    mu_temp_msg.print_diff(prevstate);
    mu_temp_msg_home.print_diff(prevstate);
    mu_home_send_msg.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_HomeNode.to_state( newstate );
  mu_Procs.to_state( newstate );
  mu_msg_processed.to_state( newstate );
  mu_LastWrite.to_state( newstate );
  mu_current_channel.to_state( newstate );
  mu_channelNum.to_state( newstate );
  mu_temp_msg.to_state( newstate );
  mu_temp_msg_home.to_state( newstate );
  mu_home_send_msg.to_state( newstate );
}
void world_class::setstate(state *thestate)
{
}


/********************
  Rule declarations
 ********************/
/******************** RuleBase0 ********************/
class RuleBase0
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    return tsprintf("mem consume LUT");
  }
  bool Condition(unsigned r)
  {
    return (mu_current_channel) == (0);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    while (what_rule < 1 )
      {
	if ( ( TRUE  ) ) {
	      if ((mu_current_channel) == (0)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 0;
    }
  }

  void Code(unsigned r)
  {
mu_temp_msg_home = mu_Peek( mu_HomeNode.mu_PRLUT );
if ( (mu_HomeNode.mu_state) == (mu_H_IorS_req) )
{
mu_HomeSend ( mu_Data, mu_HomeNode.mu_requestor, mu_HomeNode.mu_val );
mu_HomeNode.mu_requestor.undefine();
mu_HomeNode.mu_state = mu_H_IorS;
}
else
{
if ( (mu_HomeNode.mu_state) == (mu_H_M_req) )
{
mu_HomeSend ( mu_Data, mu_HomeNode.mu_requestor, mu_HomeNode.mu_val );
mu_HomeNode.mu_requestor.undefine();
mu_HomeNode.mu_state = mu_H_M;
}
else
{
if ( !(mu_temp_msg_home.mu_mtype.isundefined()) )
{
mu_HomeReceive ( mu_temp_msg_home );
if ( mu_msg_processed )
{
mu_temp_msg_home = mu_Dequeue( mu_HomeNode.mu_PRLUT );
}
}
}
}
mu_ABSelect ( mu_current_channel );
  };

};
/******************** RuleBase1 ********************/
class RuleBase1
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("proc send to bus, n:%s", mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
    return (mu_current_channel) == (mu_p.mu_channel);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 4 )
      {
	if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
	      if ((mu_current_channel) == (mu_p.mu_channel)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 1;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
if ( !(mu_isBufferEmpty( mu_p.mu_PWB )) )
{
mu_temp_msg = mu_Dequeue( mu_p.mu_PWB );
if ( !(mu_temp_msg.mu_mtype.isundefined()) )
{
{
for(int mu_i = 1; mu_i <= 3; mu_i++) {
mu_ProcReceive ( mu_temp_msg, mu_i );
};
};
mu_HomeReceive ( mu_temp_msg );
}
}
else
{
bool mu__boolexpr63;
  if (!(!(mu_isBufferEmpty( mu_p.mu_PR )))) mu__boolexpr63 = FALSE ;
  else {
  mu__boolexpr63 = (mu_isBufferEmpty( mu_p.mu_PWB )) ; 
}
if ( mu__boolexpr63 )
{
if ( !(mu_checkLUT( mu_HomeNode.mu_PRLUT, mu_n )) )
{
mu_temp_msg = mu_Dequeue( mu_p.mu_PR );
if ( !(mu_temp_msg.mu_mtype.isundefined()) )
{
{
for(int mu_i = 1; mu_i <= 3; mu_i++) {
mu_ProcReceive ( mu_temp_msg, mu_i );
};
};
mu_Enqueue ( mu_HomeNode.mu_PRLUT, mu_temp_msg );
}
}
}
}
mu_ABSelect ( mu_current_channel );
  };

};
/******************** RuleBase2 ********************/
class RuleBase2
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 2) + 4);
    r = r / 2;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("@ In S upg, v:%s, n:%s", mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 2) + 4);
    r = r / 2;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
bool mu__boolexpr64;
  if (!((mu_p.mu_state) == (mu_Proc_S))) mu__boolexpr64 = FALSE ;
  else {
  mu__boolexpr64 = (!(mu_checkLUT( mu_HomeNode.mu_PRLUT, mu_n ))) ; 
}
    return mu__boolexpr64;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 4;
    static mu_1_Value mu_v;
    mu_v.value((r % 2) + 4);
    r = r / 2;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 10 )
      {
	if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
bool mu__boolexpr65;
  if (!((mu_p.mu_state) == (mu_Proc_S))) mu__boolexpr65 = FALSE ;
  else {
  mu__boolexpr65 = (!(mu_checkLUT( mu_HomeNode.mu_PRLUT, mu_n ))) ; 
}
	      if (mu__boolexpr65) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 2;
	}
	else
	  what_rule += 2;
    r = what_rule - 4;
    mu_v.value((r % 2) + 4);
    r = r / 2;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 2) + 4);
    r = r / 2;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_p.mu_canUPG = mu_true;
{
for(int mu_i = 1; mu_i <= 3; mu_i++) {
bool mu__boolexpr66;
bool mu__boolexpr67;
  if ((mu_Procs[mu_i].mu_state) == (mu_Proc_IM_D)) mu__boolexpr67 = TRUE ;
  else {
  mu__boolexpr67 = ((mu_Procs[mu_i].mu_state) == (mu_Proc_IM_D_I)) ; 
}
  if (mu__boolexpr67) mu__boolexpr66 = TRUE ;
  else {
  mu__boolexpr66 = ((mu_Procs[mu_i].mu_state) == (mu_Proc_IM_D_S)) ; 
}
if ( mu__boolexpr66 )
{
mu_p.mu_canUPG = mu_false;
}
};
};
if ( mu_p.mu_canUPG )
{
mu_ToBuffer ( mu_p.mu_PR, mu_Upg, (int)mu_HomeType, (int)mu_n, mu_v );
mu_p.mu_state = mu_Proc_SM_W;
mu_p.mu_canUPG = mu_false;
}
  };

};
/******************** RuleBase3 ********************/
class RuleBase3
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("@ M evict, n:%s", mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
bool mu__boolexpr68;
  if (!((mu_p.mu_state) == (mu_Proc_M))) mu__boolexpr68 = FALSE ;
  else {
  mu__boolexpr68 = (!(mu_checkLUT( mu_HomeNode.mu_PRLUT, mu_n ))) ; 
}
    return mu__boolexpr68;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 10;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 13 )
      {
	if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
bool mu__boolexpr69;
  if (!((mu_p.mu_state) == (mu_Proc_M))) mu__boolexpr69 = FALSE ;
  else {
  mu__boolexpr69 = (!(mu_checkLUT( mu_HomeNode.mu_PRLUT, mu_n ))) ; 
}
	      if (mu__boolexpr69) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 10;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_ToBuffer ( mu_p.mu_PR, mu_PutM, (int)mu_HomeType, (int)mu_n, mu_p.mu_val );
mu_p.mu_state = mu_Proc_MI_WB;
  };

};
/******************** RuleBase4 ********************/
class RuleBase4
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("@ P evict, n:%s", mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
bool mu__boolexpr70;
  if ((mu_p.mu_state) == (mu_Proc_S)) mu__boolexpr70 = TRUE ;
  else {
  mu__boolexpr70 = ((mu_p.mu_state) == (mu_Proc_MS_WB)) ; 
}
    return mu__boolexpr70;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 13;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 16 )
      {
	if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
bool mu__boolexpr71;
  if ((mu_p.mu_state) == (mu_Proc_S)) mu__boolexpr71 = TRUE ;
  else {
  mu__boolexpr71 = ((mu_p.mu_state) == (mu_Proc_MS_WB)) ; 
}
	      if (mu__boolexpr71) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 13;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
switch ((int) mu_p.mu_state) {
case mu_Proc_S:
mu_p.mu_val.undefine();
mu_p.mu_state = mu_Proc_I;
break;
case mu_Proc_M:
mu_ToBuffer ( mu_p.mu_PR, mu_PutM, (int)mu_HomeType, (int)mu_n, mu_p.mu_val );
mu_p.mu_state = mu_Proc_MI_WB;
break;
case mu_Proc_MS_WB:
mu_p.mu_state = mu_Proc_MI_WB;
break;
}
  };

};
/******************** RuleBase5 ********************/
class RuleBase5
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("@ P load, n:%s", mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
bool mu__boolexpr72;
  if (!((mu_p.mu_state) == (mu_Proc_I))) mu__boolexpr72 = FALSE ;
  else {
  mu__boolexpr72 = (!(mu_p.mu_reiss)) ; 
}
    return mu__boolexpr72;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 16;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 19 )
      {
	if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
bool mu__boolexpr73;
  if (!((mu_p.mu_state) == (mu_Proc_I))) mu__boolexpr73 = FALSE ;
  else {
  mu__boolexpr73 = (!(mu_p.mu_reiss)) ; 
}
	      if (mu__boolexpr73) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 16;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
switch ((int) mu_p.mu_state) {
case mu_Proc_I:
mu_ToBuffer ( mu_p.mu_PR, mu_GetS, (int)mu_HomeType, (int)mu_n, mu_1_Value_undefined_var );
mu_p.mu_state = mu_Proc_IS_D;
break;
}
  };

};
/******************** RuleBase6 ********************/
class RuleBase6
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 2) + 4);
    r = r / 2;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("reissue, v:%s, n:%s", mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 2) + 4);
    r = r / 2;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
bool mu__boolexpr74;
  if (!((mu_p.mu_state) == (mu_Proc_I))) mu__boolexpr74 = FALSE ;
  else {
  mu__boolexpr74 = (mu_p.mu_reiss) ; 
}
    return mu__boolexpr74;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 19;
    static mu_1_Value mu_v;
    mu_v.value((r % 2) + 4);
    r = r / 2;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 25 )
      {
	if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
bool mu__boolexpr75;
  if (!((mu_p.mu_state) == (mu_Proc_I))) mu__boolexpr75 = FALSE ;
  else {
  mu__boolexpr75 = (mu_p.mu_reiss) ; 
}
	      if (mu__boolexpr75) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 2;
	}
	else
	  what_rule += 2;
    r = what_rule - 19;
    mu_v.value((r % 2) + 4);
    r = r / 2;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 2) + 4);
    r = r / 2;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_ToBuffer ( mu_p.mu_PR, mu_GetM, (int)mu_HomeType, (int)mu_n, mu_1_Value_undefined_var );
mu_p.mu_state = mu_Proc_IM_D;
mu_p.mu_reiss = mu_false;
mu_p.mu_val = mu_v;
  };

};
/******************** RuleBase7 ********************/
class RuleBase7
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 2) + 4);
    r = r / 2;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("@ P store, v:%s, n:%s", mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 2) + 4);
    r = r / 2;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
bool mu__boolexpr76;
  if (!((mu_p.mu_state) == (mu_Proc_I))) mu__boolexpr76 = FALSE ;
  else {
  mu__boolexpr76 = (!(mu_p.mu_reiss)) ; 
}
    return mu__boolexpr76;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 25;
    static mu_1_Value mu_v;
    mu_v.value((r % 2) + 4);
    r = r / 2;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 31 )
      {
	if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
bool mu__boolexpr77;
  if (!((mu_p.mu_state) == (mu_Proc_I))) mu__boolexpr77 = FALSE ;
  else {
  mu__boolexpr77 = (!(mu_p.mu_reiss)) ; 
}
	      if (mu__boolexpr77) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 2;
	}
	else
	  what_rule += 2;
    r = what_rule - 25;
    mu_v.value((r % 2) + 4);
    r = r / 2;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 2) + 4);
    r = r / 2;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
switch ((int) mu_p.mu_state) {
case mu_Proc_I:
mu_ToBuffer ( mu_p.mu_PR, mu_GetM, (int)mu_HomeType, (int)mu_n, mu_1_Value_undefined_var );
mu_p.mu_state = mu_Proc_IM_D;
mu_p.mu_val = mu_v;
break;
}
  };

};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
  RuleBase2 R2;
  RuleBase3 R3;
  RuleBase4 R4;
  RuleBase5 R5;
  RuleBase6 R6;
  RuleBase7 R7;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<1)
    { R0.NextRule(what_rule);
      if (what_rule<1) return; }
  if (what_rule>=1 && what_rule<4)
    { R1.NextRule(what_rule);
      if (what_rule<4) return; }
  if (what_rule>=4 && what_rule<10)
    { R2.NextRule(what_rule);
      if (what_rule<10) return; }
  if (what_rule>=10 && what_rule<13)
    { R3.NextRule(what_rule);
      if (what_rule<13) return; }
  if (what_rule>=13 && what_rule<16)
    { R4.NextRule(what_rule);
      if (what_rule<16) return; }
  if (what_rule>=16 && what_rule<19)
    { R5.NextRule(what_rule);
      if (what_rule<19) return; }
  if (what_rule>=19 && what_rule<25)
    { R6.NextRule(what_rule);
      if (what_rule<25) return; }
  if (what_rule>=25 && what_rule<31)
    { R7.NextRule(what_rule);
      if (what_rule<31) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=0) return R0.Condition(r-0);
  if (r>=1 && r<=3) return R1.Condition(r-1);
  if (r>=4 && r<=9) return R2.Condition(r-4);
  if (r>=10 && r<=12) return R3.Condition(r-10);
  if (r>=13 && r<=15) return R4.Condition(r-13);
  if (r>=16 && r<=18) return R5.Condition(r-16);
  if (r>=19 && r<=24) return R6.Condition(r-19);
  if (r>=25 && r<=30) return R7.Condition(r-25);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
return 0;}
void Code(unsigned r)
{
  if (r<=0) { R0.Code(r-0); return; } 
  if (r>=1 && r<=3) { R1.Code(r-1); return; } 
  if (r>=4 && r<=9) { R2.Code(r-4); return; } 
  if (r>=10 && r<=12) { R3.Code(r-10); return; } 
  if (r>=13 && r<=15) { R4.Code(r-13); return; } 
  if (r>=16 && r<=18) { R5.Code(r-16); return; } 
  if (r>=19 && r<=24) { R6.Code(r-19); return; } 
  if (r>=25 && r<=30) { R7.Code(r-25); return; } 
}
int Priority(unsigned short r)
{
  if (r<=0) { return R0.Priority(); } 
  if (r>=1 && r<=3) { return R1.Priority(); } 
  if (r>=4 && r<=9) { return R2.Priority(); } 
  if (r>=10 && r<=12) { return R3.Priority(); } 
  if (r>=13 && r<=15) { return R4.Priority(); } 
  if (r>=16 && r<=18) { return R5.Priority(); } 
  if (r>=19 && r<=24) { return R6.Priority(); } 
  if (r>=25 && r<=30) { return R7.Priority(); } 
return 0;}
char * Name(unsigned r)
{
  if (r<=0) return R0.Name(r-0);
  if (r>=1 && r<=3) return R1.Name(r-1);
  if (r>=4 && r<=9) return R2.Name(r-4);
  if (r>=10 && r<=12) return R3.Name(r-10);
  if (r>=13 && r<=15) return R4.Name(r-13);
  if (r>=16 && r<=18) return R5.Name(r-16);
  if (r>=19 && r<=24) return R6.Name(r-19);
  if (r>=25 && r<=30) return R7.Name(r-25);
  return NULL;
}
};
const unsigned numrules = 31;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 31


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("Startstate 0");
  }
  void Code(unsigned short r)
  {
{
for(int mu_v = 4; mu_v <= 5; mu_v++) {
mu_HomeNode.mu_state = mu_H_IorS;
mu_HomeNode.mu_owner.undefine();
mu_HomeNode.mu_requestor.undefine();
mu_HomeNode.mu_val = mu_v;
};
};
mu_HomeNode.mu_channel = 0;
mu_HomeNode.mu_PRLUT.mu_head = 0;
mu_HomeNode.mu_PRLUT.mu_tail = 0;
mu_LastWrite = mu_HomeNode.mu_val;
mu_current_channel = 0;
mu_channelNum = 1;
{
for(int mu_i = 1; mu_i <= 3; mu_i++) {
mu_Procs[mu_i].mu_state = mu_Proc_I;
mu_Procs[mu_i].mu_val.undefine();
if (mu_channelNum.isundefined())
  mu_Procs[mu_i].mu_channel.undefine();
else
  mu_Procs[mu_i].mu_channel = mu_channelNum;
mu_Procs[mu_i].mu_PR.mu_head = 0;
mu_Procs[mu_i].mu_PR.mu_tail = 0;
mu_Procs[mu_i].mu_PWB.mu_head = 0;
mu_Procs[mu_i].mu_PWB.mu_tail = 0;
mu_Procs[mu_i].mu_reiss = mu_false;
mu_Procs[mu_i].mu_canUPG = mu_false;
mu_channelNum = (mu_channelNum) + (1);
};
};
  };

};
class StartStateGenerator
{
  StartStateBase0 S0;
public:
void Code(unsigned short r)
{
  if (r<=0) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=0) return S0.Name(r-0);
  return NULL;
}
};
const rulerec startstates[] = {
{ NULL, NULL, NULL, FALSE},
};
unsigned short StartStateManager::numstartstates = 1;

/********************
  Invariant records
 ********************/
int mu__invariant_78() // Invariant "values in shared state match memory"
{
bool mu__quant79; 
mu__quant79 = TRUE;
{
for(int mu_n = 1; mu_n <= 3; mu_n++) {
bool mu__boolexpr80;
bool mu__boolexpr81;
  if (!((mu_HomeNode.mu_state) == (mu_H_IorS))) mu__boolexpr81 = FALSE ;
  else {
  mu__boolexpr81 = ((mu_Procs[mu_n].mu_state) == (mu_Proc_S)) ; 
}
  if (!(mu__boolexpr81)) mu__boolexpr80 = TRUE ;
  else {
  mu__boolexpr80 = ((mu_HomeNode.mu_val) == (mu_Procs[mu_n].mu_val)) ; 
}
if ( !(mu__boolexpr80) )
  { mu__quant79 = FALSE; break; }
};
};
return mu__quant79;
};

bool mu__condition_82() // Condition for Rule "values in shared state match memory"
{
  return mu__invariant_78( );
}

/**** end rule declaration ****/

int mu__invariant_83() // Invariant "value is undefined while invalid"
{
bool mu__quant84; 
mu__quant84 = TRUE;
{
for(int mu_n = 1; mu_n <= 3; mu_n++) {
bool mu__boolexpr85;
  if (!((mu_Procs[mu_n].mu_state) == (mu_Proc_I))) mu__boolexpr85 = TRUE ;
  else {
  mu__boolexpr85 = (mu_Procs[mu_n].mu_val.isundefined()) ; 
}
if ( !(mu__boolexpr85) )
  { mu__quant84 = FALSE; break; }
};
};
return mu__quant84;
};

bool mu__condition_86() // Condition for Rule "value is undefined while invalid"
{
  return mu__invariant_83( );
}

/**** end rule declaration ****/

int mu__invariant_87() // Invariant "values in m state match last write"
{
bool mu__quant88; 
mu__quant88 = TRUE;
{
for(int mu_n = 1; mu_n <= 3; mu_n++) {
bool mu__boolexpr89;
  if (!((mu_Procs[mu_n].mu_state) == (mu_Proc_M))) mu__boolexpr89 = TRUE ;
  else {
  mu__boolexpr89 = ((mu_Procs[mu_n].mu_val) == (mu_LastWrite)) ; 
}
if ( !(mu__boolexpr89) )
  { mu__quant88 = FALSE; break; }
};
};
return mu__quant88;
};

bool mu__condition_90() // Condition for Rule "values in m state match last write"
{
  return mu__invariant_87( );
}

/**** end rule declaration ****/

int mu__invariant_91() // Invariant "processor in Modified state,  no Sharers"
{
bool mu__quant92; 
mu__quant92 = TRUE;
{
for(int mu_n = 1; mu_n <= 3; mu_n++) {
bool mu__quant93; 
mu__quant93 = TRUE;
{
for(int mu_m = 1; mu_m <= 3; mu_m++) {
bool mu__boolexpr94;
bool mu__boolexpr95;
  if (!((mu_Procs[mu_n].mu_state) == (mu_Proc_M))) mu__boolexpr95 = FALSE ;
  else {
  mu__boolexpr95 = ((mu_n) != (mu_m)) ; 
}
  if (!(mu__boolexpr95)) mu__boolexpr94 = TRUE ;
  else {
bool mu__boolexpr96;
  if (!((mu_Procs[mu_m].mu_state) != (mu_Proc_S))) mu__boolexpr96 = FALSE ;
  else {
  mu__boolexpr96 = ((mu_Procs[mu_m].mu_state) != (mu_Proc_M)) ; 
}
  mu__boolexpr94 = (mu__boolexpr96) ; 
}
if ( !(mu__boolexpr94) )
  { mu__quant93 = FALSE; break; }
};
};
if ( !(mu__quant93) )
  { mu__quant92 = FALSE; break; }
};
};
return mu__quant92;
};

bool mu__condition_97() // Condition for Rule "processor in Modified state,  no Sharers"
{
  return mu__invariant_91( );
}

/**** end rule declaration ****/

int mu__invariant_98() // Invariant "Invalid implies empty owner"
{
bool mu__boolexpr99;
  if (!((mu_HomeNode.mu_state) == (mu_H_IorS))) mu__boolexpr99 = TRUE ;
  else {
  mu__boolexpr99 = (mu_HomeNode.mu_owner.isundefined()) ; 
}
return mu__boolexpr99;
};

bool mu__condition_100() // Condition for Rule "Invalid implies empty owner"
{
  return mu__invariant_98( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"Invalid implies empty owner", &mu__condition_100, NULL, },
{"processor in Modified state,  no Sharers", &mu__condition_97, NULL, },
{"values in m state match last write", &mu__condition_90, NULL, },
{"value is undefined while invalid", &mu__condition_86, NULL, },
{"values in shared state match memory", &mu__condition_82, NULL, },
};
const unsigned short numinvariants = 5;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
channelNum:NoScalarset
msg_processed:NoScalarset
current_channel:NoScalarset
temp_msg_home:ScalarsetVariable
LastWrite:ScalarsetVariable
HomeNode:ScalarsetVariable
temp_msg:ScalarsetVariable
home_send_msg:ScalarsetVariable
Procs:ScalarsetArrayOfScalarset
*/

/********************
Code for symmetry
 ********************/

/********************
 Permutation Set Class
 ********************/
class PermSet
{
public:
  // book keeping
  enum PresentationType {Simple, Explicit};
  PresentationType Presentation;

  void ResetToSimple();
  void ResetToExplicit();
  void SimpleToExplicit();
  void SimpleToOne();
  bool NextPermutation();

  void Print_in_size()
  { int ret=0; for (int i=0; i<count; i++) if (in[i]) ret++; cout << "in_size:" << ret << "\n"; }


  /********************
   Simple and efficient representation
   ********************/
  int class_mu_1_Value[2];
  int undefined_class_mu_1_Value;// has the highest class number

  void Print_class_mu_1_Value();
  bool OnlyOneRemain_mu_1_Value;
  bool MTO_class_mu_1_Value()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_Value)
      return FALSE;
    for (i=0; i<2; i++)
      for (j=0; j<2; j++)
        if (i!=j && class_mu_1_Value[i]== class_mu_1_Value[j])
	    return TRUE;
    OnlyOneRemain_mu_1_Value = TRUE;
    return FALSE;
  }
  int class_mu_1_Proc[3];
  int undefined_class_mu_1_Proc;// has the highest class number

  void Print_class_mu_1_Proc();
  bool OnlyOneRemain_mu_1_Proc;
  bool MTO_class_mu_1_Proc()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_Proc)
      return FALSE;
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
        if (i!=j && class_mu_1_Proc[i]== class_mu_1_Proc[j])
	    return TRUE;
    OnlyOneRemain_mu_1_Proc = TRUE;
    return FALSE;
  }
  bool AlreadyOnlyOneRemain;
  bool MoreThanOneRemain();


  /********************
   Explicit representation
  ********************/
  unsigned long size;
  unsigned long count;
  // in will be of product of factorial sizes for fast canonicalize
  // in will be of size 1 for reduced local memory canonicalize
  bool * in;

  // auxiliary for explicit representation

  // in/perm/revperm will be of factorial size for fast canonicalize
  // they will be of size 1 for reduced local memory canonicalize
  // second range will be size of the scalarset
  int * in_mu_1_Value;
  typedef int arr_mu_1_Value[2];
  arr_mu_1_Value * perm_mu_1_Value;
  arr_mu_1_Value * revperm_mu_1_Value;

  int size_mu_1_Value[2];
  bool reversed_sorted_mu_1_Value(int start, int end);
  void reverse_reversed_mu_1_Value(int start, int end);

  int * in_mu_1_Proc;
  typedef int arr_mu_1_Proc[3];
  arr_mu_1_Proc * perm_mu_1_Proc;
  arr_mu_1_Proc * revperm_mu_1_Proc;

  int size_mu_1_Proc[3];
  bool reversed_sorted_mu_1_Proc(int start, int end);
  void reverse_reversed_mu_1_Proc(int start, int end);

  // procedure for explicit representation
  bool ok0(mu_1_Value* perm, int size, mu_1_Value k);
  void GenPerm0(mu_1_Value* perm, int size, unsigned long& index);

  bool ok1(mu_1_Proc* perm, int size, mu_1_Proc k);
  void GenPerm1(mu_1_Proc* perm, int size, unsigned long& index);

  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
void PermSet::Print_class_mu_1_Value()
{
  cout << "class_mu_1_Value:\t";
  for (int i=0; i<2; i++)
    cout << class_mu_1_Value[i];
  cout << " " << undefined_class_mu_1_Value << "\n";
}
void PermSet::Print_class_mu_1_Proc()
{
  cout << "class_mu_1_Proc:\t";
  for (int i=0; i<3; i++)
    cout << class_mu_1_Proc[i];
  cout << " " << undefined_class_mu_1_Proc << "\n";
}
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
    for (i=0; i<2; i++)
      for (j=0; j<2; j++)
        if (i!=j && class_mu_1_Value[i]== class_mu_1_Value[j])
	    return TRUE;
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
        if (i!=j && class_mu_1_Proc[i]== class_mu_1_Proc[j])
	    return TRUE;
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
     || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
    mu_1_Value Perm0[2];
    mu_1_Proc Perm1[3];

  /********************
   declaration of class variables
  ********************/
  in = new bool[12];
 in_mu_1_Value = new int[12];
 perm_mu_1_Value = new arr_mu_1_Value[2];
 revperm_mu_1_Value = new arr_mu_1_Value[2];
 in_mu_1_Proc = new int[12];
 perm_mu_1_Proc = new arr_mu_1_Proc[6];
 revperm_mu_1_Proc = new arr_mu_1_Proc[6];

    // Set perm and revperm
    count = 0;
    for (i=4; i<=5; i++)
      {
        Perm0[0].value(i);
        GenPerm0(Perm0, 1, count);
      }
    if (count!=2)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<2; i++)
      for (j=4; j<=5; j++)
        for (k=4; k<=5; k++)
          if (revperm_mu_1_Value[i][k-4]==j)   // k - base 
            perm_mu_1_Value[i][j-4]=k; // j - base 
    count = 0;
    for (i=1; i<=3; i++)
      {
        Perm1[0].value(i);
        GenPerm1(Perm1, 1, count);
      }
    if (count!=6)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<6; i++)
      for (j=1; j<=3; j++)
        for (k=1; k<=3; k++)
          if (revperm_mu_1_Proc[i][k-1]==j)   // k - base 
            perm_mu_1_Proc[i][j-1]=k; // j - base 

    // setting up combination of permutations
    // for different scalarset
    int carry;
    int i_mu_1_Value = 0;
    int i_mu_1_Proc = 0;
    size = 12;
    count = 12;
    for (i=0; i<12; i++)
      {
        carry = 1;
        in[i]= TRUE;
      in_mu_1_Value[i] = i_mu_1_Value;
      i_mu_1_Value += carry;
      if (i_mu_1_Value >= 2) { i_mu_1_Value = 0; carry = 1; } 
      else { carry = 0; } 
      in_mu_1_Proc[i] = i_mu_1_Proc;
      i_mu_1_Proc += carry;
      if (i_mu_1_Proc >= 6) { i_mu_1_Proc = 0; carry = 1; } 
      else { carry = 0; } 
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
 in_mu_1_Value = new int[1];
 perm_mu_1_Value = new arr_mu_1_Value[1];
 revperm_mu_1_Value = new arr_mu_1_Value[1];
 in_mu_1_Proc = new int[1];
 perm_mu_1_Proc = new arr_mu_1_Proc[1];
 revperm_mu_1_Proc = new arr_mu_1_Proc[1];
  in[0] = TRUE;
    in_mu_1_Value[0] = 0;
    in_mu_1_Proc[0] = 0;
  }
}
void PermSet::ResetToSimple()
{
  int i;
  for (i=0; i<2; i++)
    class_mu_1_Value[i]=0;
  undefined_class_mu_1_Value=0;
  OnlyOneRemain_mu_1_Value = FALSE;
  for (i=0; i<3; i++)
    class_mu_1_Proc[i]=0;
  undefined_class_mu_1_Proc=0;
  OnlyOneRemain_mu_1_Proc = FALSE;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<12; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;
  int start_mu_1_Value[2];
  int size_mu_1_Value[2];
  bool should_be_in_mu_1_Value[2];
  int start_mu_1_Proc[3];
  int size_mu_1_Proc[3];
  bool should_be_in_mu_1_Proc[6];

  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Value; j++) // class number
    {
      class_size = 0;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Value[k]==j)
	  class_size++;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Value[k]==j)
	  {
	    size_mu_1_Value[k] = class_size;
	    start_mu_1_Value[k] = start;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Proc; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  {
	    size_mu_1_Proc[k] = class_size;
	    start_mu_1_Proc[k] = start;
	  }
      start+=class_size;
    }

  // To be In or not to be
  for (i=0; i<2; i++) // set up
    should_be_in_mu_1_Value[i] = TRUE;
  for (i=0; i<2; i++) // to be in or not to be
    for (k=0; k<2; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_Value[i][k]-4 >=start_mu_1_Value[k] 
	     && perm_mu_1_Value[i][k]-4 < start_mu_1_Value[k] + size_mu_1_Value[k]) )
  	    {
	      should_be_in_mu_1_Value[i] = FALSE;
	      break;
	    }
  for (i=0; i<6; i++) // set up
    should_be_in_mu_1_Proc[i] = TRUE;
  for (i=0; i<6; i++) // to be in or not to be
    for (k=0; k<3; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_Proc[i][k]-1 >=start_mu_1_Proc[k] 
	     && perm_mu_1_Proc[i][k]-1 < start_mu_1_Proc[k] + size_mu_1_Proc[k]) )
  	    {
	      should_be_in_mu_1_Proc[i] = FALSE;
	      break;
	    }

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<12; i++)
    {
      in[i] = TRUE;
      if (in[i] && !should_be_in_mu_1_Value[in_mu_1_Value[i]]) in[i] = FALSE;
      if (in[i] && !should_be_in_mu_1_Proc[in_mu_1_Proc[i]]) in[i] = FALSE;
    }
  Presentation = Explicit;
  if (args->test_parameter1.value==0) Print_in_size();
}
void PermSet::SimpleToOne()
{
  int i,j,k;
  int class_size;
  int start;


  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Value; j++) // class number
    {
      class_size = 0;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Value[k]==j)
	  class_size++;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Value[k]==j)
	  {
	    size_mu_1_Value[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Proc; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  {
	    size_mu_1_Proc[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Value; j++) // class number
    {
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_Value[k]==j)
	      revperm_mu_1_Value[0][start++] = k+4;
    }
  for (j=0; j<2; j++)
    for (k=0; k<2; k++)
      if (revperm_mu_1_Value[0][k]==j+4)
        perm_mu_1_Value[0][j]=k+4;
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Proc; j++) // class number
    {
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_Proc[k]==j)
	      revperm_mu_1_Proc[0][start++] = k+1;
    }
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_Proc[0][k]==j+1)
        perm_mu_1_Proc[0][j]=k+1;
  Presentation = Explicit;
}
bool PermSet::ok0(mu_1_Value* Perm, int size, mu_1_Value k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm0(mu_1_Value* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=2)
    {
      for (i=4; i<=5; i++)
        if(ok0(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm0(Perm, size+1, count);
          }
    }
  else
    {
      for (i=4; i<=5; i++)
        revperm_mu_1_Value[count][i-4]=Perm[i-4].value();// i - base
      count++;
    }
}
bool PermSet::ok1(mu_1_Proc* Perm, int size, mu_1_Proc k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm1(mu_1_Proc* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=3)
    {
      for (i=1; i<=3; i++)
        if(ok1(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm1(Perm, size+1, count);
          }
    }
  else
    {
      for (i=1; i<=3; i++)
        revperm_mu_1_Proc[count][i-1]=Perm[i-1].value();// i - base
      count++;
    }
}
bool PermSet::reversed_sorted_mu_1_Value(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_Value[0][i]<revperm_mu_1_Value[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_Value(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_Value[0][j];
      revperm_mu_1_Value[0][j] = revperm_mu_1_Value[0][i];
      revperm_mu_1_Value[0][i] = temp;
    }
}
bool PermSet::reversed_sorted_mu_1_Proc(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_Proc[0][i]<revperm_mu_1_Proc[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_Proc(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_Proc[0][j];
      revperm_mu_1_Proc[0][j] = revperm_mu_1_Proc[0][i];
      revperm_mu_1_Proc[0][i] = temp;
    }
}
bool PermSet::NextPermutation()
{
  bool nexted = FALSE;
  int start, end; 
  int class_size;
  int temp;
  int j,k;

  // algorithm
  // for each class
  //   if forall in the same class reverse_sorted, 
  //     { sort again; goto next class }
  //   else
  //     {
  //       nexted = TRUE;
  //       for (j from l to r)
  // 	       if (for all j+ are reversed sorted)
  // 	         {
  // 	           swap j, j+1
  // 	           sort all j+ again
  // 	           break;
  // 	         }
  //     }
  for (start = 0; start < 2; )
    {
      end = start-1+size_mu_1_Value[revperm_mu_1_Value[0][start]-4];
      if (reversed_sorted_mu_1_Value(start,end))
	       {
	  reverse_reversed_mu_1_Value(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_Value(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_Value[0][j]<revperm_mu_1_Value[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_Value[0][j];
			  revperm_mu_1_Value[0][j] = revperm_mu_1_Value[0][k];
			  revperm_mu_1_Value[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_Value(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
if (!nexted) {
  for (start = 0; start < 3; )
    {
      end = start-1+size_mu_1_Proc[revperm_mu_1_Proc[0][start]-1];
      if (reversed_sorted_mu_1_Proc(start,end))
	       {
	  reverse_reversed_mu_1_Proc(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_Proc(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_Proc[0][j]<revperm_mu_1_Proc[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_Proc[0][j];
			  revperm_mu_1_Proc[0][j] = revperm_mu_1_Proc[0][k];
			  revperm_mu_1_Proc[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_Proc(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
}
if (!nexted) return FALSE;
  for (j=0; j<2; j++)
    for (k=0; k<2; k++)
      if (revperm_mu_1_Value[0][k]==j+4)   // k - base 
	perm_mu_1_Value[0][j]=k+4; // j - base 
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_Proc[0][k]==j+1)   // k - base 
	perm_mu_1_Proc[0][j]=k+1; // j - base 
  return TRUE;
}

/********************
 Symmetry Class
 ********************/
class SymmetryClass
{
  PermSet Perm;
  bool BestInitialized;
  state BestPermutedState;

  // utilities
  void SetBestResult(int i, state* temp);
  void ResetBestResult() {BestInitialized = FALSE;};

public:
  // initializer
  SymmetryClass() : Perm(), BestInitialized(FALSE) {};
  ~SymmetryClass() {};

  void Normalize(state* s);

  void Exhaustive_Fast_Canonicalize(state *s);
  void Heuristic_Fast_Canonicalize(state *s);
  void Heuristic_Small_Mem_Canonicalize(state *s);
  void Heuristic_Fast_Normalize(state *s);

  void MultisetSort(state* s);
};


/********************
 Symmetry Class Members
 ********************/
void SymmetryClass::MultisetSort(state* s)
{
        mu_channelNum.MultisetSort();
        mu_msg_processed.MultisetSort();
        mu_current_channel.MultisetSort();
        mu_temp_msg_home.MultisetSort();
        mu_LastWrite.MultisetSort();
        mu_HomeNode.MultisetSort();
        mu_temp_msg.MultisetSort();
        mu_home_send_msg.MultisetSort();
        mu_Procs.MultisetSort();
}
void SymmetryClass::Normalize(state* s)
{
  switch (args->sym_alg.mode) {
  case argsym_alg::Exhaustive_Fast_Canonicalize:
    Exhaustive_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Canonicalize:
    Heuristic_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Small_Mem_Canonicalize:
    Heuristic_Small_Mem_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Normalize:
    Heuristic_Fast_Normalize(s);
    break;
  default:
    Heuristic_Fast_Canonicalize(s);
  }
}

/********************
 Permute and Canonicalize function for different types
 ********************/
void mu_1_Proc::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_Proc[Perm.in_mu_1_Proc[i]][value()-1]); // value - base
};
void mu_1_Proc::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Proc[value()-1]==Perm.undefined_class_mu_1_Proc) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<3; i++)
          if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-1)
            Perm.class_mu_1_Proc[i]++;
        value(1 + Perm.undefined_class_mu_1_Proc++);
      }
    else 
      {
        value(Perm.class_mu_1_Proc[value()-1]+1);
      }
}
void mu_1_Proc::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Proc::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Proc[value()-1]==Perm.undefined_class_mu_1_Proc) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<3; i++)
          if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-1)
            Perm.class_mu_1_Proc[i]++;
        Perm.undefined_class_mu_1_Proc++;
      }
}
void mu_1_Proc::ArrayLimit(PermSet& Perm) {}
void mu_1_Proc::Limit(PermSet& Perm) {}
void mu_1_Proc::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_Value::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_Value[Perm.in_mu_1_Value[i]][value()-4]); // value - base
};
void mu_1_Value::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Value[value()-4]==Perm.undefined_class_mu_1_Value) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<2; i++)
          if (Perm.class_mu_1_Value[i] == Perm.undefined_class_mu_1_Value && i!=value()-4)
            Perm.class_mu_1_Value[i]++;
        value(4 + Perm.undefined_class_mu_1_Value++);
      }
    else 
      {
        value(Perm.class_mu_1_Value[value()-4]+4);
      }
}
void mu_1_Value::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Value::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Value[value()-4]==Perm.undefined_class_mu_1_Value) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<2; i++)
          if (Perm.class_mu_1_Value[i] == Perm.undefined_class_mu_1_Value && i!=value()-4)
            Perm.class_mu_1_Value[i]++;
        Perm.undefined_class_mu_1_Value++;
      }
}
void mu_1_Value::ArrayLimit(PermSet& Perm) {}
void mu_1_Value::Limit(PermSet& Perm) {}
void mu_1_Value::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_Home::Permute(PermSet& Perm, int i) {};
void mu_1_Home::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Home::Canonicalize(PermSet& Perm) {};
void mu_1_Home::SimpleLimit(PermSet& Perm) {};
void mu_1_Home::ArrayLimit(PermSet& Perm) {};
void mu_1_Home::Limit(PermSet& Perm) {};
void mu_1_Home::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Node::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 1 ) && ( value() <= 3 ) )
      value(Perm.perm_mu_1_Proc[Perm.in_mu_1_Proc[i]][value()-1]+(0)); // value - base
  }
}
void mu_1_Node::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 1 ) && ( value() <= 3 ) )
      {
        if (Perm.class_mu_1_Proc[value()-1]==Perm.undefined_class_mu_1_Proc) // value - base
          {
            // it has not been mapped to any particular value
            for (i=0; i<3; i++)
              if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-1)
                Perm.class_mu_1_Proc[i]++;
            value(1 + Perm.undefined_class_mu_1_Proc++);
          }
        else 
          {
            value(Perm.class_mu_1_Proc[value()-1]+1);
          }
      }
  }
}
void mu_1_Node::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Node::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 1 ) && ( value() <= 3 ) )
      if (Perm.class_mu_1_Proc[value()-1]==Perm.undefined_class_mu_1_Proc) // value - base
        {
          // it has not been mapped to any particular value
          for (i=0; i<3; i++)
            if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-1)
              Perm.class_mu_1_Proc[i]++;
          Perm.undefined_class_mu_1_Proc++;
        }
  }
}
void mu_1_Node::ArrayLimit(PermSet& Perm) {}
void mu_1_Node::Limit(PermSet& Perm) {}
void mu_1_Node::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for union type.\n"); };
void mu_1_LUTindex::Permute(PermSet& Perm, int i) {};
void mu_1_LUTindex::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_LUTindex::Canonicalize(PermSet& Perm) {};
void mu_1_LUTindex::SimpleLimit(PermSet& Perm) {};
void mu_1_LUTindex::ArrayLimit(PermSet& Perm) {};
void mu_1_LUTindex::Limit(PermSet& Perm) {};
void mu_1_LUTindex::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_channelType::Permute(PermSet& Perm, int i) {};
void mu_1_channelType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_channelType::Canonicalize(PermSet& Perm) {};
void mu_1_channelType::SimpleLimit(PermSet& Perm) {};
void mu_1_channelType::ArrayLimit(PermSet& Perm) {};
void mu_1_channelType::Limit(PermSet& Perm) {};
void mu_1_channelType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_watchdogType::Permute(PermSet& Perm, int i) {};
void mu_1_watchdogType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_watchdogType::Canonicalize(PermSet& Perm) {};
void mu_1_watchdogType::SimpleLimit(PermSet& Perm) {};
void mu_1_watchdogType::ArrayLimit(PermSet& Perm) {};
void mu_1_watchdogType::Limit(PermSet& Perm) {};
void mu_1_watchdogType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_MessageType::Permute(PermSet& Perm, int i) {};
void mu_1_MessageType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_MessageType::Canonicalize(PermSet& Perm) {};
void mu_1_MessageType::SimpleLimit(PermSet& Perm) {};
void mu_1_MessageType::ArrayLimit(PermSet& Perm) {};
void mu_1_MessageType::Limit(PermSet& Perm) {};
void mu_1_MessageType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Message::Permute(PermSet& Perm, int i)
{
  mu_src.Permute(Perm,i);
  mu_dest.Permute(Perm,i);
  mu_val.Permute(Perm,i);
};
void mu_1_Message::SimpleCanonicalize(PermSet& Perm)
{
  mu_src.SimpleCanonicalize(Perm);
  mu_dest.SimpleCanonicalize(Perm);
  mu_val.SimpleCanonicalize(Perm);
};
void mu_1_Message::Canonicalize(PermSet& Perm)
{
};
void mu_1_Message::SimpleLimit(PermSet& Perm)
{
  mu_src.SimpleLimit(Perm);
  mu_dest.SimpleLimit(Perm);
  mu_val.SimpleLimit(Perm);
};
void mu_1_Message::ArrayLimit(PermSet& Perm){}
void mu_1_Message::Limit(PermSet& Perm)
{
};
void mu_1_Message::MultisetLimit(PermSet& Perm)
{
};
void mu__subrange_12::Permute(PermSet& Perm, int i) {};
void mu__subrange_12::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_12::Canonicalize(PermSet& Perm) {};
void mu__subrange_12::SimpleLimit(PermSet& Perm) {};
void mu__subrange_12::ArrayLimit(PermSet& Perm) {};
void mu__subrange_12::Limit(PermSet& Perm) {};
void mu__subrange_12::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_0::Permute(PermSet& Perm, int i)
{
  static mu_1__type_0 temp("Permute_mu_1__type_0",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<4; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_0::Canonicalize(PermSet& Perm){};
void mu_1__type_0::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<4; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_0::ArrayLimit(PermSet& Perm) {}
void mu_1__type_0::Limit(PermSet& Perm){}
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_1::Permute(PermSet& Perm, int i) {};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_1::Canonicalize(PermSet& Perm) {};
void mu_1__type_1::SimpleLimit(PermSet& Perm) {};
void mu_1__type_1::ArrayLimit(PermSet& Perm) {};
void mu_1__type_1::Limit(PermSet& Perm) {};
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_2::Permute(PermSet& Perm, int i) {};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_2::Canonicalize(PermSet& Perm) {};
void mu_1__type_2::SimpleLimit(PermSet& Perm) {};
void mu_1__type_2::ArrayLimit(PermSet& Perm) {};
void mu_1__type_2::Limit(PermSet& Perm) {};
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_fifo::Permute(PermSet& Perm, int i)
{
  mu_buf.Permute(Perm,i);
};
void mu_1_fifo::SimpleCanonicalize(PermSet& Perm)
{
  mu_buf.SimpleCanonicalize(Perm);
};
void mu_1_fifo::Canonicalize(PermSet& Perm)
{
};
void mu_1_fifo::SimpleLimit(PermSet& Perm)
{
  mu_buf.SimpleLimit(Perm);
};
void mu_1_fifo::ArrayLimit(PermSet& Perm){}
void mu_1_fifo::Limit(PermSet& Perm)
{
};
void mu_1_fifo::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_3::Permute(PermSet& Perm, int i) {};
void mu_1__type_3::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_3::Canonicalize(PermSet& Perm) {};
void mu_1__type_3::SimpleLimit(PermSet& Perm) {};
void mu_1__type_3::ArrayLimit(PermSet& Perm) {};
void mu_1__type_3::Limit(PermSet& Perm) {};
void mu_1__type_3::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_HomeState::Permute(PermSet& Perm, int i)
{
  mu_val.Permute(Perm,i);
  mu_PRLUT.Permute(Perm,i);
  mu_requestor.Permute(Perm,i);
  mu_owner.Permute(Perm,i);
};
void mu_1_HomeState::SimpleCanonicalize(PermSet& Perm)
{
  mu_val.SimpleCanonicalize(Perm);
  mu_PRLUT.SimpleCanonicalize(Perm);
  mu_requestor.SimpleCanonicalize(Perm);
  mu_owner.SimpleCanonicalize(Perm);
};
void mu_1_HomeState::Canonicalize(PermSet& Perm)
{
};
void mu_1_HomeState::SimpleLimit(PermSet& Perm)
{
  mu_val.SimpleLimit(Perm);
  mu_PRLUT.SimpleLimit(Perm);
  mu_requestor.SimpleLimit(Perm);
  mu_owner.SimpleLimit(Perm);
};
void mu_1_HomeState::ArrayLimit(PermSet& Perm){}
void mu_1_HomeState::Limit(PermSet& Perm)
{
};
void mu_1_HomeState::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_4::Permute(PermSet& Perm, int i) {};
void mu_1__type_4::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_4::Canonicalize(PermSet& Perm) {};
void mu_1__type_4::SimpleLimit(PermSet& Perm) {};
void mu_1__type_4::ArrayLimit(PermSet& Perm) {};
void mu_1__type_4::Limit(PermSet& Perm) {};
void mu_1__type_4::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_ProcState::Permute(PermSet& Perm, int i)
{
  mu_val.Permute(Perm,i);
  mu_PR.Permute(Perm,i);
  mu_PWB.Permute(Perm,i);
};
void mu_1_ProcState::SimpleCanonicalize(PermSet& Perm)
{
  mu_val.SimpleCanonicalize(Perm);
  mu_PR.SimpleCanonicalize(Perm);
  mu_PWB.SimpleCanonicalize(Perm);
};
void mu_1_ProcState::Canonicalize(PermSet& Perm)
{
};
void mu_1_ProcState::SimpleLimit(PermSet& Perm)
{
  mu_val.SimpleLimit(Perm);
  mu_PR.SimpleLimit(Perm);
  mu_PWB.SimpleLimit(Perm);
};
void mu_1_ProcState::ArrayLimit(PermSet& Perm){}
void mu_1_ProcState::Limit(PermSet& Perm)
{
};
void mu_1_ProcState::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_5::Permute(PermSet& Perm, int i)
{
  static mu_1__type_5 temp("Permute_mu_1__type_5",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=1; j<=3; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Proc[Perm.in_mu_1_Proc[i]][j-1]];};
void mu_1__type_5::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_5::Canonicalize(PermSet& Perm){};
void mu_1__type_5::SimpleLimit(PermSet& Perm){}
void mu_1__type_5::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_Proc;
  int compare;
  static mu_1_ProcState value[3];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_Proc[3];
  bool pos_mu_1_Proc[3][3];
  // sorting mu_1_Proc
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_Proc[i][j]=FALSE;
      count_mu_1_Proc = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_Proc; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_Proc[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Proc; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_Proc[k][z] = pos_mu_1_Proc[k-1][z];
                    }
                  value[j] = (*this)[i+1];
                  for (z=0; z<3; z++)
                    pos_mu_1_Proc[j][z] = FALSE;
                  pos_mu_1_Proc[j][i] = TRUE;
                  count_mu_1_Proc++;
                  break;
                }
            }
          if (j==count_mu_1_Proc)
            {
              value[j] = (*this)[i+1];
              for (z=0; z<3; z++)
                pos_mu_1_Proc[j][z] = FALSE;
              pos_mu_1_Proc[j][i] = TRUE;
              count_mu_1_Proc++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_Proc[i][k] && Perm.class_mu_1_Proc[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                    pos_mu_1_Proc[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_Proc[k]>j
                            || ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) )
                          Perm.class_mu_1_Proc[k]++;
                      Perm.undefined_class_mu_1_Proc++;
                    }
                }
            }
        }
    }
}
void mu_1__type_5::Limit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_ProcState value[3];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_Proc, oldcount_mu_1_Proc;
  bool pos_mu_1_Proc[3][3];
  bool goodset_mu_1_Proc[3];
  int count_mu_1_Value, oldcount_mu_1_Value;
  bool pos_mu_1_Value[2][2];
  bool goodset_mu_1_Value[2];
  // count_ corresponds to the number of equivalence class within the
  // scalarset value.  If count_ == size of the scalarset, then a unique
  // permutation has been found.

  // pos_ is a relation on a equivalence class number and a scalarset value.

  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_Proc[i][j]=FALSE;
  count_mu_1_Proc = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_Proc[i] == count_mu_1_Proc)
         {
           pos_mu_1_Proc[count_mu_1_Proc][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Proc++;
      else break;
    }
  // count_ corresponds to the number of equivalence class within the
  // scalarset value.  If count_ == size of the scalarset, then a unique
  // permutation has been found.

  // pos_ is a relation on a equivalence class number and a scalarset value.

  // initializing pos array
  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      pos_mu_1_Value[i][j]=FALSE;
  count_mu_1_Value = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<2; i++)
       if (Perm.class_mu_1_Value[i] == count_mu_1_Value)
         {
           pos_mu_1_Value[count_mu_1_Value][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Value++;
      else break;
    }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 3; i0++)
  {

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<3; k++) // step through class
        if ((*this)[k+1].mu_PR.mu_buf[i0].mu_src.isundefined()
            ||(*this)[k+1].mu_PR.mu_buf[i0].mu_src!=k+1)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_Proc[i][k] 
                    && !(*this)[k+1].mu_PR.mu_buf[i0].mu_src.isundefined()
                    && (*this)[k+1].mu_PR.mu_buf[i0].mu_src==k+1)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_Proc; j>i; j--)
                        for (k=0; k<3; k++)
                          pos_mu_1_Proc[j][k] = pos_mu_1_Proc[j-1][k];
                      for (k=0; k<3; k++)
                        {
                          if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                            pos_mu_1_Proc[i][k] = FALSE;
                          if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                            pos_mu_1_Proc[i+1][k] = FALSE;
                        }
                      count_mu_1_Proc++; i++;
                    }
                }
            }
        }
    }

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<3; k++) // step through class
        if ((*this)[k+1].mu_PR.mu_buf[i0].mu_dest.isundefined()
            ||(*this)[k+1].mu_PR.mu_buf[i0].mu_dest!=k+1)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_Proc[i][k] 
                    && !(*this)[k+1].mu_PR.mu_buf[i0].mu_dest.isundefined()
                    && (*this)[k+1].mu_PR.mu_buf[i0].mu_dest==k+1)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_Proc; j>i; j--)
                        for (k=0; k<3; k++)
                          pos_mu_1_Proc[j][k] = pos_mu_1_Proc[j-1][k];
                      for (k=0; k<3; k++)
                        {
                          if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                            pos_mu_1_Proc[i][k] = FALSE;
                          if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                            pos_mu_1_Proc[i+1][k] = FALSE;
                        }
                      count_mu_1_Proc++; i++;
                    }
                }
            }
        }
    }
  }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 3; i0++)
  {

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<3; k++) // step through class
        if ((*this)[k+1].mu_PWB.mu_buf[i0].mu_src.isundefined()
            ||(*this)[k+1].mu_PWB.mu_buf[i0].mu_src!=k+1)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_Proc[i][k] 
                    && !(*this)[k+1].mu_PWB.mu_buf[i0].mu_src.isundefined()
                    && (*this)[k+1].mu_PWB.mu_buf[i0].mu_src==k+1)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_Proc; j>i; j--)
                        for (k=0; k<3; k++)
                          pos_mu_1_Proc[j][k] = pos_mu_1_Proc[j-1][k];
                      for (k=0; k<3; k++)
                        {
                          if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                            pos_mu_1_Proc[i][k] = FALSE;
                          if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                            pos_mu_1_Proc[i+1][k] = FALSE;
                        }
                      count_mu_1_Proc++; i++;
                    }
                }
            }
        }
    }

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<3; k++) // step through class
        if ((*this)[k+1].mu_PWB.mu_buf[i0].mu_dest.isundefined()
            ||(*this)[k+1].mu_PWB.mu_buf[i0].mu_dest!=k+1)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_Proc[i][k] 
                    && !(*this)[k+1].mu_PWB.mu_buf[i0].mu_dest.isundefined()
                    && (*this)[k+1].mu_PWB.mu_buf[i0].mu_dest==k+1)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_Proc; j>i; j--)
                        for (k=0; k<3; k++)
                          pos_mu_1_Proc[j][k] = pos_mu_1_Proc[j-1][k];
                      for (k=0; k<3; k++)
                        {
                          if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                            pos_mu_1_Proc[i][k] = FALSE;
                          if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                            pos_mu_1_Proc[i+1][k] = FALSE;
                        }
                      count_mu_1_Proc++; i++;
                    }
                }
            }
        }
    }
  }

  // refinement -- checking priority in general
  while_guard = FALSE;
  while_guard = while_guard || (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3);
  while_guard = while_guard || (Perm.MTO_class_mu_1_Value() && count_mu_1_Value<2);
  while ( while_guard )
    {
      oldcount_mu_1_Proc = count_mu_1_Proc;
      oldcount_mu_1_Value = count_mu_1_Value;
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 3; i0++)
  {

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<3; k++) // step through class
            if (!(*this)[k+1].mu_PR.mu_buf[i0].mu_src.isundefined()
                &&(*this)[k+1].mu_PR.mu_buf[i0].mu_src!=k+1
                &&(*this)[k+1].mu_PR.mu_buf[i0].mu_src>=1
                &&(*this)[k+1].mu_PR.mu_buf[i0].mu_src<=3)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_Proc; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_Proc; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<3; k++) // step through class
                        goodset_mu_1_Proc[k] = FALSE;
                      for (k=0; k<3; k++) // step through class
                        if (pos_mu_1_Proc[i][k] 
                            && !(*this)[k+1].mu_PR.mu_buf[i0].mu_src.isundefined()
                            && (*this)[k+1].mu_PR.mu_buf[i0].mu_src!=k+1
                            && (*this)[k+1].mu_PR.mu_buf[i0].mu_src>=1
                            && (*this)[k+1].mu_PR.mu_buf[i0].mu_src<=3
                            && pos_mu_1_Proc[j][(*this)[k+1].mu_PR.mu_buf[i0].mu_src-1])
                          {
                            exists = TRUE;
                            goodset_mu_1_Proc[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<3; k++)
                            if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_Proc; j>i; j--)
                                for (k=0; k<3; k++)
                                  pos_mu_1_Proc[j][k] = pos_mu_1_Proc[j-1][k];
                              for (k=0; k<3; k++)
                                {
                                  if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                                    pos_mu_1_Proc[i][k] = FALSE;
                                  if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                                    pos_mu_1_Proc[i+1][k] = FALSE;                  
                                }
                              count_mu_1_Proc++;
                            }
                        }
                    }
                }
            }
        }

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<3; k++) // step through class
            if (!(*this)[k+1].mu_PR.mu_buf[i0].mu_dest.isundefined()
                &&(*this)[k+1].mu_PR.mu_buf[i0].mu_dest!=k+1
                &&(*this)[k+1].mu_PR.mu_buf[i0].mu_dest>=1
                &&(*this)[k+1].mu_PR.mu_buf[i0].mu_dest<=3)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_Proc; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_Proc; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<3; k++) // step through class
                        goodset_mu_1_Proc[k] = FALSE;
                      for (k=0; k<3; k++) // step through class
                        if (pos_mu_1_Proc[i][k] 
                            && !(*this)[k+1].mu_PR.mu_buf[i0].mu_dest.isundefined()
                            && (*this)[k+1].mu_PR.mu_buf[i0].mu_dest!=k+1
                            && (*this)[k+1].mu_PR.mu_buf[i0].mu_dest>=1
                            && (*this)[k+1].mu_PR.mu_buf[i0].mu_dest<=3
                            && pos_mu_1_Proc[j][(*this)[k+1].mu_PR.mu_buf[i0].mu_dest-1])
                          {
                            exists = TRUE;
                            goodset_mu_1_Proc[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<3; k++)
                            if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_Proc; j>i; j--)
                                for (k=0; k<3; k++)
                                  pos_mu_1_Proc[j][k] = pos_mu_1_Proc[j-1][k];
                              for (k=0; k<3; k++)
                                {
                                  if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                                    pos_mu_1_Proc[i][k] = FALSE;
                                  if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                                    pos_mu_1_Proc[i+1][k] = FALSE;                  
                                }
                              count_mu_1_Proc++;
                            }
                        }
                    }
                }
            }
        }
  }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 3; i0++)
  {

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<3; k++) // step through class
            if (!(*this)[k+1].mu_PWB.mu_buf[i0].mu_src.isundefined()
                &&(*this)[k+1].mu_PWB.mu_buf[i0].mu_src!=k+1
                &&(*this)[k+1].mu_PWB.mu_buf[i0].mu_src>=1
                &&(*this)[k+1].mu_PWB.mu_buf[i0].mu_src<=3)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_Proc; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_Proc; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<3; k++) // step through class
                        goodset_mu_1_Proc[k] = FALSE;
                      for (k=0; k<3; k++) // step through class
                        if (pos_mu_1_Proc[i][k] 
                            && !(*this)[k+1].mu_PWB.mu_buf[i0].mu_src.isundefined()
                            && (*this)[k+1].mu_PWB.mu_buf[i0].mu_src!=k+1
                            && (*this)[k+1].mu_PWB.mu_buf[i0].mu_src>=1
                            && (*this)[k+1].mu_PWB.mu_buf[i0].mu_src<=3
                            && pos_mu_1_Proc[j][(*this)[k+1].mu_PWB.mu_buf[i0].mu_src-1])
                          {
                            exists = TRUE;
                            goodset_mu_1_Proc[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<3; k++)
                            if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_Proc; j>i; j--)
                                for (k=0; k<3; k++)
                                  pos_mu_1_Proc[j][k] = pos_mu_1_Proc[j-1][k];
                              for (k=0; k<3; k++)
                                {
                                  if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                                    pos_mu_1_Proc[i][k] = FALSE;
                                  if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                                    pos_mu_1_Proc[i+1][k] = FALSE;                  
                                }
                              count_mu_1_Proc++;
                            }
                        }
                    }
                }
            }
        }

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<3; k++) // step through class
            if (!(*this)[k+1].mu_PWB.mu_buf[i0].mu_dest.isundefined()
                &&(*this)[k+1].mu_PWB.mu_buf[i0].mu_dest!=k+1
                &&(*this)[k+1].mu_PWB.mu_buf[i0].mu_dest>=1
                &&(*this)[k+1].mu_PWB.mu_buf[i0].mu_dest<=3)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_Proc; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_Proc; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<3; k++) // step through class
                        goodset_mu_1_Proc[k] = FALSE;
                      for (k=0; k<3; k++) // step through class
                        if (pos_mu_1_Proc[i][k] 
                            && !(*this)[k+1].mu_PWB.mu_buf[i0].mu_dest.isundefined()
                            && (*this)[k+1].mu_PWB.mu_buf[i0].mu_dest!=k+1
                            && (*this)[k+1].mu_PWB.mu_buf[i0].mu_dest>=1
                            && (*this)[k+1].mu_PWB.mu_buf[i0].mu_dest<=3
                            && pos_mu_1_Proc[j][(*this)[k+1].mu_PWB.mu_buf[i0].mu_dest-1])
                          {
                            exists = TRUE;
                            goodset_mu_1_Proc[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<3; k++)
                            if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_Proc; j>i; j--)
                                for (k=0; k<3; k++)
                                  pos_mu_1_Proc[j][k] = pos_mu_1_Proc[j-1][k];
                              for (k=0; k<3; k++)
                                {
                                  if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                                    pos_mu_1_Proc[i][k] = FALSE;
                                  if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                                    pos_mu_1_Proc[i+1][k] = FALSE;                  
                                }
                              count_mu_1_Proc++;
                            }
                        }
                    }
                }
            }
        }
  }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
           || ( Perm.MTO_class_mu_1_Value() && count_mu_1_Value<2) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<3; k++) // step through class
            if ((*this)[k+1].mu_val.isundefined())
              exists = TRUE;
            else
              split = TRUE;
          if (exists && split)
            {
              for (i=0; i<count_mu_1_Proc; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Value; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_Proc[k] = FALSE;
                    for (k=0; k<2; k++) // initialize goodset
                      goodset_mu_1_Value[k] = FALSE;
                    for (k=0; k<3; k++) // scan array index
                      // set goodsets
                      if (pos_mu_1_Proc[i][k] 
                          && !(*this)[k+1].mu_val.isundefined()
                          && pos_mu_1_Value[j][(*this)[k+1].mu_val-4])
                        {
                          exists = TRUE;
                          goodset_mu_1_Proc[k] = TRUE;
                          goodset_mu_1_Value[(*this)[k+1].mu_val-4] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Proc; z>i; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_Proc[z][k] = pos_mu_1_Proc[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[i][k] = FALSE;
                                if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[i+1][k] = FALSE;
                              }
                            count_mu_1_Proc++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<2; k++)
                          if ( pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Value; z>j; z--)
                              for (k=0; k<2; k++)
                                pos_mu_1_Value[z][k] = pos_mu_1_Value[z-1][k];
                            // split pos
                            for (k=0; k<2; k++)
                              {
                                if (pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j][k] = FALSE;
                                if (pos_mu_1_Value[j+1][k] && goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j+1][k] = FALSE;
                              }
                            count_mu_1_Value++;
                          }
                      }
                  }
            }
        }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 3; i0++)
  {

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
           || ( Perm.MTO_class_mu_1_Value() && count_mu_1_Value<2) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<3; k++) // step through class
            if ((*this)[k+1].mu_PR.mu_buf[i0].mu_val.isundefined())
              exists = TRUE;
            else
              split = TRUE;
          if (exists && split)
            {
              for (i=0; i<count_mu_1_Proc; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Value; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_Proc[k] = FALSE;
                    for (k=0; k<2; k++) // initialize goodset
                      goodset_mu_1_Value[k] = FALSE;
                    for (k=0; k<3; k++) // scan array index
                      // set goodsets
                      if (pos_mu_1_Proc[i][k] 
                          && !(*this)[k+1].mu_PR.mu_buf[i0].mu_val.isundefined()
                          && pos_mu_1_Value[j][(*this)[k+1].mu_PR.mu_buf[i0].mu_val-4])
                        {
                          exists = TRUE;
                          goodset_mu_1_Proc[k] = TRUE;
                          goodset_mu_1_Value[(*this)[k+1].mu_PR.mu_buf[i0].mu_val-4] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Proc; z>i; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_Proc[z][k] = pos_mu_1_Proc[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[i][k] = FALSE;
                                if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[i+1][k] = FALSE;
                              }
                            count_mu_1_Proc++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<2; k++)
                          if ( pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Value; z>j; z--)
                              for (k=0; k<2; k++)
                                pos_mu_1_Value[z][k] = pos_mu_1_Value[z-1][k];
                            // split pos
                            for (k=0; k<2; k++)
                              {
                                if (pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j][k] = FALSE;
                                if (pos_mu_1_Value[j+1][k] && goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j+1][k] = FALSE;
                              }
                            count_mu_1_Value++;
                          }
                      }
                  }
            }
        }
  }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 3; i0++)
  {

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
           || ( Perm.MTO_class_mu_1_Value() && count_mu_1_Value<2) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<3; k++) // step through class
            if ((*this)[k+1].mu_PWB.mu_buf[i0].mu_val.isundefined())
              exists = TRUE;
            else
              split = TRUE;
          if (exists && split)
            {
              for (i=0; i<count_mu_1_Proc; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Value; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_Proc[k] = FALSE;
                    for (k=0; k<2; k++) // initialize goodset
                      goodset_mu_1_Value[k] = FALSE;
                    for (k=0; k<3; k++) // scan array index
                      // set goodsets
                      if (pos_mu_1_Proc[i][k] 
                          && !(*this)[k+1].mu_PWB.mu_buf[i0].mu_val.isundefined()
                          && pos_mu_1_Value[j][(*this)[k+1].mu_PWB.mu_buf[i0].mu_val-4])
                        {
                          exists = TRUE;
                          goodset_mu_1_Proc[k] = TRUE;
                          goodset_mu_1_Value[(*this)[k+1].mu_PWB.mu_buf[i0].mu_val-4] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Proc; z>i; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_Proc[z][k] = pos_mu_1_Proc[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[i][k] = FALSE;
                                if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[i+1][k] = FALSE;
                              }
                            count_mu_1_Proc++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<2; k++)
                          if ( pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Value; z>j; z--)
                              for (k=0; k<2; k++)
                                pos_mu_1_Value[z][k] = pos_mu_1_Value[z-1][k];
                            // split pos
                            for (k=0; k<2; k++)
                              {
                                if (pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j][k] = FALSE;
                                if (pos_mu_1_Value[j+1][k] && goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j+1][k] = FALSE;
                              }
                            count_mu_1_Value++;
                          }
                      }
                  }
            }
        }
  }
      while_guard = FALSE;
      while_guard = while_guard || (oldcount_mu_1_Proc!=count_mu_1_Proc);
      while_guard = while_guard || (oldcount_mu_1_Value!=count_mu_1_Value);
      while_guard_temp = while_guard;
      while_guard = FALSE;
      while_guard = while_guard || count_mu_1_Proc<3;
      while_guard = while_guard || count_mu_1_Value<2;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_Proc[i][j])
            Perm.class_mu_1_Proc[j] = i;
      Perm.undefined_class_mu_1_Proc=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_Proc[j]>Perm.undefined_class_mu_1_Proc)
          Perm.undefined_class_mu_1_Proc=Perm.class_mu_1_Proc[j];
    }
  // enter the result into class
  if (Perm.MTO_class_mu_1_Value())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          if (pos_mu_1_Value[i][j])
            Perm.class_mu_1_Value[j] = i;
      Perm.undefined_class_mu_1_Value=0;
      for (j=0; j<2; j++)
        if (Perm.class_mu_1_Value[j]>Perm.undefined_class_mu_1_Value)
          Perm.undefined_class_mu_1_Value=Perm.class_mu_1_Value[j];
    }
}
void mu_1__type_5::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };

/********************
 Auxiliary function for error trace printing
 ********************/
bool match(state* ns, StatePtr p)
{
  int i;
  static PermSet Perm;
  static state temp;
  StateCopy(&temp, ns);
  if (args->symmetry_reduction.value)
    {
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
         || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_channelNum.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_channelNum.MultisetSort();
              mu_msg_processed.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_msg_processed.MultisetSort();
              mu_current_channel.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_current_channel.MultisetSort();
              mu_temp_msg_home.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_temp_msg_home.MultisetSort();
              mu_LastWrite.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_LastWrite.MultisetSort();
              mu_HomeNode.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_HomeNode.MultisetSort();
              mu_temp_msg.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_temp_msg.MultisetSort();
              mu_home_send_msg.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_home_send_msg.MultisetSort();
              mu_Procs.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Procs.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
      else {
        Perm.ResetToSimple();
        Perm.SimpleToOne();
        if (ns != workingstate)
          StateCopy(workingstate, ns);

          mu_channelNum.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_channelNum.MultisetSort();
          mu_msg_processed.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_msg_processed.MultisetSort();
          mu_current_channel.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_current_channel.MultisetSort();
          mu_temp_msg_home.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_temp_msg_home.MultisetSort();
          mu_LastWrite.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_LastWrite.MultisetSort();
          mu_HomeNode.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_HomeNode.MultisetSort();
          mu_temp_msg.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_temp_msg.MultisetSort();
          mu_home_send_msg.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_home_send_msg.MultisetSort();
          mu_Procs.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Procs.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_channelNum.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_channelNum.MultisetSort();
              mu_msg_processed.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_msg_processed.MultisetSort();
              mu_current_channel.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_current_channel.MultisetSort();
              mu_temp_msg_home.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_temp_msg_home.MultisetSort();
              mu_LastWrite.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_LastWrite.MultisetSort();
              mu_HomeNode.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_HomeNode.MultisetSort();
              mu_temp_msg.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_temp_msg.MultisetSort();
              mu_home_send_msg.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_home_send_msg.MultisetSort();
              mu_Procs.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Procs.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
    }
  if (!args->symmetry_reduction.value
      && args->multiset_reduction.value)
    {
      if (ns != workingstate)
          StateCopy(workingstate, ns);
      mu_channelNum.MultisetSort();
      mu_msg_processed.MultisetSort();
      mu_current_channel.MultisetSort();
      mu_temp_msg_home.MultisetSort();
      mu_LastWrite.MultisetSort();
      mu_HomeNode.MultisetSort();
      mu_temp_msg.MultisetSort();
      mu_home_send_msg.MultisetSort();
      mu_Procs.MultisetSort();
      if (p.compare(workingstate)) {
        StateCopy(workingstate,&temp); return TRUE; }
      StateCopy(workingstate,&temp);
      return FALSE;
    }
  return (p.compare(ns));
}

/********************
 Canonicalization by fast exhaustive generation of
 all permutations
 ********************/
void SymmetryClass::Exhaustive_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;
  Perm.ResetToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_channelNum.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_channelNum.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_msg_processed.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_msg_processed.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_current_channel.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_current_channel.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_temp_msg_home.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_temp_msg_home.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_LastWrite.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_LastWrite.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_HomeNode.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_HomeNode.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_temp_msg.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_temp_msg.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_home_send_msg.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_home_send_msg.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Procs.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Procs.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 ********************/
void SymmetryClass::Heuristic_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_temp_msg_home.SimpleCanonicalize(Perm);

  mu_LastWrite.SimpleCanonicalize(Perm);

  mu_HomeNode.SimpleCanonicalize(Perm);

  mu_temp_msg.SimpleCanonicalize(Perm);

  mu_home_send_msg.SimpleCanonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.Limit(Perm);
  }

  Perm.SimpleToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Procs.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Procs.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

  mu_temp_msg_home.SimpleCanonicalize(Perm);

  mu_LastWrite.SimpleCanonicalize(Perm);

  mu_HomeNode.SimpleCanonicalize(Perm);

  mu_temp_msg.SimpleCanonicalize(Perm);

  mu_home_send_msg.SimpleCanonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.Limit(Perm);
  }

  Perm.SimpleToOne();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  mu_Procs.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Procs.MultisetSort();
  BestPermutedState = *workingstate;
  BestInitialized = TRUE;

  cycle=1;
  while (Perm.NextPermutation())
    {
      if (args->perm_limit.value != 0
          && cycle++ >= args->perm_limit.value) break;
      StateCopy(workingstate, &temp);
      mu_Procs.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_Procs.MultisetSort();
      switch (StateCmp(workingstate, &BestPermutedState)) {
      case -1:
        BestPermutedState = *workingstate;
        break;
      case 1:
        break;
      case 0:
        break;
      default:
        Error.Error("funny return value from StateCmp");
      }
    }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Normalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and for all other variables, pick any remaining permutation
 ********************/
void SymmetryClass::Heuristic_Fast_Normalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_temp_msg_home.SimpleCanonicalize(Perm);

  mu_LastWrite.SimpleCanonicalize(Perm);

  mu_HomeNode.SimpleCanonicalize(Perm);

  mu_temp_msg.SimpleCanonicalize(Perm);

  mu_home_send_msg.SimpleCanonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.Limit(Perm);
  }

  Perm.SimpleToOne();

  mu_Procs.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Procs.MultisetSort();

};

/********************
  Include
 ********************/
#include "mu_epilog.hpp"
