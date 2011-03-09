#if !defined(TTI_TYPE_GEN_HPP)
#define TTI_TYPE_GEN_HPP

#include <boost/config.hpp>
#include <boost/preprocessor/cat.hpp>

#define BOOST_TTI_HAS_TYPE_GEN_BASE(name) \
  BOOST_PP_CAT(has_type_,name) \
/**/

#define BOOST_TTI_MTFC_HAS_TYPE_GEN_BASE(name) \
  BOOST_PP_CAT(mtfc_has_type_,name) \
/**/

#define BOOST_TTI_HAS_TYPE_GEN(name) \
  boost::tti::BOOST_TTI_HAS_TYPE_GEN_BASE(name) \
/**/

#define BOOST_TTI_MTFC_HAS_TYPE_GEN(name) \
  boost::tti::BOOST_TTI_MTFC_HAS_TYPE_GEN_BASE(name) \
/**/

#endif // TTI_TYPE_GEN_HPP
