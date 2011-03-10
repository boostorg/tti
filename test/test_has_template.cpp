#include "test_has_template.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST(BOOST_TTI_HAS_TEMPLATE_GEN(ATPMemberTemplate)<AType>::value);
  BOOST_TEST(BOOST_TTI_TRAIT_GEN(HaveCL)<AType>::value);
  BOOST_TEST(!BOOST_TTI_HAS_TEMPLATE_GEN(AMemberTemplate)<AType>::value);
  BOOST_TEST(!BOOST_TTI_TRAIT_GEN(HaveAnotherMT)<AType>::value);
  BOOST_TEST(!BOOST_TTI_HAS_TEMPLATE_GEN(SomeMemberTemplate)<AnotherType>::value);
  BOOST_TEST(!BOOST_TTI_TRAIT_GEN(ATemplateWithParms)<AnotherType>::value);
  BOOST_TEST(BOOST_TTI_HAS_TEMPLATE_GEN(SimpleTMP)<AnotherType>::value);

  return boost::report_errors();
  
  }
