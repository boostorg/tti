#include "TestMemberType.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  BOOST_MPL_ASSERT((boost::is_same<tti::member_type_AnIntType<AType>::type,AType::AnIntType>));
  BOOST_MPL_ASSERT((boost::is_same<tti::NameStruct<AType>::type,AType::AStructType>));
  BOOST_MPL_ASSERT((boost::is_same<tti::member_type_AnIntTypeReference<AType>::type,AType::AnIntTypeReference>));
  BOOST_MPL_ASSERT((boost::is_same<tti::member_type_BType<AType>::type,AType::BType>));
  BOOST_MPL_ASSERT((boost::is_same<tti::TheInteger<AType::BType>::type,AType::BType::AnIntegerType>));
  BOOST_MPL_ASSERT((boost::is_same<tti::member_type_CType<AType::BType>::type,AType::BType::CType>));
  BOOST_MPL_ASSERT((boost::is_same<tti::member_type_AnotherIntegerType<AType::BType::CType>::type,AType::BType::CType::AnotherIntegerType>));
  BOOST_MPL_ASSERT((boost::is_same<tti::SomethingElse<AnotherType>::type,AnotherType::someOtherType>));
  
  return 0;

  }
