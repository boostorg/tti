#include "test_has_static_member.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  BOOST_TTI_TRAIT_GEN(TheTIntFunction<AType),void (long,double)> aVar;
  BOOST_TTI_TRAIT_GEN(Pickedname)<AnotherType,AType (long,long)> aVar3;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((BOOST_TTI_TRAIT_GEN(HaveTheSIntFunction)<AType,int (long,double)>));
  BOOST_MPL_ASSERT((BOOST_TTI_TRAIT_GEN(TheTIntFunction)<AnotherType,AType (long,double)>));
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_COMP_STATIC_MEMBER_FUNCTION_GEN(TSFunction)<AnotherType,AType::AStructType (AType::AnIntType,double)>));
  
  return 0;

  }
