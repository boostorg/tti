#include "test_mf_has_type_check_typedef.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // You can always instantiate without compiler errors
  
  boost::tti::mf_has_type
    <
    boost::tti::TheInteger<_,_>,
    boost::tti::member_type_BType<AnotherType>,
    boost::mpl::identity<long>
    > aVar;
    
  boost::tti::mf_has_type
    <
    boost::tti::mtfc_has_type_NoOtherType,
    boost::mpl::identity<AType>,
    boost::mpl::identity<float>
    > aVar2;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                <
                boost::tti::has_type_AnIntType<_,_>,
                boost::mpl::identity<AType>,
                boost::mpl::identity<int>
                >
            ));
            
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                <
                boost::tti::NameStruct<_,_>,
                boost::mpl::identity<AType>,
                boost::tti::member_type_AStructType<AType>
                >
            ));
            
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                <
                boost::tti::has_type_AnIntTypeReference<_,_>,
                boost::mpl::identity<AType>,
                boost::mpl::identity<int &>
                >
            ));
            
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                <
                boost::tti::has_type_BType<_,_>,
                boost::mpl::identity<AType>,
                boost::tti::member_type_BType<AType>
                >
            ));
            
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                <
                boost::tti::TheInteger<_,_>,
                boost::tti::member_type_BType<AType>,
                boost::mpl::identity<int>
                >
            ));
            
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                <
                boost::tti::has_type_CType<_,_>,
                boost::tti::member_type_BType<AType>,
                boost::tti::mf_member_type
                  <
                  boost::tti::member_type_CType<_>,
                  boost::tti::member_type_BType<AType>
                  >
                >
            ));
            
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                <
                boost::tti::has_type_AnotherIntegerType<_,_>,
                boost::tti::mf_member_type
                  <
                  boost::tti::member_type_CType<_>,
                  boost::tti::member_type_BType<AType>
                  >,
                boost::mpl::identity<int>
                >
            ));
            
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                <
                boost::tti::SomethingElse<_,_>,
                boost::mpl::identity<AnotherType>,
                boost::tti::member_type_AnIntType<AType>
                >
            ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                <
                boost::tti::mtfc_has_type_AnIntType,
                boost::mpl::identity<AType>,
                boost::mpl::identity<int>
                >
            ));
            
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                <
                boost::tti::MFunctionNameStruct,
                boost::mpl::identity<AType>,
                boost::tti::member_type_AStructType<AType>
                >
            ));
            
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                <
                boost::tti::mtfc_has_type_AnIntTypeReference,
                boost::mpl::identity<AType>,
                boost::mpl::identity<int &>
                >
            ));
            
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                <
                boost::tti::mtfc_has_type_BType,
                boost::mpl::identity<AType>,
                boost::tti::member_type_BType<AType>
                >
            ));
            
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                <
                boost::tti::MFCTheInteger,
                boost::tti::member_type_BType<AType>,
                boost::mpl::identity<int>
                >
            ));
            
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                <
                boost::tti::mtfc_has_type_CType,
                boost::tti::member_type_BType<AType>,
                boost::tti::mf_member_type
                  <
                  boost::tti::member_type_CType<_>,
                  boost::tti::member_type_BType<AType>
                  >
                >
            ));
            
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                <
                boost::tti::mtfc_has_type_AnotherIntegerType,
                boost::tti::mf_member_type
                  <
                  boost::tti::mtfc_member_type_CType,
                  boost::tti::member_type_BType<AType>
                  >,
                boost::mpl::identity<int>
                >
            ));
            
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                <
                boost::tti::FClassSomethingElse,
                boost::mpl::identity<AnotherType>,
                boost::tti::member_type_AnIntType<AType>
                >
            ));
  
  return 0;

  }
