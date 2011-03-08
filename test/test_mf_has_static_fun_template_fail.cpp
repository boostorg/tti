#include "test_mf_has_static_fun_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // You can always instantiate without compiler errors
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((boost::mpl::false_));
  
  return 0;

  }
