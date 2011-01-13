#include "TestMFMemberType.hpp"
#include <boost/mpl/assert.hpp>
#include <boost/mpl/bool.hpp>

int main()
  {
  
  BOOST_MPL_ASSERT((boost::mpl::bool_
                      <
                      tti::mf_member_type
                        <
                        tti::member_type_AnIntType,
                        boost::mpl::identity<AType>
                        >
                      ::valid
                      >
                  ));
            
  BOOST_MPL_ASSERT((boost::mpl::bool_
                      <
                      tti::mf_member_type
                        <
                        tti::NameStruct,
                        boost::mpl::identity<AType>
                        >
                      ::valid
                      >
                  ));
            
  BOOST_MPL_ASSERT((boost::mpl::bool_
                      <
                      tti::mf_member_type
                        <
                        tti::member_type_AnIntTypeReference,
                        boost::mpl::identity<AType>
                        >
                      ::valid
                      >
                  ));
            
  BOOST_MPL_ASSERT((boost::mpl::bool_
                      <
                      tti::mf_member_type
                        <
                        tti::member_type_BType,
                        boost::mpl::identity<AType>
                        >
                      ::valid
                      >
                  ));
            
  BOOST_MPL_ASSERT((boost::mpl::bool_
                      <
                      tti::mf_member_type
                        <
                        tti::TheInteger,
                        tti::member_type_BType<AType>
                        >
                      ::valid
                      >
                  ));
            
  BOOST_MPL_ASSERT((boost::mpl::bool_
                      <
                      tti::mf_member_type
                        <
                        tti::member_type_CType,
                        tti::member_type_BType<AType>
                        >
                      ::valid
                      >
                  ));
            
  BOOST_MPL_ASSERT((boost::mpl::bool_
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
                      ::valid
                      >
                  ));
            
  BOOST_MPL_ASSERT((boost::mpl::bool_
                      <
                      tti::mf_member_type
                        <
                        tti::SomethingElse,
                        boost::mpl::identity<AnotherType>
                        >
                      ::valid
                      >
                  ));
  
  return 0;

  }
