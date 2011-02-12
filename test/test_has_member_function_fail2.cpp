#include "test_has_member_function.hpp"

int main()
  {
  
  // Function signature has type which does not exist
  
  boost::tti::has_member_function_sFunction<NVType,AType::AnIntType,boost::mpl::vector<short,long,double> > aVar;
  
  return 0;

  }
