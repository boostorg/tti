#include "test_has_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Too many 'typename' parameters
  
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_TEMPLATE_GEN(SomeMemberTemplate)<AnotherType>));
  
  return 0;

  }
