#include "test_has_member.hpp"

int main()
  {
  
  // Function signature has type which does not exist
  
  tti::has_member_sFunction<AType::AnIntType (NVType::*)(short,long,double)> aVar;
  
  return 0;

  }
