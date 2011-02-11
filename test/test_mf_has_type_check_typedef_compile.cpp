#include "test_mf_has_type_check_typedef.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // You can always instantiate without compiler errors
  
  tti::mf_has_type
    <
    tti::TheInteger<_,_>,
    tti::member_type_BType<AnotherType>,
    boost::mpl::identity<long>
    > aVar;
    
  tti::mf_has_type
    <
    tti::mtfc_has_type_NoOtherType,
    boost::mpl::identity<AType>,
    boost::mpl::identity<float>
    > aVar2;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                <
                tti::has_type_AnIntType<_,_>,
                boost::mpl::identity<AType>,
                boost::mpl::identity<int>
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type
                <
                tti::NameStruct<_,_>,
                boost::mpl::identity<AType>,
                tti::member_type_AStructType<AType>
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type
                <
                tti::has_type_AnIntTypeReference<_,_>,
                boost::mpl::identity<AType>,
                boost::mpl::identity<int &>
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type
                <
                tti::has_type_BType<_,_>,
                boost::mpl::identity<AType>,
                tti::member_type_BType<AType>
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type
                <
                tti::TheInteger<_,_>,
                tti::member_type_BType<AType>,
                boost::mpl::identity<int>
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type
                <
                tti::has_type_CType<_,_>,
                tti::member_type_BType<AType>,
                tti::mf_member_type
                  <
                  tti::member_type_CType<_>,
                  tti::member_type_BType<AType>
                  >
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type
                <
                tti::has_type_AnotherIntegerType<_,_>,
                tti::mf_member_type
                  <
                  tti::member_type_CType<_>,
                  tti::member_type_BType<AType>
                  >,
                boost::mpl::identity<int>
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type
                <
                tti::SomethingElse<_,_>,
                boost::mpl::identity<AnotherType>,
                tti::member_type_AnIntType<AType>
                >
            ));
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                <
                tti::mtfc_has_type_AnIntType,
                boost::mpl::identity<AType>,
                boost::mpl::identity<int>
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type
                <
                tti::MFunctionNameStruct,
                boost::mpl::identity<AType>,
                tti::member_type_AStructType<AType>
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type
                <
                tti::mtfc_has_type_AnIntTypeReference,
                boost::mpl::identity<AType>,
                boost::mpl::identity<int &>
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type
                <
                tti::mtfc_has_type_BType,
                boost::mpl::identity<AType>,
                tti::member_type_BType<AType>
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type
                <
                tti::MFCTheInteger,
                tti::member_type_BType<AType>,
                boost::mpl::identity<int>
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type
                <
                tti::mtfc_has_type_CType,
                tti::member_type_BType<AType>,
                tti::mf_member_type
                  <
                  tti::member_type_CType<_>,
                  tti::member_type_BType<AType>
                  >
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type
                <
                tti::mtfc_has_type_AnotherIntegerType,
                tti::mf_member_type
                  <
                  tti::mtfc_member_type_CType,
                  tti::member_type_BType<AType>
                  >,
                boost::mpl::identity<int>
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type
                <
                tti::FClassSomethingElse,
                boost::mpl::identity<AnotherType>,
                tti::member_type_AnIntType<AType>
                >
            ));
  
  return 0;

  }
