#include "test_has_template_check_params.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((boost::tti::HaveCL<AnotherType>));
  
  return 0;

  }
