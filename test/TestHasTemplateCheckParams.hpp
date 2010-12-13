#if !defined(TEST_HAS_TEMPLATE_CHECK_PARAMS_HPP)
#define TEST_HAS_TEMPLATE_CHECK_PARAMS_HPP

#include "TestStructs.hpp"
#include <boost/tti/TTIntrospection.hpp>

TTI_HAS_TEMPLATE_CHECK_PARAMS(ATPMemberTemplate,(class))
TTI_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(HaveCL,CLMemberTemplate,(class)(class))
TTI_HAS_TEMPLATE_CHECK_PARAMS(AMemberTemplate,(int))
TTI_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(HaveAnotherMT,AnotherMemberTemplate,(int)(int))
TTI_HAS_TEMPLATE_CHECK_PARAMS(SomeMemberTemplate,(class)(class)(class)(class)(class)(class))
TTI_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(ATemplateWithParms,ManyParameters,(class)(class)(int)(class)(template <class> class InnerTemplate)(class)(long))
TTI_HAS_TEMPLATE_CHECK_PARAMS(SimpleTMP,(class)(class)(class)(class))
TTI_HAS_TEMPLATE_CHECK_PARAMS(TemplateNotExist,(int)(class)(template <class> class ATemplate))
TTI_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(WrongParametersForMP,ManyParameters,(class)(class)(int)(class)(template <class)(class> class InnerTemplate)(class)(long))
TTI_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(WrongParameters2ForMP,ManyParameters,(class)(long)(int)(class)(template <class> class InnerTemplate)(class)(long))

#endif // TEST_HAS_TEMPLATE_CHECK_PARAMS_HPP
