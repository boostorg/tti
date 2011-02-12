#include "test_has_type.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((boost::tti::has_type_BType<AnotherType>));
  
  return 0;

  }
