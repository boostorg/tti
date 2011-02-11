#include "test_has_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Too many 'typename' parameters
  
  BOOST_MPL_ASSERT((tti::has_template_SomeMemberTemplate<AnotherType>));
  
  return 0;

  }
