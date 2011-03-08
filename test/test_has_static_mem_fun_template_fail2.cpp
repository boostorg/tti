#include "test_has_static_mem_fun_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  BOOST_MPL_ASSERT((boost::mpl::false_));
  
  return 0;

  }
