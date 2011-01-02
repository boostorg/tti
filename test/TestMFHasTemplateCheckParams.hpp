#if !defined(TEST_MF_HAS_TEMPLATE_CHECK_PARAMS_HPP)
#define TEST_MF_HAS_TEMPLATE_CHECK_PARAMS_HPP

#include "TestStructs.hpp"
#include <boost/tti/TTIntrospection.hpp>

TTI_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(HT_Str,MStrMemberTemplate,(class))
TTI_HAS_TEMPLATE_CHECK_PARAMS(AnotherMemberTemplate,(int)(int))
TTI_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(WrongParametersForMP,ManyParameters,(class)(class)(int)(class)(template <class> class InnerTemplate)(class)(short))
TTI_HAS_TEMPLATE_CHECK_PARAMS(CTManyParameters,(class)(class)(int)(short)(class)(template <class)(int> class InnerTemplate)(class))
TTI_HAS_TEMPLATE_CHECK_PARAMS(TemplateNotExist,(int)(class))

TTI_MEMBER_TYPE(AStructType)
TTI_TRAIT_MEMBER_TYPE(MT_BType,BType)
TTI_MEMBER_TYPE(CType)

#endif // TEST_MF_HAS_TEMPLATE_CHECK_PARAMS_HPP
