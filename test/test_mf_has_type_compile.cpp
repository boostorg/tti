#include "test_mf_has_type.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // You can always instantiate without compiler errors
  
  boost::tti::mf_has_type
    <
    boost::tti::mtfc_has_type_AnIntType,
    boost::mpl::identity<AnotherType>
    > aVar;
  
  boost::tti::mf_has_type
    <
    boost::tti::has_type_NoOtherType<_>,
    boost::mpl::identity<AnotherType>
    > aVar2;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      boost::tti::has_type_AnIntType<_>,
                      boost::mpl::identity<AType>
                      >
                  ));
            
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      boost::tti::NameStruct<_>,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      boost::tti::has_type_AnIntTypeReference<_>,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      boost::tti::has_type_BType<_>,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      boost::tti::TheInteger<_>,
                      boost::tti::member_type_BType<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      boost::tti::has_type_CType<_>,
                      boost::tti::member_type_BType<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      boost::tti::has_type_AnotherIntegerType<_>,
                      boost::tti::mf_member_type
                        <
                        boost::tti::member_type_CType<_>,
                        boost::tti::member_type_BType<AType>
                        >
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      boost::tti::SomethingElse<_>,
                      boost::mpl::identity<AnotherType>
                      >
                  ));
            
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      boost::tti::mtfc_has_type_AnIntType,
                      boost::mpl::identity<AType>
                      >
                  ));
            
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      boost::tti::MetaFNameStruct,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      boost::tti::mtfc_has_type_AnIntTypeReference,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      boost::tti::mtfc_has_type_BType,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      boost::tti::MClassTheInteger,
                      boost::tti::member_type_BType<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      boost::tti::mtfc_has_type_CType,
                      boost::tti::member_type_BType<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      boost::tti::mtfc_has_type_AnotherIntegerType,
                      boost::tti::mf_member_type
                        <
                        boost::tti::member_type_CType<_>,
                        boost::tti::member_type_BType<AType>
                        >
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      boost::tti::MTFCSomethingElse,
                      boost::mpl::identity<AnotherType>
                      >
                  ));
            
  return 0;

  }
