#if !defined(TTI_MEMBER_TYPE_GEN_HPP)
#define TTI_MEMBER_TYPE_GEN_HPP

#include <boost/config.hpp>
#include <boost/preprocessor/cat.hpp>
#include "trait_gen.hpp"

#define BOOST_TTI_MEMBER_TYPE_GEN_BASE(name) \
  BOOST_PP_CAT(member_type_,name) \
/**/
  
#define BOOST_TTI_MTFC_MEMBER_TYPE_GEN_BASE(name) \
  BOOST_PP_CAT(mtfc_member_type_,name) \
/**/

#define BOOST_TTI_MEMBER_TYPE_GEN(name) \
  BOOST_TTI_NAMESPACE::BOOST_TTI_MEMBER_TYPE_GEN_BASE(name) \
/**/
  
#define BOOST_TTI_MTFC_MEMBER_TYPE_GEN(name) \
  BOOST_TTI_NAMESPACE::BOOST_TTI_MTFC_MEMBER_TYPE_GEN_BASE(name) \
/**/

#endif // TTI_MEMBER_TYPE_GEN_HPP
