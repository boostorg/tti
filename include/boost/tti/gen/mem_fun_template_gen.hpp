#if !defined(TTI_MEMBER_FUNCTION_TEMPLATE_GEN_HPP)
#define TTI_MEMBER_FUNCTION_TEMPLATE_GEN_HPP

#include <boost/config.hpp>
#include <boost/preprocessor/cat.hpp>

#define BOOST_TTI_HAS_MEMBER_FUNCTION_TEMPLATE_GEN_BASE(name) \
  BOOST_PP_CAT(has_member_function_template_,name) \
/**/

#define BOOST_TTI_MTFC_HAS_MEMBER_FUNCTION_TEMPLATE_GEN_BASE(name) \
  BOOST_PP_CAT(mtfc_has_member_function_template_,name) \
/**/

#define BOOST_TTI_HAS_MEMBER_FUNCTION_TEMPLATE_GEN(name) \
  boost::tti::BOOST_TTI_HAS_MEMBER_FUNCTION_TEMPLATE_GEN_BASE(name) \
/**/

#define BOOST_TTI_MTFC_HAS_MEMBER_FUNCTION_TEMPLATE_GEN(name) \
  boost::tti::BOOST_TTI_MTFC_HAS_MEMBER_FUNCTION_TEMPLATE_GEN_BASE(name) \
/**/

#endif // TTI_MEMBER_FUNCTION_TEMPLATE_GEN_HPP
