#include "TestMFMemberType.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  BOOST_MPL_ASSERT((boost::is_same
                <
                tti::mf_member_type
                  <
                  tti::member_type_AnIntType,
                  boost::mpl::identity<AType>
                  >
                ::type,
                AType::AnIntType
                >
            ));
            
  BOOST_MPL_ASSERT((boost::is_same
                <
                tti::mf_member_type
                  <
                  tti::NameStruct,
                  boost::mpl::identity<AType>
                  >
                ::type,
                AType::AStructType
                >
            ));
            
  BOOST_MPL_ASSERT((boost::is_same
                <
                tti::mf_member_type
                  <
                  tti::member_type_AnIntTypeReference,
                  boost::mpl::identity<AType>
                  >
                ::type,
                AType::AnIntTypeReference
                >
            ));
            
  BOOST_MPL_ASSERT((boost::is_same
                <
                tti::mf_member_type
                  <
                  tti::member_type_BType,
                  boost::mpl::identity<AType>
                  >
                ::type,
                AType::BType
                >
            ));
            
  BOOST_MPL_ASSERT((boost::is_same
                <
                tti::mf_member_type
                  <
                  tti::TheInteger,
                  tti::member_type_BType<AType>
                  >
                ::type,
                AType::BType::AnIntegerType
                >
            ));
            
  BOOST_MPL_ASSERT((boost::is_same
                <
                tti::mf_member_type
                  <
                  tti::member_type_CType,
                  tti::member_type_BType<AType>
                  >
                ::type,
                AType::BType::CType
                >
            ));
            
  BOOST_MPL_ASSERT((boost::is_same
                <
                tti::mf_member_type
                  <
                  tti::member_type_AnotherIntegerType,
                  tti::mf_member_type
                    <
                    tti::member_type_CType,
                    tti::member_type_BType<AType>
                    >
                  >
                ::type,
                AType::BType::CType::AnotherIntegerType
                >
            ));
            
  BOOST_MPL_ASSERT((boost::is_same
                <
                tti::mf_member_type
                  <
                  tti::SomethingElse,
                  boost::mpl::identity<AnotherType>
                  >
                ::type,
                AnotherType::someOtherType
                >
            ));
  
  return 0;

  }
