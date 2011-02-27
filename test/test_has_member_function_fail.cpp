#include "test_has_mem_fun.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong function signature for sFunction
  
  BOOST_MPL_ASSERT((boost::tti::has_member_function_sFunction<AnotherType,AType::AnIntType,boost::mpl::vector<short,long,double> >));
  
  return 0;

  }
