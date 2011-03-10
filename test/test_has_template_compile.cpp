#include "test_has_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  BOOST_TTI_HAS_TEMPLATE_GEN(AMemberTemplate)<AnotherType> aVar;
  BOOST_TTI_TRAIT_GEN(HaveAnotherMT)<AnotherType> aVar2;
  BOOST_TTI_HAS_TEMPLATE_GEN(SomeMemberTemplate)<AType> aVar3;
  BOOST_TTI_HAS_TEMPLATE_GEN(TemplateNotExist)<AType> aVar4;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_TEMPLATE_GEN(ATPMemberTemplate)<AType>));
  BOOST_MPL_ASSERT((BOOST_TTI_TRAIT_GEN(HaveCL)<AType>));
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_TEMPLATE_GEN(SimpleTMP)<AnotherType>));
  
  return 0;

  }
