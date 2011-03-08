#include "test_has_member.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST(boost::tti::has_comp_member_function_VoidFunction<void (AType::*)()>::value);
  BOOST_TEST(boost::tti::FunctionReturningInt<int (AType::*)()>::value);
  BOOST_TEST(boost::tti::FunctionReturningInt<double (AnotherType::*)(int)>::value);
  BOOST_TEST(boost::tti::has_comp_member_function_aFunction<AType (AnotherType::*)(int)>::value);
  BOOST_TEST(boost::tti::AnotherIntFunction<int (AnotherType::*)(AType)>::value);
  BOOST_TEST(boost::tti::has_comp_member_function_sFunction<AType::AnIntType (AnotherType::*)(int,long,double)>::value);
  BOOST_TEST(!boost::tti::has_comp_member_function_someFunctionMember<AType (AnotherType::*)(long,int)>::value);
  
  return boost::report_errors();

  }
