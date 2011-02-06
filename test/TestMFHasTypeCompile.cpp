#include "TestMFHasType.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // You can always instantiate without compiler errors
  
  tti::mf_has_type
    <
    tti::has_type_AnIntType<_>,
    boost::mpl::identity<AnotherType>
    > aVar;
  
  tti::mf_has_type
    <
    tti::has_type_NoOtherType<_>,
    boost::mpl::identity<AnotherType>
    > aVar2;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::has_type_AnIntType<_>,
                      boost::mpl::identity<AType>
                      >
                  ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::NameStruct<_>,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::has_type_AnIntTypeReference<_>,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::has_type_BType<_>,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::TheInteger<_>,
                      tti::member_type_BType<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::has_type_CType<_>,
                      tti::member_type_BType<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::has_type_AnotherIntegerType<_>,
                      tti::mf_member_type
                        <
                        tti::member_type_CType<_>,
                        tti::member_type_BType<AType>
                        >
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::SomethingElse<_>,
                      boost::mpl::identity<AnotherType>
                      >
                  ));
            
  return 0;

  }
