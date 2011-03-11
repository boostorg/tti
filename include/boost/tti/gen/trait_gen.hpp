#if !defined(TTI_TRAIT_GEN_HPP)
#define TTI_TRAIT_GEN_HPP

#include "namespace_gen.hpp"

#define BOOST_TTI_TRAIT_GEN_BASE(name) \
  name \
/**/

#define BOOST_TTI_TRAIT_GEN(name) \
  BOOST_TTI_NAMESPACE::BOOST_TTI_TRAIT_GEN_BASE(name) \
/**/

#endif // TTI_TRAIT_GEN_HPP
