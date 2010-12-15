#include "TestMemberType.hpp"
#include <boost/detail/lightweight_test.hpp>
#include <boost/type_traits/is_same.hpp>

int main()
  {
  
  BOOST_TEST((boost::is_same<tti::member_type_AnIntType<AType>::type,AType::AnIntType>::value));
  BOOST_TEST((boost::is_same<tti::NameStruct<AType>::type,AType::AStructType>::value));
  BOOST_TEST((boost::is_same<tti::member_type_AnIntTypeReference<AType>::type,AType::AnIntTypeReference>::value));
  BOOST_TEST((boost::is_same<tti::member_type_BType<AType>::type,AType::BType>::value));
  BOOST_TEST((boost::is_same<tti::TheInteger<AType::BType>::type,AType::BType::AnIntegerType>::value));
  BOOST_TEST((boost::is_same<tti::member_type_CType<AType::BType>::type,AType::BType::CType>::value));
  BOOST_TEST((boost::is_same<tti::member_type_AnotherIntegerType<AType::BType::CType>::type,AType::BType::CType::AnotherIntegerType>::value));
  BOOST_TEST((boost::is_same<tti::SomethingElse<AnotherType>::type,AnotherType::someOtherType>::value));
  
  return boost::report_errors();

  }
