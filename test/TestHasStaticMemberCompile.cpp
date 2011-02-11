#include "test_has_static_member.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  tti::TheTIntFunction<AType,void (long,double)> aVar;
  tti::has_static_member_SomeStaticData<AnotherType,long> aVar2;
  tti::Pickedname<AnotherType,AType (long,long)> aVar3;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((tti::has_static_member_DSMember<AType,short>));
  BOOST_MPL_ASSERT((tti::HaveTheSIntFunction<AType,int (long,double)>));
  BOOST_MPL_ASSERT((tti::TheTIntFunction<AnotherType,AType (long,double)>));
  BOOST_MPL_ASSERT((tti::has_static_member_TSFunction<AnotherType,AType::AStructType (AType::AnIntType,double)>));
  
  return 0;

  }
