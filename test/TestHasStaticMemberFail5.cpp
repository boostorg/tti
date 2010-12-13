#include "TestHasStaticMember.hpp"

int main()
  {
  
  // Function signature has type which does not exist
  
  tti::has_static_member_TSFunction<AnotherType,AType::AClassType (AType::AnIntType,double)> aVar;
  
  return 0;

  }
