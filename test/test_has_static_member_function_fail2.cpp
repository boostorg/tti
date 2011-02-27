#include "test_has_static_mem_fun.hpp"

int main()
  {
  
  // Function signature has type which does not exist
  
  boost::tti::has_static_member_TSFunction<AnotherType,AType::AClassType,boost::mpl::vector<AType::AnIntType,double> > aVar;
  
  return 0;

  }
