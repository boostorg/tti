#include "TestMFHasType.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  tti::mf_has_type
    <
    tti::has_type_AnIntType,
    boost::mpl::identity<AnotherType>
    > aVar;
  
  tti::mf_has_type
    <
    tti::has_type_NoOtherType,
    boost::mpl::identity<AnotherType>
    > aVar2;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::has_type_AnIntType,
                      boost::mpl::identity<AType>
                      >
                  ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::NameStruct,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::has_type_AnIntTypeReference,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::has_type_BType,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::TheInteger,
                      tti::member_type_BType<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::has_type_CType,
                      tti::member_type_BType<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::has_type_AnotherIntegerType,
                      tti::mf_member_type
                        <
                        tti::member_type_CType,
                        tti::member_type_BType<AType>
                        >
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::SomethingElse,
                      boost::mpl::identity<AnotherType>
                      >
                  ));
            
  return 0;

  }
