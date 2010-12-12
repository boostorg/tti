#if !defined(TEST_STRUCTS_HPP)
#define TEST_STRUCTS_HPP

struct AType 
  {
  
  // Type
  
  typedef int AnIntType;
  struct AStructType
    {
    };
  typedef int & AnIntTypeReference;
  struct BType
    {
    typedef int AnIntegerType;
    struct CType
      {
      typedef int AnotherIntegerType;
      };
    };
    
  // Template
    
  template <class> struct ATPMemberTemplate { };
  template <int> struct AMemberTemplate { };
  template <int,int> struct AnotherMemberTemplate { };
  template <class,class> struct CLMemberTemplate { };
  
  // Data
  
  int AnInt;
  
  // Function
  
  void VoidFunction() { }
  int IntFunction() { return 0; }
  
  // Static Data
  
  static short DSMember;
  
  // Static Function
  
  static int SIntFunction(long,double) { return 2; }
  
  };
  
struct AnotherType
  {
  
  // Type
  
  typedef AType::AnIntType someOtherType;
    
  // Template
  
  template <class,class,class,class,class,class> struct SomeMemberTemplate { };
  template <class,class,int,class,template <class> class InnerTemplate,class,long> struct ManyParameters { };
  template <class,class,class,class> struct SimpleTMP { };
  
  // Data
  
  bool aMember;
  bool cMem;
  long AnInt;
  
  // Function
  
  AType aFunction(int) { return AType(); }
  int anotherFunction(AType) { return 0; }
  AType::AnIntType sFunction(int,long,double) { return 0; }
  double IntFunction(int) { return 0; }
  
  // Static Data
  
  // Static Function
  
  static AType TIntFunction(long,double) { return AType(); }
  static AType::AStructType TSFunction(AType::AnIntType,double) { return AType::AStructType(); }
  
  };

short AType::DSMember(5622);

#endif // TEST_STRUCTS_HPP
