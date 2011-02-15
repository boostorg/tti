#if !defined(TTI_DETAIL_MEMBER_HPP)
#define TTI_DETAIL_MEMBER_HPP

#include <boost/config.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/function_types/is_member_object_pointer.hpp>
#include <boost/function_types/parameter_types.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined(BOOST_MSVC)

#if defined(BOOST_NO_NULLPTR)

#define TTI_DETAIL_TRAIT_HAS_MEMBER(trait,name) \
  template<class T> \
  struct trait \
    { \
    template<class> \
    struct class_of; \
    \
    template<class R,class C> \
    struct class_of<R C::*> \
      { \
      typedef C type; \
      }; \
    \
    template<class> \
    struct return_of; \
    \
    template<class R,class C> \
    struct return_of<R C::*> \
      { \
      typedef R type; \
      }; \
    \
    template<bool,typename U> \
    struct menable_if; \
    \
    template<typename U> \
    struct menable_if<true,U> \
      { \
      typedef U type; \
      }; \
    \
    template<typename U,typename V> \
    static ::boost::type_traits::yes_type check2(V U::*); \
    \
    template<typename U,typename V> \
    static ::boost::type_traits::no_type check2(U); \
    \
    template<class F> \
    struct class_type \
      { \
      typedef typename \
      boost::remove_const \
        < \
        typename \
        boost::mpl::at \
          < \
          typename \
          boost::function_types::parameter_types \
            < \
            F, \
            boost::mpl::quote1 \
              < \
              boost::mpl::identity \
              > \
            > \
            ::type, \
            boost::mpl::int_<0> \
          >::type \
        >::type \
      type; \
      }; \
    \
    template<T> \
    struct helper; \
    \
    template<typename U,typename V> \
    static typename \
      menable_if \
        < \
        sizeof(check2<U,V>(&U::name))==sizeof(::boost::type_traits::yes_type), \
        ::boost::type_traits::yes_type \
        > \
      ::type \
    has_matching_member(int); \
    \
    template<typename U,typename V> \
    static ::boost::type_traits::no_type has_matching_member(...); \
    \
    template<class U> \
    static ::boost::type_traits::yes_type check(helper<&U::name> *); \
    \
    template<class U> \
    static ::boost::type_traits::no_type check(...); \
    \
    template<class F> \
    struct ttc_md \
      { \
      typedef boost::mpl::bool_<sizeof(has_matching_member<typename class_of<F>::type,typename return_of<F>::type>(0))==sizeof(::boost::type_traits::yes_type)> type; \
      }; \
    \
    template<class F> \
    struct ttc_mf \
      { \
      typedef boost::mpl::bool_<sizeof(check<typename class_type<F>::type>(0))==sizeof(::boost::type_traits::yes_type)> type; \
      }; \
    \
    template<class F> \
    struct type_to_check \
      { \
      typedef typename \
      boost::mpl::eval_if \
        < \
        boost::function_types::is_member_object_pointer<F>, \
        ttc_md<F>, \
        ttc_mf<F> \
        >::type \
      type; \
      }; \
    \
    typedef typename type_to_check<T>::type type; \
    \
    BOOST_STATIC_CONSTANT(bool,value=type::value); \
    \
    }; \
/**/

#else // !defined(BOOST_NO_NULLPTR)

#define TTI_DETAIL_TRAIT_HAS_MEMBER(trait,name) \
  template<class T> \
  struct trait \
    { \
    template<class> \
    struct class_of; \
    \
    template<class R,class C> \
    struct class_of<R C::*> \
      { \
      typedef C type; \
      }; \
    \
    template<class> \
    struct return_of; \
    \
    template<class R,class C> \
    struct return_of<R C::*> \
      { \
      typedef R type; \
      }; \
    \
    template<bool,typename U> \
    struct menable_if; \
    \
    template<typename U> \
    struct menable_if<true,U> \
      { \
      typedef U type; \
      }; \
    \
    template<typename U,typename V> \
    static ::boost::type_traits::yes_type check2(V U::*); \
    \
    template<typename U,typename V> \
    static ::boost::type_traits::no_type check2(U); \
    \
    template<class F> \
    struct class_type \
      { \
      typedef typename \
      boost::remove_const \
        < \
        typename \
        boost::mpl::at \
          < \
          typename \
          boost::function_types::parameter_types \
            < \
            F, \
            boost::mpl::quote1 \
              < \
              boost::mpl::identity \
              > \
            > \
            ::type, \
            boost::mpl::int_<0> \
          >::type \
        >::type \
      type; \
      }; \
    \
    template<T> \
    struct helper; \
    \
    template<typename U,typename V> \
    static typename \
      menable_if \
        < \
        sizeof(check2<U,V>(&U::name))==sizeof(::boost::type_traits::yes_type), \
        ::boost::type_traits::yes_type \
        > \
      ::type \
    has_matching_member(int); \
    \
    template<typename U,typename V> \
    static ::boost::type_traits::no_type has_matching_member(...); \
    \
    template<class U> \
    static ::boost::type_traits::yes_type check(helper<&U::name> *); \
    \
    template<class U> \
    static ::boost::type_traits::no_type check(...); \
    \
    template<class F> \
    struct ttc_md \
      { \
      typedef boost::mpl::bool_<sizeof(has_matching_member<typename class_of<F>::type,typename return_of<F>::type>(0))==sizeof(::boost::type_traits::yes_type)> type; \
      }; \
    \
    template<class F> \
    struct ttc_mf \
      { \
      typedef boost::mpl::bool_<sizeof(check<typename class_type<F>::type>(nullptr))==sizeof(::boost::type_traits::yes_type)> type; \
      }; \
    \
    template<class F> \
    struct type_to_check \
      { \
      typedef typename \
      boost::mpl::eval_if \
        < \
        boost::function_types::is_member_object_pointer<F>, \
        ttc_md<F>, \
        ttc_mf<F> \
        >::type \
      type; \
      }; \
    \
    typedef typename type_to_check<T>::type type; \
    \
    BOOST_STATIC_CONSTANT(bool,value=type::value); \
    \
    }; \
/**/

#endif // defined(BOOST_NO_NULLPTR)

#else // !defined(BOOST_MSVC)

#if defined(BOOST_NO_NULLPTR)

#define TTI_DETAIL_TRAIT_HAS_MEMBER(trait,name) \
  template<class T> \
  struct trait \
    { \
    template<class> \
    struct class_of; \
    \
    template<class R,class C> \
    struct class_of<R C::*> \
      { \
      typedef C type; \
      }; \
    \
    template<class F> \
    struct class_type \
      { \
      typedef typename \
      boost::mpl::eval_if \
        < \
        boost::function_types::is_member_object_pointer<F>, \
        class_of<F>, \
        boost::remove_const \
          < \
          typename \
          boost::mpl::at \
            < \
            typename \
            boost::function_types::parameter_types \
              < \
              F, \
              boost::mpl::quote1 \
                < \
                boost::mpl::identity \
                > \
              > \
              ::type, \
              boost::mpl::int_<0> \
            >::type \
          > \
        >::type \
      type; \
      }; \
    \
    template<T> \
    struct helper; \
    \
    template<class U> \
    static ::boost::type_traits::yes_type check(helper<&U::name> *); \
    \
    template<class U> \
    static ::boost::type_traits::no_type check(...); \
    \
    BOOST_STATIC_CONSTANT(bool,value=sizeof(check<typename class_type<T>::type>(0))==sizeof(::boost::type_traits::yes_type)); \
    \
    typedef boost::mpl::bool_<value> type; \
    }; \
/**/

#else // !defined(BOOST_NO_NULLPTR)

#define TTI_DETAIL_TRAIT_HAS_MEMBER(trait,name) \
  template<class T> \
  struct trait \
    { \
    template<class> \
    struct class_of; \
    \
    template<class R,class C> \
    struct class_of<R C::*> \
      { \
      typedef C type; \
      }; \
    \
    template<class F> \
    struct class_type \
      { \
      typedef typename \
      boost::mpl::eval_if \
        < \
        boost::function_types::is_member_object_pointer<F>, \
        class_of<F>, \
        boost::remove_const \
          < \
          typename \
          boost::mpl::at \
            < \
            typename \
            boost::function_types::parameter_types \
              < \
              F, \
              boost::mpl::quote1 \
                < \
                boost::mpl::identity \
                > \
              > \
              ::type, \
              boost::mpl::int_<0> \
            >::type \
          > \
        >::type \
      type; \
      }; \
    \
    template<T> \
    struct helper; \
    \
    template<class U> \
    static ::boost::type_traits::yes_type check(helper<&U::name> *); \
    \
    template<class U> \
    static ::boost::type_traits::no_type check(...); \
    \
    BOOST_STATIC_CONSTANT(bool,value=sizeof(check<typename class_type<T>::type>(nullptr))==sizeof(::boost::type_traits::yes_type)); \
    \
    typedef boost::mpl::bool_<value> type; \
    }; \
/**/

#endif // defined(BOOST_NO_NULLPTR)

#endif // defined(BOOST_MSVC)

#endif // TTI_DETAIL_MEMBER_HPP
