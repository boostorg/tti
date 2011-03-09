#include "test_has_mem_fun.hpp"

int main()
  {
  
  // Function signature has type which does not exist
  
  BOOST_TTI_HAS_MEMBER_FUNCTION_GEN(sFunction)<NVType,AType::AnIntType,boost::mpl::vector<short,long,double> > aVar;
  
  return 0;

  }
