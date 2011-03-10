#include "test_has_static_mem_data.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  BOOST_TTI_HAS_STATIC_MEMBER_DATA_GEN(SomeStaticData)<AnotherType,long> aVar2;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_STATIC_MEMBER_DATA_GEN(DSMember)<AType,short>));
  BOOST_MPL_ASSERT((BOOST_TTI_TRAIT_GEN(StatName)<AnotherType,AType::AStructType>));
  
  return 0;

  }
