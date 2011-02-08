#include "TestMFMemberType.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  BOOST_MPL_ASSERT((tti::mf_valid_member_type
                      <
                      tti::mf_member_type
                        <
                        tti::member_type_AnIntType<_>,
                        boost::mpl::identity<AType>
                        >
                      >
                  ));
            
  BOOST_MPL_ASSERT((tti::mf_valid_member_type
                      <
                      tti::mf_member_type
                        <
                        tti::NameStruct<_>,
                        boost::mpl::identity<AType>
                        >
                      >
                  ));
            
  BOOST_MPL_ASSERT((tti::mf_valid_member_type
                      <
                      tti::mf_member_type
                        <
                        tti::member_type_AnIntTypeReference<_>,
                        boost::mpl::identity<AType>
                        >
                      >
                  ));
            
  BOOST_MPL_ASSERT((tti::mf_valid_member_type
                      <
                      tti::mf_member_type
                        <
                        tti::member_type_BType<_>,
                        boost::mpl::identity<AType>
                        >
                      >
                  ));
            
  BOOST_MPL_ASSERT((tti::mf_valid_member_type
                      <
                      tti::mf_member_type
                        <
                        tti::TheInteger<_>,
                        tti::member_type_BType<AType>
                        >
                      >
                  ));
            
  BOOST_MPL_ASSERT((tti::mf_valid_member_type
                      <
                      tti::mf_member_type
                        <
                        tti::member_type_CType<_>,
                        tti::member_type_BType<AType>
                        >
                      >
                  ));
            
  BOOST_MPL_ASSERT((tti::mf_valid_member_type
                      <
                      tti::mf_member_type
                        <
                        tti::member_type_AnotherIntegerType<_>,
                        tti::mf_member_type
                          <
                          tti::member_type_CType<_>,
                          tti::member_type_BType<AType>
                          >
                        >
                      >
                  ));
            
  BOOST_MPL_ASSERT((tti::mf_valid_member_type
                      <
                      tti::mf_member_type
                        <
                        tti::SomethingElse<_>,
                        boost::mpl::identity<AnotherType>
                        >
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_valid_member_type
                      <
                      tti::mf_member_type
                        <
                        tti::mtfc_member_type_AnIntType,
                        boost::mpl::identity<AType>
                        >
                      >
                  ));
            
  BOOST_MPL_ASSERT((tti::mf_valid_member_type
                      <
                      tti::mf_member_type
                        <
                        tti::MFNameStruct,
                        boost::mpl::identity<AType>
                        >
                      >
                  ));
            
  BOOST_MPL_ASSERT((tti::mf_valid_member_type
                      <
                      tti::mf_member_type
                        <
                        tti::mtfc_member_type_AnIntTypeReference,
                        boost::mpl::identity<AType>
                        >
                      >
                  ));
            
  BOOST_MPL_ASSERT((tti::mf_valid_member_type
                      <
                      tti::mf_member_type
                        <
                        tti::mtfc_member_type_BType,
                        boost::mpl::identity<AType>
                        >
                      >
                  ));
            
  BOOST_MPL_ASSERT((tti::mf_valid_member_type
                      <
                      tti::mf_member_type
                        <
                        tti::MFTheInteger,
                        tti::member_type_BType<AType>
                        >
                      >
                  ));
            
  BOOST_MPL_ASSERT((tti::mf_valid_member_type
                      <
                      tti::mf_member_type
                        <
                        tti::mtfc_member_type_CType,
                        tti::member_type_BType<AType>
                        >
                      >
                  ));
            
  BOOST_MPL_ASSERT((tti::mf_valid_member_type
                      <
                      tti::mf_member_type
                        <
                        tti::mtfc_member_type_AnotherIntegerType,
                        tti::mf_member_type
                          <
                          tti::mtfc_member_type_CType,
                          tti::member_type_BType<AType>
                          >
                        >
                      >
                  ));
            
  BOOST_MPL_ASSERT((tti::mf_valid_member_type
                      <
                      tti::mf_member_type
                        <
                        tti::MetaClSomethingElse,
                        boost::mpl::identity<AnotherType>
                        >
                      >
                  ));
  
  return 0;

  }
