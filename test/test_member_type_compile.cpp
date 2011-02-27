#include "test_mem_type.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  BOOST_MPL_ASSERT((boost::tti::mf_valid_member_type<boost::tti::member_type_AnIntType<AType> >));
  BOOST_MPL_ASSERT((boost::tti::mf_valid_member_type<boost::tti::NameStruct<AType> >));
  BOOST_MPL_ASSERT((boost::tti::mf_valid_member_type<boost::tti::member_type_AnIntTypeReference<AType> >));
  BOOST_MPL_ASSERT((boost::tti::mf_valid_member_type<boost::tti::member_type_BType<AType> >));
  BOOST_MPL_ASSERT((boost::tti::mf_valid_member_type<boost::tti::TheInteger<AType::BType> >));
  BOOST_MPL_ASSERT((boost::tti::mf_valid_member_type<boost::tti::member_type_CType<AType::BType> >));
  BOOST_MPL_ASSERT((boost::tti::mf_valid_member_type<boost::tti::member_type_AnotherIntegerType<AType::BType::CType> >));
  BOOST_MPL_ASSERT((boost::tti::mf_valid_member_type<boost::tti::SomethingElse<AnotherType> >));
  
  return 0;

  }
