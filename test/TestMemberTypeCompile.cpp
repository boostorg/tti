#include "TestMemberType.hpp"
#include <boost/mpl/assert.hpp>
#include <boost/mpl/bool.hpp>

int main()
  {
  
  BOOST_MPL_ASSERT((boost::mpl::bool_<tti::member_type_AnIntType<AType>::valid>));
  BOOST_MPL_ASSERT((boost::mpl::bool_<tti::NameStruct<AType>::valid>));
  BOOST_MPL_ASSERT((boost::mpl::bool_<tti::member_type_AnIntTypeReference<AType>::valid>));
  BOOST_MPL_ASSERT((boost::mpl::bool_<tti::member_type_BType<AType>::valid>));
  BOOST_MPL_ASSERT((boost::mpl::bool_<tti::TheInteger<AType::BType>::valid>));
  BOOST_MPL_ASSERT((boost::mpl::bool_<tti::member_type_CType<AType::BType>::valid>));
  BOOST_MPL_ASSERT((boost::mpl::bool_<tti::member_type_AnotherIntegerType<AType::BType::CType>::valid>));
  BOOST_MPL_ASSERT((boost::mpl::bool_<tti::SomethingElse<AnotherType>::valid>));
  
  return 0;

  }
