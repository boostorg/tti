#include "test_has_mem_fun_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong function signature for 
  
  BOOST_MPL_ASSERT((boost::mpl::false_));
  
  return 0;
  
  }
