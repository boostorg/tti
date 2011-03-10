#include "test_has_member.hpp"

int main()
  {
  
  // Function signature has type which does not exist
  
  BOOST_TTI_HAS_COMP_MEMBER_FUNCTION_GEN(sFunction)<AType::AnIntType (NVType::*)(short,long,double)> aVar;
  
  return 0;

  }
