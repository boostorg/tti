#if !defined(TEST_VM_MF_HAS_TEMPLATE_CHECK_PARAMS_HPP)
#define TEST_VM_MF_HAS_TEMPLATE_CHECK_PARAMS_HPP

#if !defined(BOOST_NO_VARIADIC_MACROS)

#include "test_structs.hpp"
#include <boost/tti/tti_vm.hpp>
#include <boost/tti/tti.hpp>

TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(HT_Str,MStrMemberTemplate,class)
TTI_VM_HAS_TEMPLATE_CHECK_PARAMS(AnotherMemberTemplate,int,int)
TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(WrongParametersForMP,ManyParameters,class,class,int,class,template <class> class InnerTemplate,class,short)
TTI_VM_HAS_TEMPLATE_CHECK_PARAMS(CTManyParameters,class,class,int,short,class,template <class,int> class InnerTemplate,class)
TTI_VM_HAS_TEMPLATE_CHECK_PARAMS(TemplateNotExist,int,class)

TTI_VM_MTFC_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(MF_HT_Str,MStrMemberTemplate,class)
TTI_VM_MTFC_HAS_TEMPLATE_CHECK_PARAMS(AnotherMemberTemplate,int,int)
TTI_VM_MTFC_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(AllWrongParametersForMP,ManyParameters,class,class,int,class,template <class> class InnerTemplate,class,short)
TTI_VM_MTFC_HAS_TEMPLATE_CHECK_PARAMS(CTManyParameters,class,class,int,short,class,template <class,int> class InnerTemplate,class)
TTI_VM_MTFC_HAS_TEMPLATE_CHECK_PARAMS(TemplateNotExist,int,class)

TTI_MEMBER_TYPE(AStructType)
TTI_TRAIT_MEMBER_TYPE(MT_BType,BType)
TTI_MEMBER_TYPE(CType)

TTI_MTFC_MEMBER_TYPE(CType)

#endif //!defined(BOOST_NO_VARIADIC_MACROS)

#endif // TEST_VM_MF_HAS_TEMPLATE_CHECK_PARAMS_HPP
