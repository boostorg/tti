#include "test_has_member.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  boost::tti::has_comp_member_function_someFunctionMember<double (AnotherType::*)(short,short,long,int)> aVar3;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((boost::tti::has_comp_member_function_VoidFunction<void (AType::*)()>));
  BOOST_MPL_ASSERT((boost::tti::FunctionReturningInt<int (AType::*)()>));
  BOOST_MPL_ASSERT((boost::tti::FunctionReturningInt<double (AnotherType::*)(int)>));
  BOOST_MPL_ASSERT((boost::tti::has_comp_member_function_aFunction<AType (AnotherType::*)(int)>));
  BOOST_MPL_ASSERT((boost::tti::AnotherIntFunction<int (AnotherType::*)(AType)>));
  BOOST_MPL_ASSERT((boost::tti::has_comp_member_function_sFunction<AType::AnIntType (AnotherType::*)(int,long,double)>));
  
  return 0;

  }
