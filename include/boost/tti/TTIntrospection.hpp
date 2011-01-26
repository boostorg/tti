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
#include "TTIntrospectionTemplate.hpp"
#include "detail/TTIntrospectionDetail.hpp"

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/// Expands to a metafunction which tests whether an inner type with a particular name exists and optionally is a particular type.
/**

    trait = the name of the metafunction within the tti namespace.<br />
    name  = the name of the inner type.

    returns = a metafunction called "tti::trait" where 'trait' is the macro parameter.
    
              The metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                U = the type of the inner type named 'name' as an optional parameter.<br />
                returns = 'value' is true if the 'name' type exists within the enclosing type
                          and, if type U is specified, the 'name' type is the same as the type U,
                          otherwise 'value' is false.
    
*/
#define TTI_TRAIT_HAS_TYPE(trait,name) \
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
  template<class T> \
  struct BOOST_PP_CAT(trait,_impl)<T,tti::detail::notype,boost::mpl::true_::type> \
    { \
    typedef boost::mpl::true_::type type; \
    }; \
  \
  template<class T,class U = tti::detail::notype> \
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

/// Expands to a metafunction which tests whether an inner type with a particular name exists and optionally is a particular type.
/**

    name  = the name of the inner type.

    returns = a metafunction called "tti::has_type_name" where 'name' is the macro parameter.
    
              The metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                U = the type of the inner type named 'name' as an optional parameter.<br />
                returns = 'value' is true if the 'name' type exists within the enclosing type
                          and, if type U is specified, the 'name' type is the same as the type U,
                          otherwise 'value' is false.
    
*/
#define TTI_HAS_TYPE(name) \
  TTI_TRAIT_HAS_TYPE \
  ( \
  BOOST_PP_CAT(has_type_,name), \
  name \
  ) \
/**/

/// Expands to a metafunction whose typedef 'type' is either the named type or an unspecified type.
/**

    trait = the name of the metafunction within the tti namespace.<br />
    name  = the name of the inner type.

    returns = a metafunction called "tti::trait" where 'trait' is the macro parameter.
    
              The metafunction types and return:
              
                T = the enclosing type.<br />
                returns = 'type' is the inner type of 'name' if the inner type exists
                          within the enclosing type, else 'type' is an unspecified type.<br />
                          'valid' is true if the inner type of 'name' exists
                          within the enclosing type, else 'valid' is false.
                          
    The purpose of this macro is to encapsulate the 'name' type as the typedef 'type'
    of a metafunction, but only if it exists within the enclosing type. This allows for
    a lazy evaluation of inner type existence which can be used by other metafunctions
    in this library.
    
*/
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
        boost::mpl::identity<tti::detail::notype> \
        >::type \
    type; \
    \
    typedef typename tti::detail::valid_type<type>::type valtype; \
    \
    BOOST_STATIC_CONSTANT(bool,valid=valtype::value); \
    }; \
  } \
/**/

/// Expands to a metafunction whose typedef 'type' is either the named type or an unspecified type.
/**

    name  = the name of the inner type.

    returns = a metafunction called "tti::member_type_name" where 'name' is the macro parameter.
    
              The metafunction types and return:
              
                T = the enclosing type.<br />
                returns = 'type' is the inner type of 'name' if the inner type exists
                          within the enclosing type, else 'type' is an unspecified type.<br />
                          'valid' is true if the inner type of 'name' exists
                          within the enclosing type, else 'valid' is false.
                          
    The purpose of this macro is to encapsulate the 'name' type as the typedef 'type'
    of a metafunction, but only if it exists within the enclosing type. This allows for
    a lazy evaluation of inner type existence which can be used by other metafunctions
    in this library.
    
*/
#define TTI_MEMBER_TYPE(name) \
  TTI_TRAIT_MEMBER_TYPE \
  ( \
  BOOST_PP_CAT(member_type_,name), \
  name \
  ) \
/**/
  
/// Expands to a metafunction which tests whether an inner class template with a particular name exists.
/**

    trait = the name of the metafunction within the tti namespace.<br />
    name  = the name of the inner template.

    returns = a metafunction called "tti::trait" where 'trait' is the macro parameter.
    
              The metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' template exists within the enclosing type,
                          otherwise 'value' is false.
                          
                The template must have all 'class' ( or 'typename' ) parameters types.
    
*/
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
  
/// Expands to a metafunction which tests whether an inner class template with a particular name exists.
/**

    name  = the name of the inner template.

    returns = a metafunction called "tti::has_template_name" where 'name' is the macro parameter.
    
              The metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' template exists within the enclosing type,
                          otherwise 'value' is false.
                          
                The template must have all 'class' ( or 'typename' ) parameters types.
    
*/
#define TTI_HAS_TEMPLATE(name) \
  TTI_TRAIT_HAS_TEMPLATE \
  ( \
  BOOST_PP_CAT(has_template_,name), \
  name \
  ) \
/**/

#if !defined(BOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE)
#if !BOOST_WORKAROUND(BOOST_MSVC, <= 1400)

/// Expands to a metafunction which tests whether an inner class template with a particular name and signature exists.
/**

    trait = the name of the metafunction within the tti namespace.<br />
    name  = the name of the inner class template.<br />
    tpSeq = a Boost PP sequence which has the class template parameters.
            Each part of the template parameters separated by a comma ( , )
            is put in a separate sequence element.<br />

    returns = a metafunction called "tti::trait" where 'trait' is the macro parameter.
    
              The metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' class template with the signature
                          as defined by the 'tpSeq' exists within the enclosing type,
                          otherwise 'value' is false.
    
*/
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

/// Expands to a metafunction which tests whether an inner class template with a particular name and signature exists.
/**

    trait = the name of the metafunction within the tti namespace.<br />
    name  = the name of the inner class template.<br />
    tpSeq = a Boost PP sequence which has the class template parameters.
            Each part of the template parameters separated by a comma ( , )
            is put in a separate sequence element.<br />

    returns = a metafunction called "tti::trait" where 'trait' is the macro parameter.
    
              The metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' class template with the signature
                          as defined by the 'tpSeq' exists within the enclosing type,
                          otherwise 'value' is false.
    
*/
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

/// Expands to a metafunction which tests whether an inner class template with a particular name and signature exists.
/**

    trait = the name of the metafunction within the tti namespace.<br />
    name  = the name of the inner class template.<br />
    tpSeq = a Boost PP sequence which has the class template parameters.
            Each part of the template parameters separated by a comma ( , )
            is put in a separate sequence element.<br />

    returns = a metafunction called "tti::trait" where 'trait' is the macro parameter.
    
              The metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' class template with the signature
                          as defined by the 'tpSeq' exists within the enclosing type,
                          otherwise 'value' is false.
    
*/
#define TTI_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(trait,name,tpSeq) \
TTI_DETAIL_SAME(trait,name) \
/**/

#endif // !defined(BOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE)

/// Expands to a metafunction which tests whether an inner class template with a particular name and signature exists.
/**

    name  = the name of the inner class template.<br />
    tpSeq = a Boost PP sequence which has the class template parameters.
            Each part of the template parameters separated by a comma ( , )
            is put in a separate sequence element.

    returns = a metafunction called "tti::has_template_check_params_name" where 'name' is the macro parameter.
    
              The metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' class template with the signature
                          as defined by the 'tpSeq' exists within the enclosing type,
                          otherwise 'value' is false.
    
*/
#define TTI_HAS_TEMPLATE_CHECK_PARAMS(name,tpSeq) \
  TTI_TRAIT_HAS_TEMPLATE_CHECK_PARAMS \
  ( \
  BOOST_PP_CAT(has_template_check_params_,name), \
  name, \
  tpSeq \
  ) \
/**/

#if defined(BOOST_MSVC)

#if defined(BOOST_NO_NULLPTR)

/// Expands to a metafunction which tests whether a member data or member function with a particular name and type exists.
/**

    trait = the name of the metafunction within the tti namespace.<br />
    name  = the name of the inner member.

    returns = a metafunction called "tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction types and return:
    
                T = the type, in the form of a member data pointer or member function pointer, 
                    in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
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
  } \
/**/

#else // !defined(BOOST_NO_NULLPTR)

/// Expands to a metafunction which tests whether a member data or member function with a particular name and type exists.
/**

    trait = the name of the metafunction within the tti namespace.<br />
    name  = the name of the inner member.

    returns = a metafunction called "tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction types and return:
    
                T = the type, in the form of a member data pointer or member function pointer, 
                    in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
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
  } \
/**/

#endif // defined(BOOST_NO_NULLPTR)

#else // !defined(BOOST_MSVC)

#if defined(BOOST_NO_NULLPTR)

/// Expands to a metafunction which tests whether a member data or member function with a particular name and type exists.
/**

    trait = the name of the metafunction within the tti namespace.<br />
    name  = the name of the inner member.

    returns = a metafunction called "tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction types and return:
    
                T = the type, in the form of a member data pointer or member function pointer, 
                    in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
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

#else // !defined(BOOST_NO_NULLPTR)

/// Expands to a metafunction which tests whether a member data or member function with a particular name and type exists.
/**

    trait = the name of the metafunction within the tti namespace.<br />
    name  = the name of the inner member.

    returns = a metafunction called "tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction types and return:
    
                T = the type, in the form of a member data pointer or member function pointer, 
                    in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
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

#endif // defined(BOOST_MSVC)

/// Expands to a metafunction which tests whether a member data or member function with a particular name and type exists.
/**

    name  = the name of the inner member.

    returns = a metafunction called "tti::has_member_name" where 'name' is the macro parameter.
    
              The metafunction types and return:
    
                T = the type, in the form of a member data pointer or member function pointer, 
                    in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define TTI_HAS_MEMBER(name) \
  TTI_TRAIT_HAS_MEMBER \
  ( \
  BOOST_PP_CAT(has_member_,name), \
  name \
  ) \
/**/

#if defined(BOOST_NO_NULLPTR)

/// Expands to a metafunction which tests whether a static member data or a static member function with a particular name and type exists.
/**

    trait = the name of the metafunction within the tti namespace.<br />
    name  = the name of the inner member.

    returns = a metafunction called "tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction types and return:
    
                T    = the enclosing type.<br />
                Type = the static member data or static member function type,
                       in the form of a data or function type,
                       in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' exists within the enclosing type,
                          with the appropriate type,
                          otherwise 'value' is false.
                          
*/
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

/// Expands to a metafunction which tests whether a static member data or a static member function with a particular name and type exists.
/**

    trait = the name of the metafunction within the tti namespace.<br />
    name  = the name of the inner member.

    returns = a metafunction called "tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction types and return:
    
                T    = the enclosing type.<br />
                Type = the static member data or static member function type,
                       in the form of a data or function type,
                       in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' exists within the enclosing type,
                          with the appropriate type,
                          otherwise 'value' is false.
                          
*/
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
  
/// Expands to a metafunction which tests whether a static member data or a static member function with a particular name and type exists.
/**

    name  = the name of the inner member.

    returns = a metafunction called "tti::has_static_member_name" where 'name' is the macro parameter.<br />
    
              The metafunction types and return:
    
                T    = the enclosing type.<br />
                Type = the static member data or static member function type,
                       in the form of a data or function type,
                       in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' exists within the enclosing type,
                          with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define TTI_HAS_STATIC_MEMBER(name) \
  TTI_TRAIT_HAS_STATIC_MEMBER \
  ( \
  BOOST_PP_CAT(has_static_member_,name), \
  name \
  ) \
/**/

namespace tti
  {
  
/// A metafunction which checks whether a type exists within an enclosing type and optionally is a particular type.
/**

    This metafunction takes all its types as nullary metafunctions whose typedef 'type' member is the actual type used.
    
    The metafunction types and return:

      HasType = Template class generated from the TTI_HAS_TYPE ( or TTI_TRAIT_HAS_TYPE ) macro.<br />
      T       = The enclosing type as a nullary metafunction.
      U       = the type of the inner type as a nullary metafunction, as an optional parameter.<br />
      
      returns = 'value' is true if the type exists within the enclosing type
                and, if type U is specified, the type is the same as the type U,
                otherwise 'value' is false.
                          
*/
  template
    <
    template<class,class> class HasType,
    class T,
    class U = boost::mpl::identity<tti::detail::notype>
    >
  struct mf_has_type :
    tti::detail::eval
      <
      HasType
        <
        T,
        U
        >
      >
    {
    };
    
/// A metafunction whose typedef 'type' is either the internal type or an unspecified type.
/**

    This metafunction takes all its types as nullary metafunctions whose typedef 'type' member is the actual type used.
    
    The metafunction types and return:

      MemberType = Template class generated from the TTI_MEMBER_TYPE ( or TTI_TRAIT_MEMBER_TYPE ) macro.<br />
      T          = The enclosing type as a nullary metafunction.
      
      returns = 'type' is the inner type of the 'name' in TTI_MEMBER_TYPE ( or TTI_TRAIT_MEMBER_TYPE ) 
                if the inner type exists within the enclosing type,
                else 'type' is an unspecified type.<br />
                'valid' is true if the inner type of 'name' exists
                within the enclosing type, else 'valid' is false.
                          
    The purpose of this metafunction is to encapsulate the 'name' type
    in TTI_MEMBER_TYPE ( or TTI_TRAIT_MEMBER_TYPE ) as the typedef 'type'
    of a metafunction, but only if it exists within the enclosing type. This allows for
    a lazy evaluation of inner type existence which can be used by other metafunctions
    in this library. 
    
    Furthermore this metafunction allows the enclosing type to be return type from either the 
    metafunction generated from TTI_MEMBER_TYPE ( or TTI_TRAIT_MEMBER_TYPE ) or from this 
    metafunction itself.
    
*/
  template
    <
    template<class> class MemberType,
    class T
    >
  struct mf_member_type :
    tti::detail::eval
      <
      MemberType
        <
        T
        >
      >
    {
    };
    
/// A metafunction which checks whether a class template exists within an enclosing type.
/**

    This metafunction takes all its types as nullary metafunctions whose typedef 'type' member is the actual type used.
    
    The metafunction types and return:

      HasTemplate = Template class generated from TTI_HAS_TEMPLATE ( TTI_TRAIT_HAS_TEMPLATE )<br />
      T           = The enclosing type as a nullary metafunction.
      
      returns = 'value' is true if the template exists within the enclosing type,
                otherwise 'value' is false.
                          
*/
  template
    <
    template<class> class HasTemplate,
    class T
    >
  struct mf_has_template :
    tti::detail::eval
      <
      HasTemplate
        <
        T
        >
      >
    {
    };
    
/// A metafunction which checks whether a member function exists within an enclosing type.
/**

    This metafunction takes all its types as nullary metafunctions whose typedef 'type' member is the actual type used.
    
    The metafunction types and return:

      HasMember = Template class generated from the TTI_HAS_MEMBER ( or TTI_TRAIT_HAS_MEMBER ) macro.<br />
      T         = The enclosing type as a nullary metafunction.<br />
      R         = The return type of the member function as a nullary metafunction.<br />
      P...      = The parameter types of the member function, each as a nullary metafunction.<br /> 
                  There can be up to TTI_MAX_PARAMETERS number of parameters. The default is 10.
      
      returns = 'value' is true if the member function exists within the enclosing type,
                otherwise 'value' is false.
                          
*/
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
    
/// A metafunction which checks whether a member data exists within an enclosing type.
/**

    This metafunction takes all its types as nullary metafunctions whose typedef 'type' member is the actual type used.
    
    The metafunction types and return:

      HasMember = Template class generated from the TTI_HAS_MEMBER ( or TTI_TRAIT_HAS_MEMBER ) macro.<br />
      T         = The enclosing type as a nullary metafunction.<br />
      R         = The type of the member data as a nullary metafunction.
      
      returns = 'value' is true if the member data exists within the enclosing type,
                otherwise 'value' is false.
                          
*/
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
    
/// A metafunction which checks whether a static member function exists within an enclosing type.
/**

    This metafunction takes all its types as nullary metafunctions whose typedef 'type' member is the actual type used.
    
    The metafunction types and return:

      HasStatic Member = Template class generated from the TTI_HAS_STATIC_MEMBER ( or TTI_TRAIT_HAS_STATIC_MEMBER ) macro.<br />
      T                = The enclosing type as a nullary metafunction.<br />
      R                = The return type of the static member function as a nullary metafunction.<br />
      P...             = The parameter types of the static member function, each as a nullary metafunction.<br /> 
                         There can be up to TTI_MAX_PARAMETERS number of parameters. The default is 10.
      
      returns = 'value' is true if the static member function exists within the enclosing type,
                otherwise 'value' is false.
                          
*/
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
    
/// A metafunction which checks whether a static member data exists within an enclosing type.
/**

    This metafunction takes all its types as nullary metafunctions whose typedef 'type' member is the actual type used.
    
    The metafunction types and return:

      HasStaticMember = Template class generated from the TTI_HAS_STATIC_MEMBER ( or TTI_TRAIT_HAS_STATIC_MEMBER ) macro.<br />
      T               = The enclosing type as a nullary metafunction.<br />
      R               = The type of the static member data as a nullary metafunction.
      
      returns = 'value' is true if the member data exists within the enclosing type,
                otherwise 'value' is false.
                          
*/
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
    
  }
  
#endif // TT_INTROSPECTION_HPP
