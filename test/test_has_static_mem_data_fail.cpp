#include "test_has_static_mem_data.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // SomeStaticData does not exist at all
  
  BOOST_MPL_ASSERT((boost::tti::has_static_member_data_SomeStaticData<AnotherType,float>));
  
  return 0;

  }
