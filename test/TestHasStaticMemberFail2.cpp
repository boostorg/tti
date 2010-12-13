#include "TestHasStaticMember.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong enclosing type for DSMember
  
  BOOST_MPL_ASSERT((AnotherType,short));
  
  return 0;

  }
