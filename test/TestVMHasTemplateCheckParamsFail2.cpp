#include "TestVMHasTemplateCheckParams.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((tti::HaveCL<AnotherType>));
  
  return 0;

  }
