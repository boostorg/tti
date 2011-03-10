#include "test_has_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_TEMPLATE_GEN(ATPMemberTemplate)<AnotherType>));
  
  return 0;

  }
