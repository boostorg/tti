#include "test_mf_has_member_function.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // You can always instantiate without compiler errors
  
  tti::mf_has_member_function
    <
    tti::FunctionReturningInt<_,_>,
    boost::mpl::identity<AnotherType>,
    boost::mpl::identity<short>
    > aVar;
  
  tti::mf_has_member_function
    <
    tti::has_member_function_sFunction<_,_,_>,
    boost::mpl::identity<AnotherType>,
    tti::member_type_AnIntType<AnotherType>,
    boost::mpl::vector
      <
      boost::mpl::identity<int>,
      boost::mpl::identity<long>,
      boost::mpl::identity<double>
      >
    > aVar2;
                      
  tti::mf_has_member_function
    <
    tti::has_member_function_someFunctionMember<_,_,_>,
    boost::mpl::identity<AnotherType>,
    boost::mpl::identity<short>,
    boost::mpl::vector
      <
      boost::mpl::identity<double>,
      boost::mpl::identity<int>,
      boost::mpl::identity<long>
      >
    > aVar3;
    
  // Compile time asserts
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::has_member_function_VoidFunction<_,_>,
                      boost::mpl::identity<AType>,
                      boost::mpl::identity<void>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::FunctionReturningInt<_,_>,
                      boost::mpl::identity<AType>,
                      boost::mpl::identity<int>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::FunctionReturningInt<_,_,_>,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<double>,
                      boost::mpl::vector<boost::mpl::identity<int> >
                      >
                  ));
                  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::has_member_function_aFunction<_,_,_>,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<AType>,
                      boost::mpl::vector<boost::mpl::identity<int> >
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::AnotherIntFunction<_,_,_>,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<int>,
                      boost::mpl::vector<boost::mpl::identity<AType> >
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::has_member_function_sFunction<_,_,_>,
                      boost::mpl::identity<AnotherType>,
                      tti::member_type_AnIntType<AType>,
                      boost::mpl::vector
                        <
                        boost::mpl::identity<int>,
                        boost::mpl::identity<long>,
                        boost::mpl::identity<double>
                        >
                      >
                  ));
            
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::mtfc_has_member_function_VoidFunction,
                      boost::mpl::identity<AType>,
                      boost::mpl::identity<void>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::MFFunctionReturningInt,
                      boost::mpl::identity<AType>,
                      boost::mpl::identity<int>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::MFFunctionReturningInt,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<double>,
                      boost::mpl::vector<boost::mpl::identity<int> >
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::mtfc_has_member_function_aFunction,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<AType>,
                      boost::mpl::vector<boost::mpl::identity<int> >
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::MFAnotherIntFunction,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<int>,
                      boost::mpl::vector<boost::mpl::identity<AType> >
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::mtfc_has_member_function_sFunction,
                      boost::mpl::identity<AnotherType>,
                      tti::member_type_AnIntType<AType>,
                      boost::mpl::vector
                        <
                        boost::mpl::identity<int>,
                        boost::mpl::identity<long>,
                        boost::mpl::identity<double> 
                        >
                      >
                  ));
  
  return 0;

  }
