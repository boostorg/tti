#include "test_has_type.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  BOOST_TTI_HAS_TYPE_GEN(AnIntType)<AnotherType> aVar1;
  BOOST_TTI_HAS_TYPE_GEN(NoOtherType)<AType> aVar2;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_TYPE_GEN(AnIntType)<AType>));
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_TYPE_GEN(AnIntTypeReference)<AType>));
  BOOST_MPL_ASSERT((BOOST_TTI_TRAIT_GEN(NameStruct)<AType>));
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_TYPE_GEN(BType)<AType>));
  BOOST_MPL_ASSERT((BOOST_TTI_TRAIT_GEN(TheInteger)<AType::BType>));
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_TYPE_GEN(CType)<AType::BType>));
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_TYPE_GEN(AnotherIntegerType)<AType::BType::CType>));
  BOOST_MPL_ASSERT((BOOST_TTI_TRAIT_GEN(SomethingElse)<AnotherType>));
  
  return 0;

  }
