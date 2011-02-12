#include "test_has_member.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST(boost::tti::has_member_AnInt<int AType::*>::value);
  BOOST_TEST(boost::tti::has_member_AnInt<long AnotherType::*>::value);
  BOOST_TEST(boost::tti::has_member_VoidFunction<void (AType::*)()>::value);
  BOOST_TEST(boost::tti::FunctionReturningInt<int (AType::*)()>::value);
  BOOST_TEST(boost::tti::FunctionReturningInt<double (AnotherType::*)(int)>::value);
  BOOST_TEST(boost::tti::has_member_aFunction<AType (AnotherType::*)(int)>::value);
  BOOST_TEST(boost::tti::AnotherIntFunction<int (AnotherType::*)(AType)>::value);
  BOOST_TEST(boost::tti::has_member_sFunction<AType::AnIntType (AnotherType::*)(int,long,double)>::value);
  BOOST_TEST(boost::tti::has_member_aMember<bool AnotherType::*>::value);
  BOOST_TEST(!boost::tti::has_member_aMember<int AnotherType::*>::value);
  BOOST_TEST(boost::tti::CMember<bool AnotherType::*>::value);
  BOOST_TEST(!boost::tti::has_member_someDataMember<short AType::*>::value);
  BOOST_TEST(!boost::tti::has_member_someFunctionMember<AType (AnotherType::*)(long,int)>::value);
  BOOST_TEST(boost::tti::has_member_IntBT<AType::BType AType::*>::value);
  BOOST_TEST(boost::tti::NestedData<AType::BType::CType AType::*>::value);
  BOOST_TEST(boost::tti::AOther<AType AnotherType::*>::value);
  BOOST_TEST(boost::tti::has_member_ONestStr<AType::AStructType AnotherType::*>::value);
  
  return boost::report_errors();

  }
