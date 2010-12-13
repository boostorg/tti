#if !defined(TEST_HAS_TEMPLATE_HPP)
#define TEST_HAS_TEMPLATE_HPP

#include "TestStructs.hpp"
#include <boost/tti/TTIntrospection.hpp>

TTI_HAS_TEMPLATE(ATPMemberTemplate)
TTI_TRAIT_HAS_TEMPLATE(HaveCL,CLMemberTemplate)
TTI_HAS_TEMPLATE(AMemberTemplate)
TTI_TRAIT_HAS_TEMPLATE(HaveAnotherMT,AnotherMemberTemplate)
TTI_HAS_TEMPLATE(SomeMemberTemplate)
TTI_TRAIT_HAS_TEMPLATE(ATemplateWithParms,ManyParameters)
TTI_HAS_TEMPLATE(SimpleTMP)
TTI_HAS_TEMPLATE(TemplateNotExist)

#endif // TEST_HAS_TEMPLATE_HPP
