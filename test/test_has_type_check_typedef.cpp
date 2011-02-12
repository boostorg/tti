#include "test_has_type_check_typedef.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST((boost::tti::has_type_AnIntType<AType,int>::value));
  BOOST_TEST((boost::tti::NameStruct<AType,AType::AStructType>::value));
  BOOST_TEST((boost::tti::has_type_AnIntTypeReference<AType,int &>::value));
  BOOST_TEST((boost::tti::has_type_BType<AType,AType::BType>::value));
  BOOST_TEST((boost::tti::TheInteger<AType::BType,int>::value));
  BOOST_TEST((boost::tti::has_type_CType<AType::BType,AType::BType::CType>::value));
  BOOST_TEST((boost::tti::has_type_AnotherIntegerType<AType::BType::CType,int>::value));
  BOOST_TEST((boost::tti::SomethingElse<AnotherType,AType::AnIntType>::value));
  BOOST_TEST((!boost::tti::has_type_NoOtherType<AnotherType,double>::value));
  
  return boost::report_errors();

  }
