#include "test_has_static_mem_data.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST((boost::tti::has_static_member_data_DSMember<AType,short>::value));
  BOOST_TEST((!boost::tti::has_static_member_data_SomeStaticData<AnotherType,float>::value));
  BOOST_TEST((boost::tti::StatName<AnotherType,AType::AStructType>::value));
  
  return boost::report_errors();

  }
