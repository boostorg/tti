#include "test_member_type.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  BOOST_MPL_ASSERT((tti::mf_valid_member_type<tti::member_type_AnIntType<AType> >));
  BOOST_MPL_ASSERT((tti::mf_valid_member_type<tti::NameStruct<AType> >));
  BOOST_MPL_ASSERT((tti::mf_valid_member_type<tti::member_type_AnIntTypeReference<AType> >));
  BOOST_MPL_ASSERT((tti::mf_valid_member_type<tti::member_type_BType<AType> >));
  BOOST_MPL_ASSERT((tti::mf_valid_member_type<tti::TheInteger<AType::BType> >));
  BOOST_MPL_ASSERT((tti::mf_valid_member_type<tti::member_type_CType<AType::BType> >));
  BOOST_MPL_ASSERT((tti::mf_valid_member_type<tti::member_type_AnotherIntegerType<AType::BType::CType> >));
  BOOST_MPL_ASSERT((tti::mf_valid_member_type<tti::SomethingElse<AnotherType> >));
  
  return 0;

  }
