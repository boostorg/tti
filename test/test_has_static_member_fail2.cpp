#include "test_has_static_member.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong enclosing type for DSMember
  
  BOOST_MPL_ASSERT((boost::tti::has_static_member_DSMember<AnotherType,short>));
  
  return 0;

  }
