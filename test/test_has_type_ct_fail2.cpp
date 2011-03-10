#include "test_has_type_ct.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_TYPE_GEN(BType)<AnotherType,short>));
  
  return 0;

  }
