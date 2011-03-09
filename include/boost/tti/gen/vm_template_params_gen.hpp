#if !defined(TTI_VM_TEMPLATE_PARAMS_GEN_HPP)
#define TTI_VM_TEMPLATE_PARAMS_GEN_HPP

#include <boost/config.hpp>

#if !defined(BOOST_NO_VARIADIC_MACROS)

#include <boost/preprocessor/cat.hpp>

#define BOOST_TTI_VM_HAS_TEMPLATE_CHECK_PARAMS_GEN_BASE(name) \
  BOOST_PP_CAT(has_template_check_params_,name) \
/**/

#define BOOST_TTI_VM_MTFC_HAS_TEMPLATE_CHECK_PARAMS_GEN_BASE(name) \
  BOOST_PP_CAT(mtfc_has_template_check_params_,name) \
/**/

#define BOOST_TTI_VM_HAS_TEMPLATE_CHECK_PARAMS_GEN(name) \
  boost::tti::BOOST_TTI_VM_HAS_TEMPLATE_CHECK_PARAMS_GEN_BASE(name) \
/**/

#define BOOST_TTI_VM_MTFC_HAS_TEMPLATE_CHECK_PARAMS_GEN(name) \
  boost::tti::BOOST_TTI_VM_MTFC_HAS_TEMPLATE_CHECK_PARAMS_GEN_BASE(name) \
/**/

#endif // !defined(BOOST_NO_VARIADIC_MACROS)
#endif // TTI_VM_TEMPLATE_PARAMS_GEN_HPP
