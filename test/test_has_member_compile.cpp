#include "test_has_member.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  boost::tti::has_member_aMember<long AType::*> aVar;
  boost::tti::has_member_someDataMember<double AnotherType::*> aVar2;
  boost::tti::has_member_someFunctionMember<double (AnotherType::*)(short,short,long,int)> aVar3;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((boost::tti::has_member_AnInt<int AType::*>));
  BOOST_MPL_ASSERT((boost::tti::has_member_AnInt<long AnotherType::*>));
  BOOST_MPL_ASSERT((boost::tti::has_member_VoidFunction<void (AType::*)()>));
  BOOST_MPL_ASSERT((boost::tti::FunctionReturningInt<int (AType::*)()>));
  BOOST_MPL_ASSERT((boost::tti::FunctionReturningInt<double (AnotherType::*)(int)>));
  BOOST_MPL_ASSERT((boost::tti::has_member_aFunction<AType (AnotherType::*)(int)>));
  BOOST_MPL_ASSERT((boost::tti::AnotherIntFunction<int (AnotherType::*)(AType)>));
  BOOST_MPL_ASSERT((boost::tti::has_member_sFunction<AType::AnIntType (AnotherType::*)(int,long,double)>));
  BOOST_MPL_ASSERT((boost::tti::has_member_aMember<bool AnotherType::*>));
  BOOST_MPL_ASSERT((boost::tti::CMember<bool AnotherType::*>));
  BOOST_MPL_ASSERT((boost::tti::has_member_IntBT<AType::BType AType::*>));
  BOOST_MPL_ASSERT((boost::tti::NestedData<AType::BType::CType AType::*>));
  BOOST_MPL_ASSERT((boost::tti::AOther<AType AnotherType::*>));
  BOOST_MPL_ASSERT((boost::tti::has_member_ONestStr<AType::AStructType AnotherType::*>));
  
  return 0;

  }
