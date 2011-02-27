#if !defined(TEST_VM_HAS_TEMPLATE_CHECK_PARAMS_HPP)
#define TEST_VM_HAS_TEMPLATE_CHECK_PARAMS_HPP

#if !defined(BOOST_NO_VARIADIC_MACROS)

#include "test_structs.hpp"
#include <boost/tti/vm_template_params.hpp>

BOOST_TTI_VM_HAS_TEMPLATE_CHECK_PARAMS(ATPMemberTemplate,class)
BOOST_TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(HaveCL,CLMemberTemplate,class,class)
BOOST_TTI_VM_HAS_TEMPLATE_CHECK_PARAMS(AMemberTemplate,int)
BOOST_TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(HaveAnotherMT,AnotherMemberTemplate,int,int)
BOOST_TTI_VM_HAS_TEMPLATE_CHECK_PARAMS(SomeMemberTemplate,class,class,class,class,class,class)
BOOST_TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(ATemplateWithParms,ManyParameters,class,class,int,class,template <class> class InnerTemplate,class,long)
BOOST_TTI_VM_HAS_TEMPLATE_CHECK_PARAMS(SimpleTMP,class,class,class,class)
BOOST_TTI_VM_HAS_TEMPLATE_CHECK_PARAMS(TemplateNotExist,int,class,template <class> class ATemplate)
BOOST_TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(WrongParametersForMP,ManyParameters,class,class,int,class,template <class,class> class InnerTemplate,class,long)
BOOST_TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(WrongParameters2ForMP,ManyParameters,class,long,int,class,template <class> class InnerTemplate,class,long)

#endif //!defined(BOOST_NO_VARIADIC_MACROS)

#endif // TEST_VM_HAS_TEMPLATE_CHECK_PARAMS_HPP
