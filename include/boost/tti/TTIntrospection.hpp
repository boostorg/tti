#if !defined(TT_INTROSPECTION_HPP)
#define TT_INTROSPECTION_HPP

#include <boost/config.hpp>
#include <boost/function_types/is_member_object_pointer.hpp>
#include <boost/function_types/parameter_types.hpp>
#include <boost/mpl/has_xxx.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/preprocessor/arithmetic/add.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
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
        tti::detail::member_type::trait<T>, \
        tti::detail::notype \
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
  BOOST_PP_CAT(has_type_check_typedef_,name), \
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

#else // !!BOOST_WORKAROUND(BOOST_MSVC, <= 1400)

#define TTI_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(trait,name,tpSeq) \
namespace tti \
  { \
  TTI_DETAIL_HAS_MEMBER_WITH_TEMPLATE_SFINAE \
    ( \
      ( BOOST_PP_ADD(BOOST_PP_SEQ_SIZE(tpSeq),4), ( trait, name, 1, false, BOOST_PP_SEQ_ENUM(tpSeq) ) )  \
    ) \
  } \
/**/

#endif // !BOOST_WORKAROUND(BOOST_MSVC, <= 1400)
#else // !!defined(BOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE)

#define TTI_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(trait,name,tpSeq) \
TTI_DETAIL_SAME(trait,name) \
/**/

#endif // !defined(BOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE)

#define TTI_HAS_TEMPLATE_CHECK_PARAMS(name,tpSeq) \
  TTI_TRAIT_HAS_TEMPLATE_CHECK_PARAMS \
  ( \
  BOOST_PP_CAT(has_template_check_params_,name), \
  name, \
  tpSeq \
  ) \
/**/

#if defined(BOOST_NO_NULLPTR)

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
    typedef trait type; \
    }; \
  } \
/**/

#else // !!defined(BOOST_NO_NULLPTR)

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
    typedef trait type; \
    }; \
  } \
/**/

#endif // defined(BOOST_NO_NULLPTR)

#define TTI_HAS_MEMBER(name) \
  TTI_TRAIT_HAS_MEMBER \
  ( \
  BOOST_PP_CAT(has_member_,name), \
  name \
  ) \
/**/

#if defined(BOOST_NO_NULLPTR)

#define TTI_TRAIT_HAS_STATIC_MEMBER(trait,name) \
namespace tti \
  { \
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
    typedef trait type; \
    }; \
  } \
/**/

#else // !defined(BOOST_NO_NULLPTR)

#define TTI_TRAIT_HAS_STATIC_MEMBER(trait,name) \
namespace tti \
  { \
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
    typedef trait type; \
    }; \
  } \
/**/

#endif // defined(BOOST_NO_NULLPTR)
  
#define TTI_HAS_STATIC_MEMBER(name) \
  TTI_TRAIT_HAS_STATIC_MEMBER \
  ( \
  BOOST_PP_CAT(has_static_member_,name), \
  name \
  ) \
/**/

namespace tti
  {
  
  template
    <
    template<class> class HasType,
    class T
    >
  struct mf_has_type :
    tti::detail::eval
      <
      HasType
        <
        T
        >
      >
    {
    };
    
  template
    <
    template<class> class MemberType,
    class T
    >
  struct mf_member_type :
    public mf_has_type<MemberType,T>
    {
    };
    
  template
    <
    template<class> class HasMember,
    class T,
    class R,
    BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(TTI_MAX_PARAMETERS,class P,tti::detail::noparam)
    >
  struct mf_has_member_function :
    tti::detail::eval
      <
      HasMember 
        <
        tti::detail::eval
          <
          tti::detail::ptmf
            <
            T,
            R,
            BOOST_PP_ENUM_PARAMS(TTI_MAX_PARAMETERS,P)
            >
          >
        >
      >
    {
    };
    
  template
    <
    template<class> class HasMember,
    class T,
    class R
    >
  struct mf_has_member_data :
    tti::detail::eval
      <
      HasMember 
        <
        tti::detail::eval
          <
          tti::detail::ptmd
            <
            T,
            R
            >
          >
        >
      >
    {
    };
    
  template
    <
    template<class,class> class HasStaticMember,
    class T,
    class R,
    BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(TTI_MAX_PARAMETERS,class P,tti::detail::noparam)
    >
  struct mf_has_static_function :
    tti::detail::eval
      <
      HasStaticMember 
        <
        T,
        tti::detail::eval
          <
          tti::detail::tfunction
            <
            R,
            BOOST_PP_ENUM_PARAMS(TTI_MAX_PARAMETERS,P)
            >
          >
        >
      >
    {
    };
    
  template
    <
    template<class,class> class HasStaticMember,
    class T,
    class R
    >
  struct mf_has_static_data :
    tti::detail::eval
      <
      HasStaticMember 
        <
        T,
        R
        >
      >
    {
    };
    
  template
    <
    template<class,class> class HasTypeCheckTypedef,
    class T,
    class U
    >
  struct mf_has_type_check_typedef :
    public mf_has_static_data<HasTypeCheckTypedef,T,U>
    {
    };
    
  }
  
#endif // TT_INTROSPECTION_HPP
