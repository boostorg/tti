#include "test_has_static_mem_data.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // SomeStaticData does not exist at all
  
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_STATIC_MEMBER_DATA_GEN(SomeStaticData)<AnotherType,float>));
  
  return 0;

  }
