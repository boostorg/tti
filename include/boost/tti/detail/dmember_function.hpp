#if !defined(TTI_DETAIL_MEMBER_FUNCTION_HPP)
#define TTI_DETAIL_MEMBER_FUNCTION_HPP

#include <boost/config.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/function_types/member_function_pointer.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined(BOOST_NO_NULLPTR)

#define TTI_DETAIL_TRAIT_HAS_MEMBER_FUNCTION(trait,name) \
  template<class T,class C> \
  struct trait \
    { \
    template<T> \
    struct helper; \
    \
    template<class U> \
    static ::boost::type_traits::yes_type check(helper<&U::name> *); \
    \
    template<class U> \
    static ::boost::type_traits::no_type check(...); \
    \
    BOOST_STATIC_CONSTANT(bool,value=sizeof(check<C>(0))==sizeof(::boost::type_traits::yes_type)); \
    \
    typedef boost::mpl::bool_<value> type; \
    }; \
/**/

#else // !defined(BOOST_NO_NULLPTR)

#define TTI_DETAIL_TRAIT_HAS_MEMBER_FUNCTION(trait,name) \
  template<class T,class C> \
  struct trait \
    { \
    template<T> \
    struct helper; \
    \
    template<class U> \
    static ::boost::type_traits::yes_type check(helper<&U::name> *); \
    \
    template<class U> \
    static ::boost::type_traits::no_type check(...); \
    \
    BOOST_STATIC_CONSTANT(bool,value=sizeof(check<C>(nullptr))==sizeof(::boost::type_traits::yes_type)); \
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
        class T,
        class R,
        class FS,
        class TAG
        >
      struct ptmf_seq
        {
        typedef typename boost::mpl::push_front<FS,T>::type tfs1;
        typedef typename boost::mpl::push_front<tfs1,R>::type tfs2;
        typedef typename boost::function_types::member_function_pointer<tfs2,TAG>::type type;
        };
      }
    }
  }
  
#endif // TTI_DETAIL_MEMBER_FUNCTION_HPP
