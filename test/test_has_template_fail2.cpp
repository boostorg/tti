#include "test_has_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((boost::tti::has_template_ATPMemberTemplate<AnotherType>));
  
  return 0;

  }
