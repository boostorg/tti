#if !defined(TTI_TRAIT_GEN_HPP)
#define TTI_TRAIT_GEN_HPP

#include <boost/config.hpp>
#include <boost/preprocessor/cat.hpp>

#define BOOST_TTI_TRAIT_GEN_BASE(name) \
  name \
/**/

#define BOOST_TTI_TRAIT_GEN(name) \
  boost::tti::BOOST_TTI_TRAIT_GEN_BASE(name) \
/**/

#endif // TTI_TRAIT_GEN_HPP
