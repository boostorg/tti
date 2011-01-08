#include "TestHasMember.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  tti::has_member_aMember<long AType::*> aVar;
  tti::has_member_someDataMember<double AnotherType::*> aVar2;
  tti::has_member_someFunctionMember<double (AnotherType::*)(short,short,long,int)> aVar3;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((tti::has_member_AnInt<int AType::*>));
  BOOST_MPL_ASSERT((tti::has_member_AnInt<long AnotherType::*>));
  BOOST_MPL_ASSERT((tti::has_member_VoidFunction<void (AType::*)()>));
  BOOST_MPL_ASSERT((tti::FunctionReturningInt<int (AType::*)()>));
  BOOST_MPL_ASSERT((tti::FunctionReturningInt<double (AnotherType::*)(int)>));
  BOOST_MPL_ASSERT((tti::has_member_aFunction<AType (AnotherType::*)(int)>));
  BOOST_MPL_ASSERT((tti::AnotherIntFunction<int (AnotherType::*)(AType)>));
  BOOST_MPL_ASSERT((tti::has_member_sFunction<AType::AnIntType (AnotherType::*)(int,long,double)>));
  BOOST_MPL_ASSERT((tti::has_member_aMember<bool AnotherType::*>));
  BOOST_MPL_ASSERT((tti::CMember<bool AnotherType::*>));
  BOOST_MPL_ASSERT((tti::has_member_IntBT<AType::BType AType::*>));
  BOOST_MPL_ASSERT((tti::NestedData<AType::BType::CType AType::*>));
  BOOST_MPL_ASSERT((tti::AOther<AType AnotherType::*>));
  BOOST_MPL_ASSERT((tti::has_member_ONestStr<AType::AStructType AnotherType::*>));
  
  return 0;

  }
