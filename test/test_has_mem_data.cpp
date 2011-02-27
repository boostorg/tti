#include "test_has_mem_data.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST((boost::tti::has_member_data_AnInt<AType,int>::value));
  BOOST_TEST((boost::tti::has_member_data_AnInt<AnotherType,long>::value));
  BOOST_TEST((boost::tti::has_member_data_aMember<AnotherType,bool>::value));
  BOOST_TEST((!boost::tti::has_member_data_aMember<AnotherType,int>::value));
  BOOST_TEST((boost::tti::CMember<AnotherType,bool>::value));
  BOOST_TEST((!boost::tti::has_member_data_someDataMember<AType,short>::value));
  BOOST_TEST((boost::tti::has_member_data_IntBT<AType,AType::BType>::value));
  BOOST_TEST((boost::tti::NestedData<AType,AType::BType::CType>::value));
  BOOST_TEST((boost::tti::AOther<AnotherType,AType>::value));
  BOOST_TEST((boost::tti::has_member_data_ONestStr<AnotherType,AType::AStructType>::value));
  
  return boost::report_errors();

  }
