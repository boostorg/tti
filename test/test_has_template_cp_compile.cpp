#include "test_has_template_cp.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  BOOST_TTI_HAS_TEMPLATE_CHECK_PARAMS_GEN(TemplateNotExist)<AnotherType> aVar1;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_TEMPLATE_CHECK_PARAMS_GEN(ATPMemberTemplate)<AType>));
  BOOST_MPL_ASSERT((BOOST_TTI_TRAIT_GEN(HaveCL)<AType>));
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_TEMPLATE_CHECK_PARAMS_GEN(AMemberTemplate)<AType>));
  BOOST_MPL_ASSERT((BOOST_TTI_TRAIT_GEN(HaveAnotherMT)<AType>));
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_TEMPLATE_CHECK_PARAMS_GEN(SomeMemberTemplate)<AnotherType>));
  BOOST_MPL_ASSERT((BOOST_TTI_TRAIT_GEN(ATemplateWithParms)<AnotherType>));
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_TEMPLATE_CHECK_PARAMS_GEN(SimpleTMP)<AnotherType>));
  
  return 0;

  }
