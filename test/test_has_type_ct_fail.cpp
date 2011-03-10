#include "test_has_type_ct.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // NoOtherType does not exist at all
  
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_TYPE_GEN(NoOtherType)<AType,int>));
  
  return 0;

  }
