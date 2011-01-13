#include "TestMemberType.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST(tti::member_type_AnIntType<AType>::valid);
  BOOST_TEST(tti::NameStruct<AType>::valid);
  BOOST_TEST(tti::member_type_AnIntTypeReference<AType>::valid);
  BOOST_TEST(tti::member_type_BType<AType>::valid);
  BOOST_TEST(tti::TheInteger<AType::BType>::valid);
  BOOST_TEST(tti::member_type_CType<AType::BType>::valid);
  BOOST_TEST(tti::member_type_AnotherIntegerType<AType::BType::CType>::valid);
  BOOST_TEST(tti::SomethingElse<AnotherType>::valid);
  
  return boost::report_errors();

  }
