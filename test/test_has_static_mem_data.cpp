#include "test_has_static_mem_data.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST((BOOST_TTI_HAS_STATIC_MEMBER_DATA_GEN(DSMember)<AType,short>::value));
  BOOST_TEST((!BOOST_TTI_HAS_STATIC_MEMBER_DATA_GEN(SomeStaticData)<AnotherType,float>::value));
  BOOST_TEST((BOOST_TTI_TRAIT_GEN(StatName)<AnotherType,AType::AStructType>::value));
  
  return boost::report_errors();

  }
