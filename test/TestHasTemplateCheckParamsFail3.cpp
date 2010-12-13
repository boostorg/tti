#include "TestHasTemplateCheckParams.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong template parameters
  
  BOOST_MPL_ASSERT((tti::WrongParametersForMP<AnotherType>));
  
  return 0;

  }
