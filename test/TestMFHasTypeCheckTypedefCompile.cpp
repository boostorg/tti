#include "TestMFHasTypeCheckTypedef.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  tti::mf_has_type_check_typedef
    <
    tti::TheInteger,
    tti::member_type_BType<AnotherType>,
    boost::mpl::identity<long>
    > aVar;
    
  tti::mf_has_type_check_typedef
    <
    tti::has_type_check_typedef_NoOtherType,
    boost::mpl::identity<AType>,
    boost::mpl::identity<float>
    > aVar2;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((tti::mf_has_type_check_typedef
                <
                tti::has_type_check_typedef_AnIntType,
                boost::mpl::identity<AType>,
                boost::mpl::identity<int>
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type_check_typedef
                <
                tti::NameStruct,
                boost::mpl::identity<AType>,
                tti::member_type_AStructType<AType>
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type_check_typedef
                <
                tti::has_type_check_typedef_AnIntTypeReference,
                boost::mpl::identity<AType>,
                boost::mpl::identity<int &>
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type_check_typedef
                <
                tti::has_type_check_typedef_BType,
                boost::mpl::identity<AType>,
                tti::member_type_BType<AType>
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type_check_typedef
                <
                tti::TheInteger,
                tti::member_type_BType<AType>,
                boost::mpl::identity<int>
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type_check_typedef
                <
                tti::has_type_check_typedef_CType,
                tti::member_type_BType<AType>,
                tti::mf_member_type
                  <
                  tti::member_type_CType,
                  tti::member_type_BType<AType>
                  >
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type_check_typedef
                <
                tti::has_type_check_typedef_AnotherIntegerType,
                tti::mf_member_type
                  <
                  tti::member_type_CType,
                  tti::member_type_BType<AType>
                  >,
                boost::mpl::identity<int>
                >
            ));
            
  BOOST_MPL_ASSERT((tti::mf_has_type_check_typedef
                <
                tti::SomethingElse,
                boost::mpl::identity<AnotherType>,
                tti::member_type_AnIntType<AType>
                >
            ));
  
  return 0;

  }
