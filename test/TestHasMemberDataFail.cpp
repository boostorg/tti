#include "TestHasMemberData.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // someDataMember does not exist at all
  
  BOOST_MPL_ASSERT(( tti::has_member_data_someDataMember<AType,short> ));
  
  return 0;

  }
