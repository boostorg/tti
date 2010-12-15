#include "TestHasTypeCheckTypedef.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // NoOtherType does not exist at all
  
  BOOST_MPL_ASSERT((tti::has_type_check_typedef_NoOtherType<AType,int>));
  
  return 0;

  }
