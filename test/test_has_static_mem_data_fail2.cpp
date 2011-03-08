#include "test_has_static_mem_data.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong enclosing type for DSMember
  
  BOOST_MPL_ASSERT((boost::tti::has_static_member_data_DSMember<AnotherType,short>));
  
  return 0;

  }
