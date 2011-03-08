#include "test_has_static_member.hpp"

int main()
  {
  
  // Function signature has type which does not exist
  
  boost::tti::has_comp_static_member_function_TSFunction<AnotherType,AType::AClassType (AType::AnIntType,double)> aVar;
  
  return 0;

  }
