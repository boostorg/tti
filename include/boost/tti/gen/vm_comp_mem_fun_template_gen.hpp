#if !defined(TTI_VM_COMP_MEM_FUN_TEMPLATE_GEN_HPP)
#define TTI_VM_COMP_MEM_FUN_TEMPLATE_GEN_HPP

#include <boost/config.hpp>

#if !defined(BOOST_NO_VARIADIC_MACROS)

#include <boost/preprocessor/cat.hpp>
#include "trait_gen.hpp"

#define BOOST_TTI_VM_HAS_COMP_MEMBER_FUNCTION_TEMPLATE_GEN_BASE(name) \
  BOOST_PP_CAT(has_comp_member_function_template_,name) \
/**/

#define BOOST_TTI_VM_MTFC_HAS_COMP_MEMBER_FUNCTION_TEMPLATE_GEN_BASE(name) \
  BOOST_PP_CAT(mtfc_has_comp_member_function_template_,name) \
/**/

#define BOOST_TTI_VM_HAS_COMP_MEMBER_FUNCTION_TEMPLATE_GEN(name) \
  boost::tti::BOOST_TTI_VM_HAS_COMP_MEMBER_FUNCTION_TEMPLATE_GEN_BASE(name) \
/**/

#define BOOST_TTI_VM_MTFC_HAS_COMP_MEMBER_FUNCTION_TEMPLATE_GEN(name) \
  boost::tti::BOOST_TTI_VM_MTFC_HAS_COMP_MEMBER_FUNCTION_TEMPLATE_GEN_BASE(name) \
/**/

#endif // !defined(BOOST_NO_VARIADIC_MACROS)
#endif // TTI_VM_COMP_MEM_FUN_TEMPLATE_GEN_HPP
