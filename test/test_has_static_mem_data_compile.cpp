#include "test_has_static_mem_data.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  boost::tti::has_static_member_data_SomeStaticData<AnotherType,long> aVar2;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((boost::tti::has_static_member_data_DSMember<AType,short>));
  BOOST_MPL_ASSERT((boost::tti::StatName<AnotherType,AType::AStructType>));
  
  return 0;

  }
