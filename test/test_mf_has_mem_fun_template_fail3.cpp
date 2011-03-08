#include "test_mf_has_mem_fun_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  BOOST_MPL_ASSERT((boost::mpl::false_));
  
  return 0;

  }
