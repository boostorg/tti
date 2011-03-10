#include "test_has_static_mem_fun.hpp"

int main()
  {
  
  // Function signature has type which does not exist
  
  BOOST_TTI_HAS_STATIC_MEMBER_FUNCTION_GEN(TSFunction)<AnotherType,AType::AClassType,boost::mpl::vector<AType::AnIntType,double> > aVar;
  
  return 0;

  }
