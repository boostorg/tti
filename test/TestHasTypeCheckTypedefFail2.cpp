#include "test_has_type_check_typedef.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((tti::has_type_BType<AnotherType,short>));
  
  return 0;

  }
