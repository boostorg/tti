#include "TestHasMember.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  BOOST_MPL_ASSERT((tti::has_member_AnInt<int AType::*>));
  BOOST_MPL_ASSERT((tti::has_member_AnInt<long AnotherType::*>));
  BOOST_MPL_ASSERT((tti::has_member_VoidFunction<void (AType::*)()>));
  BOOST_MPL_ASSERT((tti::has_member_IntFunction<int (AType::*)()>));
  BOOST_MPL_ASSERT((tti::has_member_IntFunction<double (AnotherType::*)(int)>));
  BOOST_MPL_ASSERT((tti::has_member_aFunction<AType (AnotherType::*)(int)>));
  BOOST_MPL_ASSERT((tti::has_member_anotherFunction<int (AnotherType::*)(AType)>));
  BOOST_MPL_ASSERT((tti::has_member_sFunction<AType::AnIntType (AnotherType::*)(int,long,double)>));
  BOOST_MPL_ASSERT((tti::has_member_aMember<bool AnotherType::*>));
  BOOST_MPL_ASSERT((tti::has_member_cMem<bool AnotherType::*>));
  
  return 0;

  }
