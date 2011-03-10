#include "test_has_template_cp.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((BOOST_TTI_TRAIT_GEN(HaveCL)<AnotherType>));
  
  return 0;

  }
