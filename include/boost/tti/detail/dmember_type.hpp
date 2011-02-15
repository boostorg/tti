#if !defined(TTI_DETAIL_MEMBER_TYPE_HPP)
#define TTI_DETAIL_MEMBER_TYPE_HPP

#include <boost/config.hpp>
#include <boost/mpl/has_xxx.hpp>

#define TTI_DETAIL_TRAIT_HAS_TYPE_MEMBER_TYPE(trait,name) \
namespace mpl \
  { \
  BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, false) \
  } \
template<class T> \
struct trait \
  { \
  typedef typename mpl::trait<T>::type type; \
  \
  BOOST_STATIC_CONSTANT(bool,value=type::value); \
  }; \
/**/

#define TTI_DETAIL_TRAIT_MEMBER_TYPE(trait,name) \
namespace member_type \
  { \
  template<class T> \
  struct trait \
    { \
    typedef typename T::name type; \
    }; \
  } \
/**/

#endif // TTI_DETAIL_MEMBER_TYPE_HPP
