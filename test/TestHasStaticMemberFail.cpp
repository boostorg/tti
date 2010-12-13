#include "TestHasStaticMember.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // SomeStaticData does not exist at all
  
  BOOST_MPL_ASSERT((tti::has_static_member_SomeStaticData<AnotherType,float>));
  
  return 0;

  }
