#if !defined(TTI_STATIC_MEMBER_FUNCTION_GEN_HPP)
#define TTI_STATIC_MEMBER_FUNCTION_GEN_HPP

#include <boost/config.hpp>
#include <boost/preprocessor/cat.hpp>

#define BOOST_TTI_HAS_STATIC_MEMBER_FUNCTION_GEN_BASE(name) \
  BOOST_PP_CAT(has_static_member_function_,name) \
/**/

#define BOOST_TTI_MTFC_HAS_STATIC_MEMBER_FUNCTION_GEN_BASE(name) \
  BOOST_PP_CAT(mtfc_has_static_member_function_,name) \
/**/

#define BOOST_TTI_HAS_STATIC_MEMBER_FUNCTION_GEN(name) \
  boost::tti::BOOST_TTI_HAS_STATIC_MEMBER_FUNCTION_GEN_BASE(name) \
/**/

#define BOOST_TTI_MTFC_HAS_STATIC_MEMBER_FUNCTION_GEN(name) \
  boost::tti::BOOST_TTI_MTFC_HAS_STATIC_MEMBER_FUNCTION_GEN_BASE(name) \
/**/

#endif // TTI_STATIC_MEMBER_FUNCTION_GEN_HPP
