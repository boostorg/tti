#if !defined(TT_INTROSPECTION_HPP)
#define TT_INTROSPECTION_HPP

#include <boost/config.hpp>
#include <boost/function_types/property_tags.hpp>
#include <boost/mpl/has_xxx.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#include "mf_template_params.hpp"
#include "detail/dtti.hpp"

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
    TTI_DETAIL_TRAIT_HAS_TYPE(trait,name) \
    } \
  template<class T,class U = tti::detail::notype> \
  struct trait : \
    detail::trait \
      < \
      T, \
      U, \
      typename detail::mpl::trait<T>::type \
      > \
    { \
    }; \
  } \
/**/

/// Expands to a metafunction class which tests whether an inner type with a particular name exists and optionally is a particular type.
/**

    trait = the name of the metafunction class within the tti namespace.<br />
    name  = the name of the inner type.

    returns = a metfunction class called "tti::trait" where 'trait' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                U = the type of the inner type named 'name' as an optional parameter.<br />
                returns = 'value' is true if the 'name' type exists within the enclosing type
                          and, if type U is specified, the 'name' type is the same as the type U,
                          otherwise 'value' is false.
    
*/
#define TTI_MTFC_TRAIT_HAS_TYPE(trait,name) \
namespace tti \
  { \
  namespace detail \
    { \
    TTI_DETAIL_TRAIT_HAS_TYPE(trait,name) \
    } \
  struct trait \
    { \
    template<class T,class U = tti::detail::notype> \
    struct apply : \
      detail::trait \
        < \
        T, \
        U, \
        typename detail::mpl::trait<T>::type \
        > \
      { \
      }; \
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

/// Expands to a metafunction class which tests whether an inner type with a particular name exists and optionally is a particular type.
/**

    name  = the name of the inner type.

    returns = a metafunction class called "tti::mtfc_has_type_name" where 'name' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                U = the type of the inner type named 'name' as an optional parameter.<br />
                returns = 'value' is true if the 'name' type exists within the enclosing type
                          and, if type U is specified, the 'name' type is the same as the type U,
                          otherwise 'value' is false.
    
*/
#define TTI_MTFC_HAS_TYPE(name) \
  TTI_MTFC_TRAIT_HAS_TYPE \
  ( \
  BOOST_PP_CAT(mtfc_has_type_,name), \
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
    TTI_DETAIL_TRAIT_HAS_TYPE_MEMBER_TYPE(trait,name) \
    TTI_DETAIL_TRAIT_MEMBER_TYPE(trait,name) \
    } \
  template<class T> \
  struct trait : \
    boost::mpl::eval_if \
      < \
      tti::detail::trait<T>, \
      tti::detail::member_type::trait<T>, \
      boost::mpl::identity<tti::detail::notype> \
      > \
    { \
    }; \
  } \
/**/

/// Expands to a metafunction class whose typedef 'type' is either the named type or an unspecified type.
/**

    trait = the name of the metafunction class within the tti namespace.<br />
    name  = the name of the inner type.

    returns = a metafunction class called "tti::trait" where 'trait' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
              
                T = the enclosing type.<br />
                returns = 'type' is the inner type of 'name' if the inner type exists
                          within the enclosing type, else 'type' is an unspecified type.<br />
                          
    The purpose of this macro is to encapsulate the 'name' type as the typedef 'type'
    of a metafunction class, but only if it exists within the enclosing type. This allows for
    a lazy evaluation of inner type existence which can be used by other metafunctions
    in this library.
    
*/
#define TTI_MTFC_TRAIT_MEMBER_TYPE(trait,name) \
namespace tti \
  { \
  namespace detail \
    { \
    TTI_DETAIL_TRAIT_HAS_TYPE_MEMBER_TYPE(trait,name) \
    TTI_DETAIL_TRAIT_MEMBER_TYPE(trait,name) \
    } \
  struct trait \
    { \
    template<class T> \
    struct apply : \
      boost::mpl::eval_if \
        < \
        tti::detail::trait<T>, \
        tti::detail::member_type::trait<T>, \
        boost::mpl::identity<tti::detail::notype> \
        > \
      { \
      }; \
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
  
/// Expands to a metafunction class whose typedef 'type' is either the named type or an unspecified type.
/**

    name  = the name of the inner type.

    returns = a metafunction class called "tti::mtfc_member_type_name" where 'name' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
              
                T = the enclosing type.<br />
                returns = 'type' is the inner type of 'name' if the inner type exists
                          within the enclosing type, else 'type' is an unspecified type.<br />
                          
    The purpose of this macro is to encapsulate the 'name' type as the typedef 'type'
    of a metafunction class, but only if it exists within the enclosing type. This allows for
    a lazy evaluation of inner type existence which can be used by other metafunctions
    in this library.
    
*/
#define TTI_MTFC_MEMBER_TYPE(name) \
  TTI_MTFC_TRAIT_MEMBER_TYPE \
  ( \
  BOOST_PP_CAT(mtfc_member_type_,name), \
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
  struct trait : \
    tti::detail::trait<T> \
    { \
    }; \
  } \
/**/
  
/// Expands to a metafunction class which tests whether an inner class template with a particular name exists.
/**

    trait = the name of the metafunction class within the tti namespace.<br />
    name  = the name of the inner template.

    returns = a metafunction class called "tti::trait" where 'trait' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' template exists within the enclosing type,
                          otherwise 'value' is false.
                          
                The template must have all 'class' ( or 'typename' ) parameters types.
    
*/
#define TTI_MTFC_TRAIT_HAS_TEMPLATE(trait,name) \
namespace tti \
  { \
  namespace detail \
    { \
    BOOST_MPL_HAS_XXX_TEMPLATE_NAMED_DEF(trait, name, false) \
    } \
  struct trait \
    { \
    template<class T> \
    struct apply : \
      tti::detail::trait<T> \
      { \
      }; \
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

/// Expands to a metafunction class which tests whether an inner class template with a particular name exists.
/**

    name  = the name of the inner template.

    returns = a metafunction class called "tti::mtfc_has_template_name" where 'name' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' template exists within the enclosing type,
                          otherwise 'value' is false.
                          
                The template must have all 'class' ( or 'typename' ) parameters types.
    
*/
#define TTI_MTFC_HAS_TEMPLATE(name) \
  TTI_MTFC_TRAIT_HAS_TEMPLATE \
  ( \
  BOOST_PP_CAT(mtfc_has_template_,name), \
  name \
  ) \
/**/

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
  namespace detail \
    { \
    TTI_DETAIL_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(trait,name,tpSeq) \
    } \
  template<class T> \
  struct trait : \
    detail::trait<T> \
    { \
    }; \
  } \
/**/

/// Expands to a metafunction class which tests whether an inner class template with a particular name and signature exists.
/**

    trait = the name of the metafunction class within the tti namespace.<br />
    name  = the name of the inner class template.<br />
    tpSeq = a Boost PP sequence which has the class template parameters.
            Each part of the template parameters separated by a comma ( , )
            is put in a separate sequence element.<br />

    returns = a metafunction class called "tti::trait" where 'trait' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' class template with the signature
                          as defined by the 'tpSeq' exists within the enclosing type,
                          otherwise 'value' is false.
    
*/
#define TTI_MTFC_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(trait,name,tpSeq) \
namespace tti \
  { \
  namespace detail \
    { \
    TTI_DETAIL_MTFC_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(trait,name,tpSeq) \
    } \
  struct trait \
    { \
    template<class T> \
    struct apply : \
      detail::trait::apply<T> \
      { \
      }; \
    }; \
  } \
/**/

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

/// Expands to a metafunction class which tests whether an inner class template with a particular name and signature exists.
/**

    name  = the name of the inner class template.<br />
    tpSeq = a Boost PP sequence which has the class template parameters.
            Each part of the template parameters separated by a comma ( , )
            is put in a separate sequence element.

    returns = a metafunction class called "tti::mtfc_has_template_check_params_name" where 'name' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' class template with the signature
                          as defined by the 'tpSeq' exists within the enclosing type,
                          otherwise 'value' is false.
    
*/
#define TTI_MTFC_HAS_TEMPLATE_CHECK_PARAMS(name,tpSeq) \
  TTI_MTFC_TRAIT_HAS_TEMPLATE_CHECK_PARAMS \
  ( \
  BOOST_PP_CAT(mtfc_has_template_check_params_,name), \
  name, \
  tpSeq \
  ) \
/**/

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
  namespace detail \
    { \
    TTI_DETAIL_TRAIT_HAS_MEMBER(trait,name) \
    } \
  template<class T> \
  struct trait : \
    detail::trait<T> \
    { \
    }; \
  } \
/**/

/// Expands to a metafunction class which tests whether a member data or member function with a particular name and type exists.
/**

    trait = the name of the metafunction class within the tti namespace.<br />
    name  = the name of the inner member.

    returns = a metafunction class called "tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction class's 'apply' metafunction types and return:
    
                T = the type, in the form of a member data pointer or member function pointer, 
                    in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define TTI_MTFC_TRAIT_HAS_MEMBER(trait,name) \
namespace tti \
  { \
  namespace detail \
    { \
    TTI_DETAIL_TRAIT_HAS_MEMBER(trait,name) \
    } \
  struct trait \
    { \
    template<class T> \
    struct apply : \
      detail::trait<T> \
      { \
      }; \
    }; \
  } \
/**/

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

/// Expands to a metafunction class which tests whether a member data or member function with a particular name and type exists.
/**

    name  = the name of the inner member.

    returns = a metafunction class called "tti::mtfc_has_member_name" where 'name' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T = the type, in the form of a member data pointer or member function pointer, 
                    in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define TTI_MTFC_HAS_MEMBER(name) \
  TTI_MTFC_TRAIT_HAS_MEMBER \
  ( \
  BOOST_PP_CAT(mtfc_has_member_,name), \
  name \
  ) \
/**/

/// Expands to a metafunction which tests whether a member function with a particular name and signature exists.
/**

    trait = the name of the metafunction within the tti namespace.<br />
    name  = the name of the inner member.

    returns = a metafunction called "tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.<br />
                R   = the return type of the member function.<br />
                FS  = an optional parameter which are the parameters of the member function as a boost::mpl forward sequence.<br />
                TAG = an optional parameter which is a boost::function_types tag to apply to the member function.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define TTI_TRAIT_HAS_MEMBER_FUNCTION(trait,name) \
namespace tti \
  { \
  namespace detail \
    { \
    TTI_DETAIL_TRAIT_HAS_MEMBER_FUNCTION(trait,name) \
    } \
  template<class T,class R,class FS = boost::mpl::vector<>,class TAG = boost::function_types::null_tag> \
  struct trait : \
    detail::trait<typename detail::ptmf_seq<T,R,FS,TAG>::type,typename boost::remove_const<T>::type> \
    { \
    }; \
  } \
/**/

/// Expands to a metafunction class which tests whether a member function with a particular name and signature exists.
/**

    trait = the name of the metafunction class within the tti namespace.<br />
    name  = the name of the inner member.

    returns = a metafunction class called "tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction class's 'apply' metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.<br />
                R   = the return type of the member function.<br />
                FS  = an optional parameter which are the parameters of the member function as a boost::mpl forward sequence.<br />
                TAG = an optional parameter which is a boost::function_types tag to apply to the member function.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define TTI_MTFC_TRAIT_HAS_MEMBER_FUNCTION(trait,name) \
namespace tti \
  { \
  namespace detail \
    { \
    TTI_DETAIL_TRAIT_HAS_MEMBER_FUNCTION(trait,name) \
    } \
  struct trait \
    { \
    template<class T,class R,class FS = boost::mpl::vector<>,class TAG = boost::function_types::null_tag> \
    struct apply : \
      detail::trait<typename detail::ptmf_seq<T,R,FS,TAG>::type,typename boost::remove_const<T>::type> \
      { \
      }; \
    }; \
  } \
/**/

/// Expands to a metafunction which tests whether a member function with a particular name and signature exists.
/**

    name  = the name of the inner member.

    returns = a metafunction called "tti::has_member_function_name" where 'name' is the macro parameter.
    
              The metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.<br />
                R   = the return type of the member function.<br />
                FS  = an optional parameter which are the parameters of the member function as a boost::mpl forward sequence.<br />
                TAG = an optional parameter which is a boost::function_types tag to apply to the member function.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define TTI_HAS_MEMBER_FUNCTION(name) \
  TTI_TRAIT_HAS_MEMBER_FUNCTION \
  ( \
  BOOST_PP_CAT(has_member_function_,name), \
  name \
  ) \
/**/

/// Expands to a metafunction class which tests whether a member function with a particular name and signature exists.
/**

    name  = the name of the inner member.

    returns = a metafunction class called "tti::mtfc_has_member_function_name" where 'name' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.<br />
                R   = the return type of the member function.<br />
                FS  = an optional parameter which are the parameters of the member function as a boost::mpl forward sequence.<br />
                TAG = an optional parameter which is a boost::function_types tag to apply to the member function.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define TTI_MTFC_HAS_MEMBER_FUNCTION(name) \
  TTI_MTFC_TRAIT_HAS_MEMBER_FUNCTION \
  ( \
  BOOST_PP_CAT(mtfc_has_member_function_,name), \
  name \
  ) \
/**/

/// Expands to a metafunction which tests whether a member data with a particular name and type exists.
/**

    trait = the name of the metafunction within the tti namespace.<br />
    name  = the name of the inner member.

    returns = a metafunction called "tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.<br />
                R   = the type of the member data.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define TTI_TRAIT_HAS_MEMBER_DATA(trait,name) \
namespace tti \
  { \
  namespace detail \
    { \
    TTI_DETAIL_TRAIT_HAS_MEMBER_DATA(trait,name) \
    } \
  template<class T,class R> \
  struct trait : \
    detail::trait<typename detail::ptmd<T,R>::type,typename boost::remove_const<T>::type> \
    { \
    }; \
  } \
/**/

/// Expands to a metafunction class which tests whether a member data with a particular name and type exists.
/**

    trait = the name of the metafunction class within the tti namespace.<br />
    name  = the name of the inner member.

    returns = a metafunction class called "tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction class's 'apply' metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.<br />
                R   = the type of the member data.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define TTI_MTFC_TRAIT_HAS_MEMBER_DATA(trait,name) \
namespace tti \
  { \
  namespace detail \
    { \
    TTI_DETAIL_TRAIT_HAS_MEMBER_DATA(trait,name) \
    } \
  struct trait \
    { \
    template<class T,class R> \
    struct apply : \
      detail::trait<typename detail::ptmd<T,R>::type,typename boost::remove_const<T>::type> \
      { \
      }; \
    }; \
  } \
/**/

/// Expands to a metafunction which tests whether a member data with a particular name and type exists.
/**

    name  = the name of the inner member.

    returns = a metafunction called "tti::has_member_data_name" where 'name' is the macro parameter.
    
              The metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.<br />
                R   = the type of the member data.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define TTI_HAS_MEMBER_DATA(name) \
  TTI_TRAIT_HAS_MEMBER_DATA \
  ( \
  BOOST_PP_CAT(has_member_data_,name), \
  name \
  ) \
/**/

/// Expands to a metafunction class which tests whether a member data with a particular name and type exists.
/**

    name  = the name of the inner member.

    returns = a metafunction class called "tti::mtfc_has_member_data_name" where 'name' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.<br />
                R   = the type of the member data.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define TTI_MTFC_HAS_MEMBER_DATA(name) \
  TTI_MTFC_TRAIT_HAS_MEMBER_DATA \
  ( \
  BOOST_PP_CAT(mtfc_has_member_data_,name), \
  name \
  ) \
/**/

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
  namespace detail \
    { \
    TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER(trait,name) \
    } \
  template<class T,class Type> \
  struct trait : \
    detail::trait<T,Type> \
    { \
    }; \
  } \
/**/

/// Expands to a metafunction class which tests whether a static member data or a static member function with a particular name and type exists.
/**

    trait = the name of the metafunction class within the tti namespace.<br />
    name  = the name of the inner member.

    returns = a metafunction class called "tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction class's 'apply' metafunction types and return:
    
                T    = the enclosing type.<br />
                Type = the static member data or static member function type,
                       in the form of a data or function type,
                       in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' exists within the enclosing type,
                          with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define TTI_MTFC_TRAIT_HAS_STATIC_MEMBER(trait,name) \
namespace tti \
  { \
  namespace detail \
    { \
    TTI_DETAIL_MTFC_TRAIT_HAS_STATIC_MEMBER(trait,name) \
    } \
  struct trait \
    { \
    template<class T,class Type> \
    struct apply : \
      detail::trait::apply<T,Type> \
      { \
      }; \
    }; \
  } \
/**/


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

/// Expands to a metafunction class which tests whether a static member data or a static member function with a particular name and type exists.
/**

    name  = the name of the inner member.

    returns = a metafunction class called "tti::mtfc_has_static_member_name" where 'name' is the macro parameter.<br />
    
              The metafunction class's 'apply' metafunction types and return:
    
                T    = the enclosing type.<br />
                Type = the static member data or static member function type,
                       in the form of a data or function type,
                       in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' exists within the enclosing type,
                          with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define TTI_MTFC_HAS_STATIC_MEMBER(name) \
  TTI_MTFC_TRAIT_HAS_STATIC_MEMBER \
  ( \
  BOOST_PP_CAT(mtfc_has_static_member_,name), \
  name \
  ) \
/**/

/// Expands to a metafunction which tests whether a static member function with a particular name and signature exists.
/**

    trait = the name of the metafunction within the tti namespace.<br />
    name  = the name of the inner member.

    returns = a metafunction called "tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.<br />
                R   = the return type of the static member function.<br />
                FS  = an optional parameter which are the parameters of the static member function as a boost::mpl forward sequence.<br />
                TAG = an optional parameter which is a boost::function_types tag to apply to the static member function.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define TTI_TRAIT_HAS_STATIC_MEMBER_FUNCTION(trait,name) \
namespace tti \
  { \
  namespace detail \
    { \
    TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION(trait,name) \
    } \
  template<class T,class R,class FS = boost::mpl::vector<>,class TAG = boost::function_types::null_tag> \
  struct trait : \
    detail::trait<T,typename detail::tfunction_seq<R,FS,TAG>::type> \
    { \
    }; \
  } \
/**/

/// Expands to a metafunction class which tests whether a static member function with a particular name and signature exists.
/**

    trait = the name of the metafunction class within the tti namespace.<br />
    name  = the name of the inner member.

    returns = a metafunction class called "tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction class's 'apply' metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.<br />
                R   = the return type of the static member function.<br />
                FS  = an optional parameter which are the parameters of the static member function as a boost::mpl forward sequence.<br />
                TAG = an optional parameter which is a boost::function_types tag to apply to the static member function.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define TTI_MTFC_TRAIT_HAS_STATIC_MEMBER_FUNCTION(trait,name) \
namespace tti \
  { \
  namespace detail \
    { \
    TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION(trait,name) \
    } \
  struct trait \
    { \
    template<class T,class R,class FS = boost::mpl::vector<>,class TAG = boost::function_types::null_tag> \
    struct apply : \
      detail::trait<T,typename detail::tfunction_seq<R,FS,TAG>::type> \
      { \
      }; \
    }; \
  } \
/**/

/// Expands to a metafunction which tests whether a static member function with a particular name and signature exists.
/**

    name  = the name of the inner member.

    returns = a metafunction called "tti::has_static_member_function_name" where 'name' is the macro parameter.
    
              The metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.<br />
                R   = the return type of the static member function.<br />
                FS  = an optional parameter which are the parameters of the static member function as a boost::mpl forward sequence.<br />
                TAG = an optional parameter which is a boost::function_types tag to apply to the static member function.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define TTI_HAS_STATIC_MEMBER_FUNCTION(name) \
  TTI_TRAIT_HAS_STATIC_MEMBER_FUNCTION \
  ( \
  BOOST_PP_CAT(has_static_member_function_,name), \
  name \
  ) \
/**/

/// Expands to a metafunction class which tests whether a static member function with a particular name and signature exists.
/**

    name  = the name of the inner member.

    returns = a metafunction class called "tti::mtfc_has_static_member_function_name" where 'name' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.<br />
                R   = the return type of the static member function.<br />
                FS  = an optional parameter which are the parameters of the static member function as a boost::mpl forward sequence.<br />
                TAG = an optional parameter which is a boost::function_types tag to apply to the static member function.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define TTI_MTFC_HAS_STATIC_MEMBER_FUNCTION(name) \
  TTI_MTFC_TRAIT_HAS_STATIC_MEMBER_FUNCTION \
  ( \
  BOOST_PP_CAT(mtfc_has_static_member_function_,name), \
  name \
  ) \
/**/

namespace tti
  {
  
/// A metafunction which checks whether the member 'type' returned from invoking the macro metafunction generated by TTI_MEMBER_TYPE ( TTI_TRAIT_MEMBER_TYPE ) or from invoking tti::mf_member_type is a valid type.
/**

    The metafunction types and return:

      T       = returned inner 'type' from invoking the macro metafunction generated by TTI_MEMBER_TYPE ( TTI_TRAIT_MEMBER_TYPE ) or from invoking tti::mf_member_type.
      
      returns = 'value' is true if the type is valid, otherwise 'value' is false.
                          
*/
  template
    <
    class T
    >
  struct valid_member_type :
    boost::mpl::not_
      <
      boost::is_same
        <
        T,
        detail::notype
        >
      >
    {
    };
      
/// A metafunction which checks whether the member 'type' returned from invoking the macro metafunction generated by TTI_MEMBER_TYPE ( TTI_TRAIT_MEMBER_TYPE ) or from invoking tti::mf_member_type is a valid type.
/**

    The metafunction types and return:

      T       = the nullary metafunction from invoking the macro metafunction generated by TTI_MEMBER_TYPE ( TTI_TRAIT_MEMBER_TYPE ) or from invoking tti::mf_member_type.
      
      returns = 'value' is true if the type is valid, otherwise 'value' is false.
                          
*/
  template
    <
    class T
    >
  struct mf_valid_member_type :
    boost::mpl::not_
      <
      boost::is_same
        <
        typename T::type,
        detail::notype
        >
      >
    {
    };
      
/// A metafunction which checks whether a type exists within an enclosing type and optionally is a particular type.
/**

    This metafunction takes its specific types as nullary metafunctions whose typedef 'type' member is the actual type used.
    
    The metafunction types and return:

      HasType = a Boost MPL lambda expression using the metafunction generated from the TTI_HAS_TYPE ( or TTI_TRAIT_HAS_TYPE ) macro.<br />
                The easiest way to generate the lambda expression is to use a Boost MPL placeholder expression of the form 'metafunction\<_\>' ( or optionally 'metafunction\<_,_\>' ).
                You can also use the metafunction class generated by the TTI_MTFC_HAS_TYPE ( or TTI_MTFC_TRAIT_HAS_TYPE ) macro.<br />
      T       = the enclosing type as a nullary metafunction.<br />
      U       = the type of the inner type as a nullary metafunction, as an optional parameter.
      
      returns = 'value' is true if the type exists within the enclosing type
                and, if type U is specified, the type is the same as the type U,
                otherwise 'value' is false.
                          
*/
  template
    <
    class HasType,
    class T,
    class U = boost::mpl::identity<tti::detail::notype>
    >
  struct mf_has_type :
    boost::mpl::apply
      <
      HasType,
      typename T::type,
      typename U::type
      >::type
    {
    };
    
/// A metafunction whose typedef 'type' is either the internal type or an unspecified type.
/**

    This metafunction takes its enclosing type as nullary metafunctions whose typedef 'type' member is the actual type used.
    
    The metafunction types and return:

      MemberType = a Boost MPL lambda expression using the metafunction generated from the TTI_MEMBER_TYPE ( or TTI_TRAIT_MEMBER_TYPE ) macro.<br />
                   The easiest way to generate the lambda expression is to use a Boost MPL placeholder expression of the form 'metafunction\<_\>'.
                   You can also use the metafunction class generated by the TTI_MTFC_MEMBER_TYPE ( or TTI_MTFC_TRAIT_MEMBER_TYPE ) macro.<br />
      T          = the enclosing type as a nullary metafunction.
      
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
    class MemberType,
    class T
    >
  struct mf_member_type :
    boost::mpl::apply
      <
      MemberType,
      typename T::type
      > 
    {
    };
    
/// A metafunction which checks whether a class template exists within an enclosing type.
/**

    This metafunction takes its enclosing type as nullary metafunctions whose typedef 'type' member is the actual type used.
    
    The metafunction types and return:

      HasTemplate = a Boost MPL lambda expression using the metafunction generated from the TTI_HAS_TEMPLATE ( TTI_TRAIT_HAS_TEMPLATE ) macro.<br />
                    The easiest way to generate the lambda expression is to use a Boost MPL placeholder expression of the form 'metafunction\<_\>'.
                    You can also use the metafunction class generated by the TTI_MTFC_HAS_TEMPLATE ( TTI_MTFC_TRAIT_HAS_TEMPLATE ) macro.<br />
      T           = the enclosing type as a nullary metafunction.
      
      returns = 'value' is true if the template exists within the enclosing type,
                otherwise 'value' is false.
                          
*/
  template
    <
    class HasTemplate,
    class T
    >
  struct mf_has_template :
    boost::mpl::apply
      <
      HasTemplate,
      typename T::type
      >::type 
    {
    };
    
/// A metafunction which checks whether a member function exists within an enclosing type.
/**

    This metafunction takes its specific types, except for the optional parameters, as nullary metafunctions whose typedef 'type' member is the actual type used.
    
    The metafunction types and return:

      HasMemberFunction = a Boost MPL lambda expression using the metafunction generated from the TTI_HAS_MEMBER_FUNCTION ( or TTI_TRAIT_HAS_MEMBER_FUNCTION ) macro.<br />
                          The easiest way to generate the lambda expression is to use a Boost MPL placeholder expression of the form 'metafunction\<_,_\> ( or optionally 'metafunction\<_,_,_\> or ' 'metafunction\<_,_,_,_\> )'.
                          You can also use the metafunction class generated by the TTI_MTFC_HAS_MEMBER_FUNCTION ( or TTI_MTFC_TRAIT_HAS_MEMBER_FUNCTION ) macro.<br />
      T         = the enclosing type as a nullary metafunction.<br />
      R         = the return type of the member function as a nullary metafunction.<br />
      FS        = an optional parameter which is the parameters of the member function, each as a nullary metafunction, as a boost::mpl forward sequence.<br />
                  This parameter defaults to boost::mpl::vector<>.<br />
      TAG       = an optional parameter which is a boost::function_types tag to apply to the member function.<br />
                  This parameter defaults to boost::function_types::null_tag.
      
      returns = 'value' is true if the member function exists within the enclosing type,
                otherwise 'value' is false.
                          
*/
  template
    <
    class HasMemberFunction,
    class T,
    class R,
    class FS = boost::mpl::vector<>,
    class TAG = boost::function_types::null_tag
    >
  struct mf_has_member_function :
    boost::mpl::apply
      <
      HasMemberFunction,
      typename T::type,
      typename R::type,
      typename boost::mpl::transform<FS,detail::tself<boost::mpl::_1> >::type,
      TAG
      >::type
    {
    };
    
/// A metafunction which checks whether a member data exists within an enclosing type.
/**

    This metafunction takes its specific types as nullary metafunctions whose typedef 'type' member is the actual type used.
    
    The metafunction types and return:

      HasMemberData = a Boost MPL lambda expression using the metafunction generated from the TTI_HAS_MEMBER_DATA ( or TTI_TRAIT_HAS_MEMBER_DATA ) macro.<br />
                      The easiest way to generate the lambda expression is to use a Boost MPL placeholder expression of the form 'metafunction\<_,_\>'.
                      You can also use the metafunction class generated by the TTI_MTFC_HAS_MEMBER_DATA ( or TTI_MTFC_TRAIT_HAS_MEMBER_DATA ) macro.<br />
      T         = the enclosing type as a nullary metafunction.<br />
      R         = the type of the member data as a nullary metafunction.
      
      returns = 'value' is true if the member data exists within the enclosing type,
                otherwise 'value' is false.
                          
*/
  template
    <
    class HasMemberData,
    class T,
    class R
    >
  struct mf_has_member_data :
    boost::mpl::apply
      <
      HasMemberData,
      typename T::type,
      typename R::type
      >::type 
    {
    };
    
/// A metafunction which checks whether a static member function exists within an enclosing type.
/**

    This metafunction takes its specific types, except for the optional parameters, as nullary metafunctions whose typedef 'type' member is the actual type used.
    
    The metafunction types and return:

      HasStaticMemberFunction = a Boost MPL lambda expression using the metafunction generated from the TTI_HAS_STATIC_MEMBER_FUNCTION ( or TTI_TRAIT_HAS_STATIC_MEMBER_FUNCTION ) macro.<br />
                                The easiest way to generate the lambda expression is to use a Boost MPL placeholder expression of the form 'metafunction\<_,_\> ( or optionally 'metafunction\<_,_,_\> or ' 'metafunction\<_,_,_,_\> )'.
                                You can also use the metafunction class generated by the TTI_MTFC_HAS_STATIC_MEMBER_FUNCTION ( or TTI_MTFC_TRAIT_HAS_STATIC_MEMBER_FUNCTION ) macro.<br />
      T               = the enclosing type as a nullary metafunction.<br />
      R               = the return type of the static member function as a nullary metafunction.<br />
      FS              = an optional parameter which is the parameters of the static member function, each as a nullary metafunction, as a boost::mpl forward sequence.<br />
      TAG             = an optional parameter which is a boost::function_types tag to apply to the static member function.
      
      returns = 'value' is true if the member function exists within the enclosing type,
                otherwise 'value' is false.
                          
*/
  template
    <
    class HasStaticMemberFunction,
    class T,
    class R,
    class FS = boost::mpl::vector<>,
    class TAG = boost::function_types::null_tag
    >
  struct mf_has_static_member_function :
    boost::mpl::apply
      <
      HasStaticMemberFunction,
      typename T::type,
      typename R::type,
      typename boost::mpl::transform<FS,detail::tself<boost::mpl::_1> >::type,
      TAG
      >::type
    {
    };
    
/// A metafunction which checks whether a static member data exists within an enclosing type.
/**

    This metafunction takes its specific types as nullary metafunctions whose typedef 'type' member is the actual type used.
    
    The metafunction types and return:

      HasStaticMember = a Boost MPL lambda expression using the metafunction generated from the TTI_HAS_STATIC_MEMBER ( or TTI_TRAIT_HAS_STATIC_MEMBER ) macro.<br />
                        The easiest way to generate the lambda expression is to use a Boost MPL placeholder expression of the form 'metafunction\<_,_\>'.
                        You can also use the metafunction class generated by the TTI_MTFC_HAS_STATIC_MEMBER ( or TTI_MTFC_TRAIT_HAS_STATIC_MEMBER ) macro.<br />
      T               = the enclosing type as a nullary metafunction.<br />
      R               = the type of the static member data as a nullary metafunction.
      
      returns = 'value' is true if the member data exists within the enclosing type,
                otherwise 'value' is false.
                          
*/
  template
    <
    class HasStaticMember,
    class T,
    class R
    >
  struct mf_has_static_data :
    boost::mpl::apply
      <
      HasStaticMember,
      typename T::type,
      typename R::type
      >::type 
    {
    };
  }
  
#endif // TT_INTROSPECTION_HPP
