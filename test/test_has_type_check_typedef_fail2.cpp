#include "test_has_type_ct.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((boost::tti::has_type_BType<AnotherType,short>));
  
  return 0;

  }
