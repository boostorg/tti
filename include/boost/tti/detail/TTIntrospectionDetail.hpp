#if !defined(TT_INTROSPECTION_DETAIL_HPP)
#define TT_INTROSPECTION_DETAIL_HPP

#include <boost/config.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/has_xxx.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/mpl/remove.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/preprocessor/arithmetic/add.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/array/elem.hpp>
#include <boost/preprocessor/array/size.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/iteration/iterate.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_shifted.hpp>
#include <boost/preprocessor/repetition/enum_shifted_params.hpp>
#include <boost/function_types/function_type.hpp>
#include <boost/function_types/is_member_object_pointer.hpp>
#include <boost/function_types/member_function_pointer.hpp>
#include <boost/function_types/parameter_types.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if !defined(BOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE)

#define TTI_DETAIL_TEMPLATE_PARAMETERS(z,n,args) \
BOOST_PP_ARRAY_ELEM(BOOST_PP_ADD(4,n),args) \
/**/

#define TTI_DETAIL_HAS_MEMBER_IMPLEMENTATION(args,introspect_macro) \
   template \
     < \
     typename T, \
     typename fallback_ \
       = boost::mpl::bool_< BOOST_PP_ARRAY_ELEM(3, args) > \
     > \
   class BOOST_PP_ARRAY_ELEM(0, args) \
     { \
     introspect_macro(args) \
     public: \
       static const bool value \
         = BOOST_MPL_HAS_MEMBER_INTROSPECTION_NAME(args)< T >::value; \
       typedef typename BOOST_MPL_HAS_MEMBER_INTROSPECTION_NAME(args) \
         < \
         T \
         >::type type; \
     }; \
/**/

#define TTI_DETAIL_MTFC_HAS_MEMBER_IMPLEMENTATION(args,introspect_macro) \
  struct BOOST_PP_ARRAY_ELEM(0, args) \
    { \
    template \
      < \
      typename T, \
      typename fallback_ \
        = boost::mpl::bool_< BOOST_PP_ARRAY_ELEM(3, args) > \
      > \
    class apply \
      { \
      introspect_macro(args) \
      public: \
        static const bool value \
          = BOOST_MPL_HAS_MEMBER_INTROSPECTION_NAME(args)< T >::value; \
        typedef typename BOOST_MPL_HAS_MEMBER_INTROSPECTION_NAME(args) \
          < \
          T \
          >::type type; \
      }; \
    }; \
/**/

#if !BOOST_WORKAROUND(BOOST_MSVC, <= 1400)

#define TTI_DETAIL_HAS_MEMBER_MULTI_SUBSTITUTE(z,n,args) \
  template \
    < \
    template \
      < \
      BOOST_PP_ENUM_ ## z \
        ( \
        BOOST_PP_SUB \
          ( \
          BOOST_PP_ARRAY_SIZE(args), \
          4 \
          ), \
        TTI_DETAIL_TEMPLATE_PARAMETERS, \
        args \
        ) \
      > \
    class V \
    > \
  struct BOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_NAME(args, n) \
    { \
    }; \
/**/

#define TTI_DETAIL_HAS_MEMBER_SUBSTITUTE(args) \
  BOOST_PP_REPEAT \
    ( \
    BOOST_PP_ARRAY_ELEM(2, args), \
    TTI_DETAIL_HAS_MEMBER_MULTI_SUBSTITUTE, \
    args \
    ) \
/**/

#define TTI_DETAIL_HAS_MEMBER_INTROSPECT(args) \
  template< typename U > \
  struct BOOST_MPL_HAS_MEMBER_INTROSPECTION_NAME(args) \
    { \
    TTI_DETAIL_HAS_MEMBER_SUBSTITUTE(args) \
    BOOST_MPL_HAS_MEMBER_REJECT(args, BOOST_PP_NIL) \
    BOOST_MPL_HAS_MEMBER_ACCEPT(args, BOOST_PP_NIL) \
    BOOST_STATIC_CONSTANT \
      ( \
      bool, value = BOOST_MPL_HAS_MEMBER_TEST(args) \
      ); \
    typedef boost::mpl::bool_< value > type; \
    }; \
/**/

#define TTI_DETAIL_HAS_MEMBER_WITH_FUNCTION_SFINAE(args) \
  TTI_DETAIL_HAS_MEMBER_IMPLEMENTATION \
    ( \
    args, \
    TTI_DETAIL_HAS_MEMBER_INTROSPECT \
    ) \
/**/

#else // !!BOOST_WORKAROUND(BOOST_MSVC, <= 1400)

#define TTI_DETAIL_HAS_MEMBER_MULTI_SUBSTITUTE_WITH_TEMPLATE_SFINAE(z,n,args) \
  template \
    < \
    template \
      < \
      BOOST_PP_ENUM_ ## z \
        ( \
        BOOST_PP_SUB \
          ( \
          BOOST_PP_ARRAY_SIZE(args), \
          4 \
          ), \
        TTI_DETAIL_TEMPLATE_PARAMETERS, \
        args \
        ) \
      > \
    class U \
    > \
  struct BOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_NAME_WITH_TEMPLATE_SFINAE \
    ( \
    args, \
    n \
    ) \
    { \
    typedef \
      BOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_TAG_NAME(args) \
      type; \
    }; \
/**/

#define TTI_DETAIL_HAS_MEMBER_SUBSTITUTE_WITH_TEMPLATE_SFINAE(args) \
  typedef void \
      BOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_TAG_NAME(args); \
  BOOST_PP_REPEAT \
    ( \
    BOOST_PP_ARRAY_ELEM(2, args), \
    TTI_DETAIL_HAS_MEMBER_MULTI_SUBSTITUTE_WITH_TEMPLATE_SFINAE, \
    args \
    ) \
/**/

#define TTI_DETAIL_HAS_MEMBER_INTROSPECT_WITH_TEMPLATE_SFINAE(args) \
  BOOST_MPL_HAS_MEMBER_REJECT_WITH_TEMPLATE_SFINAE(args,BOOST_PP_NIL) \
  BOOST_MPL_HAS_MEMBER_ACCEPT_WITH_TEMPLATE_SFINAE(args,BOOST_PP_NIL) \
  template< typename U > \
  struct BOOST_MPL_HAS_MEMBER_INTROSPECTION_NAME(args) \
      : BOOST_MPL_HAS_MEMBER_INTROSPECTION_TEST_NAME(args)< U > { \
  }; \
/**/

#define TTI_DETAIL_HAS_MEMBER_WITH_TEMPLATE_SFINAE(args) \
  TTI_DETAIL_HAS_MEMBER_SUBSTITUTE_WITH_TEMPLATE_SFINAE \
    ( \
    args \
    ) \
  TTI_DETAIL_HAS_MEMBER_IMPLEMENTATION \
    ( \
    args, \
    TTI_DETAIL_HAS_MEMBER_INTROSPECT_WITH_TEMPLATE_SFINAE \
    ) \
/**/

#define TTI_DETAIL_MTFC_HAS_MEMBER_WITH_TEMPLATE_SFINAE(args) \
  TTI_DETAIL_HAS_MEMBER_SUBSTITUTE_WITH_TEMPLATE_SFINAE \
    ( \
    args \
    ) \
  TTI_DETAIL_MTFC_HAS_MEMBER_IMPLEMENTATION \
    ( \
    args, \
    TTI_DETAIL_HAS_MEMBER_INTROSPECT_WITH_TEMPLATE_SFINAE \
    ) \
/**/

#endif // !BOOST_WORKAROUND(BOOST_MSVC, <= 1400)
#else // !!defined(BOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE)

#define TTI_DETAIL_SAME(trait,name) \
  BOOST_MPL_HAS_XXX_TEMPLATE_NAMED_DEF \
    ( \
    trait, \
    name, \
    false \
    ) \
/**/

#endif // !defined(BOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE)

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

#define TTI_DETAIL_TRAIT_HAS_TYPE(trait,name) \
namespace mpl \
  { \
  BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, false) \
  } \
template<class T,class U,class B> \
struct trait \
  { \
  typedef typename \
    boost::mpl::eval_if \
      < \
      boost::is_same<typename T::name,U>, \
      boost::mpl::true_, \
      boost::mpl::false_ \
      >::type \
  type; \
  }; \
\
template<class T,class U> \
struct trait<T,U,boost::mpl::false_::type> \
  { \
  typedef boost::mpl::false_::type type; \
  }; \
\
template<class T> \
struct trait<T,tti::detail::notype,boost::mpl::true_::type> \
  { \
  typedef boost::mpl::true_::type type; \
  }; \
/**/

#define TTI_DETAIL_PP_REPEAT_CLASS(z,n,data) \
  BOOST_PP_COMMA_IF(n) data \
/**/

#define TTI_DETAIL_PP_ENUM_SHIFTED_TYPENAME(z,n,data) \
  BOOST_PP_CAT(typename P,n::type) \
/**/

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

#if defined(BOOST_MSVC)

#define TTI_DETAIL_TRAIT_HAS_MEMBER_DATA(trait,name) \
  template<class T,class C> \
  struct trait \
    { \
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
    template<class U,class V> \
    struct ttc_md \
      { \
      typedef boost::mpl::bool_<sizeof(has_matching_member<V,typename return_of<U>::type>(0))==sizeof(::boost::type_traits::yes_type)> type; \
      }; \
    \
    typedef typename ttc_md<T,C>::type type; \
    \
    BOOST_STATIC_CONSTANT(bool,value=type::value); \
    \
    }; \
/**/

#else // !defined(BOOST_MSVC)

#define TTI_DETAIL_TRAIT_HAS_MEMBER_DATA(trait,name) \
  TTI_DETAIL_TRAIT_HAS_MEMBER_FUNCTION(trait,name) \
/**/

#endif // defined(BOOST_MSVC)

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

namespace tti
  {
  namespace detail
    {
    struct notype
      {
      };
      
    template <class T>
    struct tself : T
      {
      };
  
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

    template
      <
      class T,
      class R
      >
    struct ptmd
      {
      typedef R T::* type;
      };
      
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
  
#endif // TT_INTROSPECTION_DETAIL_HPP
