#if !defined(TTI_DETAIL_STATIC_MEMBER_FUNCTION_HPP)
#define TTI_DETAIL_STATIC_MEMBER_FUNCTION_HPP

#include <boost/config.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/function_types/function_type.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined(BOOST_NO_NULLPTR)

#define TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION(trait,name) \
  template<class T,class Type> \
  struct trait \
    { \
    template<Type *> \
    struct helper; \
    \
    template<class U> \
    static ::boost::type_traits::yes_type check(helper<&U::name> *); \
    \
    template<class U> \
    static ::boost::type_traits::no_type check(...); \
    \
    BOOST_STATIC_CONSTANT(bool,value=sizeof(check<T>(0))==sizeof(::boost::type_traits::yes_type)); \
    \
    typedef boost::mpl::bool_<value> type; \
    }; \
/**/

#else // !defined(BOOST_NO_NULLPTR)

#define TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION(trait,name) \
  template<class T,class Type> \
  struct trait \
    { \
    template<Type *> \
    struct helper; \
    \
    template<class U> \
    static ::boost::type_traits::yes_type check(helper<&U::name> *); \
    \
    template<class U> \
    static ::boost::type_traits::no_type check(...); \
    \
    BOOST_STATIC_CONSTANT(bool,value=sizeof(check<T>(nullptr))==sizeof(::boost::type_traits::yes_type)); \
    \
    typedef boost::mpl::bool_<value> type; \
    }; \
/**/

#endif // defined(BOOST_NO_NULLPTR)

namespace boost
  {
  namespace tti
    {
    namespace detail
      {
      template
        <
        class R,
        class FS,
        class TAG
        >
      struct tfunction_seq
        {
        typedef typename boost::mpl::push_front<FS,R>::type ftseq;
        typedef typename boost::function_types::function_type<ftseq,TAG>::type type;
        };
      }
    }
  }
  
#endif // TTI_DETAIL_STATIC_MEMBER_FUNCTION_HPP
