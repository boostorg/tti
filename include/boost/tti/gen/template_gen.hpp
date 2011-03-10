#if !defined(TTI_TEMPLATE_GEN_HPP)
#define TTI_TEMPLATE_GEN_HPP

#include <boost/config.hpp>
#include <boost/preprocessor/cat.hpp>
#include "trait_gen.hpp"

#define BOOST_TTI_HAS_TEMPLATE_GEN_BASE(name) \
  BOOST_PP_CAT(has_template_,name) \
/**/

#define BOOST_TTI_MTFC_HAS_TEMPLATE_GEN_BASE(name) \
  BOOST_PP_CAT(mtfc_has_template_,name) \
/**/

#define BOOST_TTI_HAS_TEMPLATE_GEN(name) \
  boost::tti::BOOST_TTI_HAS_TEMPLATE_GEN_BASE(name) \
/**/

#define BOOST_TTI_MTFC_HAS_TEMPLATE_GEN(name) \
  boost::tti::BOOST_TTI_MTFC_HAS_TEMPLATE_GEN_BASE(name) \
/**/

#endif // TTI_TEMPLATE_GEN_HPP
