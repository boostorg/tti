#if !defined(TTI_COMP_MEM_FUN_GEN_HPP)
#define TTI_COMP_MEM_FUN_GEN_HPP

#include <boost/config.hpp>
#include <boost/preprocessor/cat.hpp>

#define BOOST_TTI_HAS_COMP_MEMBER_FUNCTION_GEN_BASE(name) \
  BOOST_PP_CAT(has_comp_member_function_,name) \
/**/

#define BOOST_TTI_MTFC_HAS_COMP_MEMBER_FUNCTION_GEN_BASE(name) \
  BOOST_PP_CAT(mtfc_has_comp_member_function_,name) \
/**/

#define BOOST_TTI_HAS_COMP_MEMBER_FUNCTION_GEN(name) \
  boost::tti::BOOST_TTI_HAS_COMP_MEMBER_FUNCTION_GEN_BASE(name) \
/**/

#define BOOST_TTI_MTFC_HAS_COMP_MEMBER_FUNCTION_GEN(name) \
  boost::tti::BOOST_TTI_MTFC_HAS_COMP_MEMBER_FUNCTION_GEN_BASE(name) \
/**/

#endif // TTI_COMP_MEM_FUN_GEN_HPP
