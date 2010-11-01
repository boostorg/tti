#if !defined(TT_INTROSPECTION_HPP)
#define TT_INTROSPECTION_HPP

#include <boost/config.hpp>
#include <boost/mpl/has_xxx.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/variadic_macro_data/VariadicMacroData.hpp>
#include "detail/TTIntrospectionDetail.hpp"

#define TTI_TRAIT_HAS_TYPE(trait,name) \
namespace tti \
  { \
  namespace detail \
    { \
    TTI_DETAIL_TRAIT_HAS_TYPE(trait,name) \
    } \
  template<class T> \
  struct trait \
    { \
    typedef typename tti::detail::trait<T>::type type; \
    \
    BOOST_STATIC_CONSTANT(bool,value=type::value); \
    }; \
  } \
/**/

#define TTI_HAS_TYPE(name) \
  TTI_TRAIT_HAS_TYPE \
  ( \
  BOOST_PP_CAT(has_type_,name), \
  name \
  ) \
/**/

#define TTI_TRAIT_MEMBER_TYPE(trait,name) \
namespace tti \
  { \
  namespace detail \
    { \
    TTI_DETAIL_TRAIT_HAS_TYPE(trait,name) \
    TTI_DETAIL_TRAIT_MEMBER_TYPE(trait,name) \
    } \
  template<class T> \
  struct trait \
    { \
    typedef typename \
      boost::mpl::eval_if \
        < \
        tti::detail::trait<T>, \
        tti::detail::membertype::trait<T>, \
        boost::mpl::identity<tti::detail::notype> \
        >::type \
    type; \
    }; \
  } \
/**/

#define TTI_MEMBER_TYPE(name) \
  TTI_TRAIT_MEMBER_TYPE \
  ( \
  BOOST_PP_CAT(member_type_,name), \
  name \
  ) \
/**/
  
#define TTI_TRAIT_HAS_TYPE_CHECK_TYPEDEF(trait,name) \
namespace tti \
  { \
  namespace detail \
    { \
    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, false) \
    } \
  \
  template<class T,class U,class B> \
  struct BOOST_PP_CAT(trait,_impl) \
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
  struct BOOST_PP_CAT(trait,_impl)<T,U,boost::mpl::false_::type> \
    { \
    typedef boost::mpl::false_::type type; \
    }; \
  \
  template<class T,class U> \
  struct trait \
    { \
    \
    typedef typename \
      BOOST_PP_CAT(trait,_impl) \
      < \
      T, \
      U, \
      typename tti::detail::trait<T>::type \
      >::type \
    type; \
    \
    BOOST_STATIC_CONSTANT(bool,value=type::value); \
    }; \
  } \
/**/

#define TTI_HAS_TYPE_CHECK_TYPEDEF(name) \
  TTI_TRAIT_HAS_TYPE_CHECK_TYPEDEF \
  ( \
  BOOST_PP_CAT(has_type_check_,name), \
  name \
  ) \
/**/

#define TTI_TRAIT_HAS_TEMPLATE(trait,name) \
namespace tti \
  { \
  namespace detail \
    { \
    BOOST_MPL_HAS_XXX_TEMPLATE_NAMED_DEF(trait, name, false) \
    } \
  template<class T> \
  struct trait \
    { \
    typedef typename tti::detail::trait<T>::type type; \
    \
    BOOST_STATIC_CONSTANT(bool,value=type::value); \
    }; \
  } \
/**/
  
#define TTI_HAS_TEMPLATE(name) \
  TTI_TRAIT_HAS_TEMPLATE \
  ( \
  BOOST_PP_CAT(has_template_,name), \
  name \
  ) \
/**/

#if !defined(BOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE)
#if !BOOST_WORKAROUND(BOOST_MSVC, <= 1400)
#define TTI_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(trait,name,tpSeq) \
namespace tti \
  { \
  TTI_DETAIL_HAS_MEMBER_WITH_FUNCTION_SFINAE \
    (  \
      ( BOOST_PP_ADD(BOOST_PP_SEQ_SIZE(tpSeq),4), ( trait, name, 1, false, BOOST_PP_SEQ_ENUM(tpSeq) ) )  \
    )  \
  } \
/**/
#if !defined(BOOST_NO_VARIADIC_MACROS)
#define TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(trait,name,...) \
namespace tti \
  { \
  TTI_DETAIL_HAS_MEMBER_WITH_FUNCTION_SFINAE \
    (  \
      ( BOOST_PP_ADD(VMD_DATA_SIZE(__VA_ARGS__),4), ( trait, name, 1, false, __VA_ARGS__ ) )  \
    )  \
  } \
/**/
#endif // !defined(BOOST_NO_VARIADIC_MACROS)
#else
#define TTI_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(trait,name,tpSeq) \
namespace tti \
  { \
  TTI_DETAIL_HAS_MEMBER_WITH_TEMPLATE_SFINAE \
    ( \
      ( BOOST_PP_ADD(BOOST_PP_SEQ_SIZE(tpSeq),4), ( trait, name, 1, false, BOOST_PP_SEQ_ENUM(tpSeq) ) )  \
    ) \
  } \
/**/
#if !defined(BOOST_NO_VARIADIC_MACROS)
#define TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(trait,name,...) \
namespace tti \
  { \
  TTI_DETAIL_HAS_MEMBER_WITH_TEMPLATE_SFINAE \
    ( \
      ( BOOST_PP_ADD(VMD_DATA_SIZE(__VA_ARGS__),4), ( trait, name, 1, false, __VA_ARGS__ ) )  \
    ) \
  } \
/**/
#endif // !defined(BOOST_NO_VARIADIC_MACROS)
#endif // !BOOST_WORKAROUND(BOOST_MSVC, <= 1400)
#else
#define TTI_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(trait,name,tpSeq) \
TTI_DETAIL_SAME(trait,name) \
/**/
#if !defined(BOOST_NO_VARIADIC_MACROS)
#define TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(trait,name,...) \
TTI_DETAIL_SAME(trait,name) \
/**/
#endif // !defined(BOOST_NO_VARIADIC_MACROS)
#endif // !defined(BOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE)

#define TTI_HAS_TEMPLATE_CHECK_PARAMS(name,tpSeq) \
  TTI_TRAIT_HAS_TEMPLATE_CHECK_PARAMS \
  ( \
  BOOST_PP_CAT(has_template_check_,name), \
  name, \
  tpSeq \
  ) \
/**/
#if !defined(BOOST_NO_VARIADIC_MACROS)
#define TTI_VM_HAS_TEMPLATE_CHECK_PARAMS(name,...) \
  TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS \
  ( \
  BOOST_PP_CAT(has_template_check_,name), \
  name, \
  __VA_ARGS__ \
  ) \
/**/
#endif

#define TTI_TRAIT_HAS_MEMBER(trait,name) \
namespace tti \
  { \
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
    template<T> \
    struct helper; \
    \
    template<class U> \
    static ::boost::type_traits::yes_type check(helper<&U::name> *); \
    \
    template<class U> \
    static ::boost::type_traits::no_type check(...); \
    \
    BOOST_STATIC_CONSTANT(bool,value=sizeof(check<typename class_of<T>::type>(nullptr))==sizeof(::boost::type_traits::yes_type)); \
    \
    typedef trait type; \
    }; \
  } \
/**/
  
#define TTI_HAS_MEMBER(name) \
  TTI_TRAIT_HAS_MEMBER \
  ( \
  BOOST_PP_CAT(has_member_,name), \
  name \
  ) \
/**/

#endif // TT_INTROSPECTION_HPP
