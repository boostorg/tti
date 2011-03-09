#include "test_has_mem_data.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // someDataMember does not exist at all
  
  BOOST_MPL_ASSERT(( BOOST_TTI_HAS_MEMBER_DATA_GEN(someDataMember)<AType,short> ));
  
  return 0;

  }
