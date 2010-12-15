#include "TestHasType.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  tti::has_type_AnIntType<AnotherType> aVar1;
  tti::has_type_NoOtherType<AType> aVar2;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((tti::has_type_AnIntType<AType>));
  BOOST_MPL_ASSERT((tti::has_type_AnIntTypeReference<AType>));
  BOOST_MPL_ASSERT((tti::NameStruct<AType>));
  BOOST_MPL_ASSERT((tti::has_type_BType<AType>));
  BOOST_MPL_ASSERT((tti::TheInteger<AType::BType>));
  BOOST_MPL_ASSERT((tti::has_type_CType<AType::BType>));
  BOOST_MPL_ASSERT((tti::has_type_AnotherIntegerType<AType::BType::CType>));
  BOOST_MPL_ASSERT((tti::SomethingElse<AnotherType>));
  
  return 0;

  }
