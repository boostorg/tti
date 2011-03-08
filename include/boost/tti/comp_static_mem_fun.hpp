#if !defined(TTI_STATIC_MEMBER_HPP)
#define TTI_STATIC_MEMBER_HPP

#include <boost/config.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/preprocessor/cat.hpp>
#include "detail/dcomp_static_mem_fun.hpp"

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/// Expands to a metafunction which tests whether a static member function with a particular name and composite type exists.
/**

    trait = the name of the metafunction within the tti namespace.
    
    name  = the name of the inner member.

    returns = a metafunction called "boost::tti::trait" where 'trait' is the macro parameter.
    
              The metafunction types and return:
    
                T    = the enclosing type.
                
                Type = the static member function type,
                       in the form of a composite function type - 'return_type (parameter_types...)',
                       in which to look for our 'name'.
                       
                returns = 'value' is true if the 'name' exists within the enclosing type,
                          with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_TRAIT_HAS_STATIC_MEMBER(trait,name) \
namespace boost \
  { \
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
  } \
/**/

/// Expands to a metafunction class which tests whether a static member function with a particular name and composite type exists.
/**

    trait = the name of the metafunction class within the tti namespace.
    
    name  = the name of the inner member.

    returns = a metafunction class called "boost::tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction class's 'apply' metafunction types and return:
    
                T    = the enclosing type.
                
                Type = the static member function type,
                       in the form of a composite function type - 'return_type (parameter_types...)',
                       in which to look for our 'name'.
                       
                returns = 'value' is true if the 'name' exists within the enclosing type,
                          with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_MTFC_TRAIT_HAS_STATIC_MEMBER(trait,name) \
namespace boost \
  { \
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
  } \
/**/


/// Expands to a metafunction which tests whether a static member function with a particular name and composite type exists.
/**

    name  = the name of the inner member.

    returns = a metafunction called "boost::tti::has_static_member_name" where 'name' is the macro parameter.<br />
    
              The metafunction types and return:
    
                T    = the enclosing type.
                
                Type = the static member function type,
                       in the form of a composite function type - 'return_type (parameter_types...)',
                       in which to look for our 'name'.
                       
                returns = 'value' is true if the 'name' exists within the enclosing type,
                          with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_HAS_STATIC_MEMBER(name) \
  BOOST_TTI_TRAIT_HAS_STATIC_MEMBER \
  ( \
  BOOST_PP_CAT(has_static_member_,name), \
  name \
  ) \
/**/

/// Expands to a metafunction class which tests whether a static member function with a particular name and composite type exists.
/**

    name  = the name of the inner member.

    returns = a metafunction class called "boost::tti::mtfc_has_static_member_name" where 'name' is the macro parameter.<br />
    
              The metafunction class's 'apply' metafunction types and return:
    
                T    = the enclosing type.
                
                Type = the static member function type,
                       in the form of a composite function type - 'return_type (parameter_types...)',
                       in which to look for our 'name'.
                       
                returns = 'value' is true if the 'name' exists within the enclosing type,
                          with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_MTFC_HAS_STATIC_MEMBER(name) \
  BOOST_TTI_MTFC_TRAIT_HAS_STATIC_MEMBER \
  ( \
  BOOST_PP_CAT(mtfc_has_static_member_,name), \
  name \
  ) \
/**/

#endif // TTI_STATIC_MEMBER_HPP
