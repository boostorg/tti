#if !defined(TEST_HAS_MEM_FUN_TEMPLATE_HPP)
#define TEST_HAS_MEM_FUN_TEMPLATE_HPP

#include "test_structs.hpp"
#include <boost/tti/mem_fun_template.hpp>
#include <boost/tti/mem_fun_template_params.hpp>
#include <boost/tti/mem_type.hpp>

BOOST_TTI_HAS_MEMBER_FUNCTION_TEMPLATE_PARAMS(SomeFuncTemplate,(int)(long)(double)(50))
BOOST_TTI_TRAIT_HAS_MEMBER_FUNCTION_TEMPLATE_PARAMS(SameName,AFuncTemplate,(int)(int)(float))
BOOST_TTI_HAS_MEMBER_FUNCTION_TEMPLATE_PARAMS(AFuncTemplate,(long)(9983))
BOOST_TTI_TRAIT_HAS_MEMBER_FUNCTION_TEMPLATE_PARAMS(AnotherName,MyFuncTemplate,(bool))

BOOST_TTI_TRAIT_HAS_MEMBER_FUNCTION_TEMPLATE(SomeFuncName,SomeFuncTemplate)
BOOST_TTI_TRAIT_HAS_MEMBER_FUNCTION_TEMPLATE(AnotherNameFT,AFuncTemplate)
BOOST_TTI_TRAIT_HAS_MEMBER_FUNCTION_TEMPLATE(OneFT,AFuncTemplate)
BOOST_TTI_HAS_MEMBER_FUNCTION_TEMPLATE(MyFuncTemplate)

BOOST_TTI_MEMBER_TYPE(BType)
BOOST_TTI_MEMBER_TYPE(CType)

#endif // TEST_HAS_MEM_FUN_TEMPLATE_HPP
