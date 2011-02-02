#include "TestHasMemberFunction.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  tti::has_member_function_someFunctionMember<AnotherType,double,boost::mpl::vector<short,short,long,int> > aVar3;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((tti::has_member_function_VoidFunction<AType,void>));
  BOOST_MPL_ASSERT((tti::FunctionReturningInt<AType,int>));
  BOOST_MPL_ASSERT((tti::FunctionReturningInt<AnotherType,double,boost::mpl::vector<int> >));
  BOOST_MPL_ASSERT((tti::has_member_function_aFunction<AnotherType,AType,boost::mpl::vector<int> >));
  BOOST_MPL_ASSERT((tti::AnotherIntFunction<AnotherType,int,boost::mpl::vector<AType> >));
  BOOST_MPL_ASSERT((tti::has_member_function_sFunction<AnotherType,AType::AnIntType,boost::mpl::vector<int,long,double> >));
  
  return 0;

  }
