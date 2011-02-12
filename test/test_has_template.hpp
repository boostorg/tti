#if !defined(TEST_HAS_TEMPLATE_HPP)
#define TEST_HAS_TEMPLATE_HPP

#include "test_structs.hpp"
#include <boost/tti/tti.hpp>

BOOST_TTI_HAS_TEMPLATE(ATPMemberTemplate)
BOOST_TTI_TRAIT_HAS_TEMPLATE(HaveCL,CLMemberTemplate)
BOOST_TTI_HAS_TEMPLATE(AMemberTemplate)
BOOST_TTI_TRAIT_HAS_TEMPLATE(HaveAnotherMT,AnotherMemberTemplate)
BOOST_TTI_HAS_TEMPLATE(SomeMemberTemplate)
BOOST_TTI_TRAIT_HAS_TEMPLATE(ATemplateWithParms,ManyParameters)
BOOST_TTI_HAS_TEMPLATE(SimpleTMP)
BOOST_TTI_HAS_TEMPLATE(TemplateNotExist)

#endif // TEST_HAS_TEMPLATE_HPP
