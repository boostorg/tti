#include "test_has_static_member.hpp"

int main()
  {
  
  // Function signature has type which does not exist
  
  BOOST_TTI_HAS_COMP_STATIC_MEMBER_FUNCTION_GEN(TSFunction)<AnotherType,AType::AClassType (AType::AnIntType,double)> aVar;
  
  return 0;

  }
