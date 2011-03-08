#if !defined(TEST_VM_HAS_MEM_FUN_TEMPLATE_HPP)
#define TEST_VM_HAS_MEM_FUN_TEMPLATE_HPP

#include <boost/config.hpp>

#if !defined(BOOST_NO_VARIADIC_MACROS)

#include "test_structs.hpp"
#include <boost/tti/vm_mem_fun_template.hpp>
#include <boost/tti/mem_type.hpp>

BOOST_TTI_VM_HAS_MEMBER_FUNCTION_TEMPLATE(SomeFuncTemplate,int,long,long,21234)
BOOST_TTI_VM_TRAIT_HAS_MEMBER_FUNCTION_TEMPLATE(SameName,AFuncTemplate,long,short,float)
BOOST_TTI_VM_HAS_MEMBER_FUNCTION_TEMPLATE(AFuncTemplate,bool,2385)
BOOST_TTI_VM_TRAIT_HAS_MEMBER_FUNCTION_TEMPLATE(AnotherName,MyFuncTemplate,double)

BOOST_TTI_MEMBER_TYPE(BType)
BOOST_TTI_MEMBER_TYPE(CType)

#endif //!defined(BOOST_NO_VARIADIC_MACROS)

#endif // TEST_VM_HAS_MEM_FUN_TEMPLATE_HPP
