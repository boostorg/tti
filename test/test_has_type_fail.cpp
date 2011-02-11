#include "test_has_type.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // NoOtherType does not exist at all
  
  BOOST_MPL_ASSERT((tti::has_type_NoOtherType<AnotherType>));
  
  return 0;

  }
