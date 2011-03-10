#include "test_has_static_mem_data.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong enclosing type for DSMember
  
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_STATIC_MEMBER_DATA_GEN(DSMember)<AnotherType,short>));
  
  return 0;

  }
