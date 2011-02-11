#include "test_has_type.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST(tti::has_type_AnIntType<AType>::value);
  BOOST_TEST(tti::has_type_AnIntTypeReference<AType>::value);
  BOOST_TEST(tti::NameStruct<AType>::value);
  BOOST_TEST(tti::has_type_BType<AType>::value);
  BOOST_TEST(tti::TheInteger<AType::BType>::value);
  BOOST_TEST(tti::has_type_CType<AType::BType>::value);
  BOOST_TEST(tti::has_type_AnotherIntegerType<AType::BType::CType>::value);
  BOOST_TEST(tti::SomethingElse<AnotherType>::value);
  BOOST_TEST(!tti::has_type_NoOtherType<AnotherType>::value);
  
  return boost::report_errors();

  }
