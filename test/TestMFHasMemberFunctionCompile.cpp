#include "TestMFHasMemberFunction.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  tti::mf_has_member_function
    <
    tti::FunctionReturningInt,
    boost::mpl::identity<AnotherType>,
    boost::mpl::identity<short>
    > aVar;
  
  tti::mf_has_member_function
    <
    tti::has_member_sFunction,
    boost::mpl::identity<AnotherType>,
    tti::member_type_AnIntType<AnotherType>,
    boost::mpl::identity<int>,
    boost::mpl::identity<long>,
    boost::mpl::identity<double>
    > aVar2;
                      
  tti::mf_has_member_function
    <
    tti::has_member_someFunctionMember,
    boost::mpl::identity<AnotherType>,
    boost::mpl::identity<short>,
    boost::mpl::identity<double>,
    boost::mpl::identity<int>,
    boost::mpl::identity<long>
    > aVar3;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::has_member_VoidFunction,
                      boost::mpl::identity<AType>,
                      boost::mpl::identity<void>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::FunctionReturningInt,
                      boost::mpl::identity<AType>,
                      boost::mpl::identity<int>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::FunctionReturningInt,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<double>,
                      boost::mpl::identity<int>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::has_member_aFunction,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<AType>,
                      boost::mpl::identity<int>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::AnotherIntFunction,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<int>,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::has_member_sFunction,
                      boost::mpl::identity<AnotherType>,
                      tti::member_type_AnIntType<AType>,
                      boost::mpl::identity<int>,
                      boost::mpl::identity<long>,
                      boost::mpl::identity<double>
                      >
                  ));
            
  return 0;

  }
