#if !defined(TTI_MEMBER_TYPE_HPP)
#define TTI_MEMBER_TYPE_HPP

#include <boost/config.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/type_traits/is_same.hpp>
#include "detail/dmem_type.hpp"
#include "detail/dnotype.hpp"

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/// Expands to a metafunction whose typedef 'type' is either the named type or an unspecified type.
/**

    trait = the name of the metafunction within the tti namespace.
    
    name  = the name of the inner type.

    returns = a metafunction called "boost::tti::trait" where 'trait' is the macro parameter.
    
              The metafunction types and return:
              
                T = the enclosing type.<br />
                
                returns = 'type' is the inner type of 'name' if the inner type exists
                          within the enclosing type, else 'type' is an unspecified type.<br />
                          
    The purpose of this macro is to encapsulate the 'name' type as the typedef 'type'
    of a metafunction, but only if it exists within the enclosing type. This allows for
    a lazy evaluation of inner type existence which can be used by other metafunctions
    in this library.
    
*/
#define BOOST_TTI_TRAIT_MEMBER_TYPE(trait,name) \
namespace boost \
  { \
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
        detail::trait<T>, \
        detail::member_type::trait<T>, \
        boost::mpl::identity<detail::notype> \
        > \
      { \
      }; \
    } \
  } \
/**/

/// Expands to a metafunction class whose typedef 'type' is either the named type or an unspecified type.
/**

    trait = the name of the metafunction class within the tti namespace.
    
    name  = the name of the inner type.

    returns = a metafunction class called "boost::tti::trait" where 'trait' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
              
                T = the enclosing type.
                
                returns = 'type' is the inner type of 'name' if the inner type exists
                          within the enclosing type, else 'type' is an unspecified type.<br />
                          
    The purpose of this macro is to encapsulate the 'name' type as the typedef 'type'
    of a metafunction class, but only if it exists within the enclosing type. This allows for
    a lazy evaluation of inner type existence which can be used by other metafunctions
    in this library.
    
*/
#define BOOST_TTI_MTFC_TRAIT_MEMBER_TYPE(trait,name) \
namespace boost \
  { \
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
          detail::trait<T>, \
          detail::member_type::trait<T>, \
          boost::mpl::identity<detail::notype> \
          > \
        { \
        }; \
      }; \
    } \
  } \
/**/

/// Expands to a metafunction whose typedef 'type' is either the named type or an unspecified type.
/**

    name  = the name of the inner type.

    returns = a metafunction called "boost::tti::member_type_name" where 'name' is the macro parameter.
    
              The metafunction types and return:
              
                T = the enclosing type.
                
                returns = 'type' is the inner type of 'name' if the inner type exists
                          within the enclosing type, else 'type' is an unspecified type.
                          
    The purpose of this macro is to encapsulate the 'name' type as the typedef 'type'
    of a metafunction, but only if it exists within the enclosing type. This allows for
    a lazy evaluation of inner type existence which can be used by other metafunctions
    in this library.
    
*/
#define BOOST_TTI_MEMBER_TYPE(name) \
  BOOST_TTI_TRAIT_MEMBER_TYPE \
  ( \
  BOOST_PP_CAT(member_type_,name), \
  name \
  ) \
/**/
  
/// Expands to a metafunction class whose typedef 'type' is either the named type or an unspecified type.
/**

    name  = the name of the inner type.

    returns = a metafunction class called "boost::tti::mtfc_member_type_name" where 'name' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
              
                T = the enclosing type.
                
                returns = 'type' is the inner type of 'name' if the inner type exists
                          within the enclosing type, else 'type' is an unspecified type.
                          
    The purpose of this macro is to encapsulate the 'name' type as the typedef 'type'
    of a metafunction class, but only if it exists within the enclosing type. This allows for
    a lazy evaluation of inner type existence which can be used by other metafunctions
    in this library.
    
*/
#define BOOST_TTI_MTFC_MEMBER_TYPE(name) \
  BOOST_TTI_MTFC_TRAIT_MEMBER_TYPE \
  ( \
  BOOST_PP_CAT(mtfc_member_type_,name), \
  name \
  ) \
/**/

namespace boost
  {
  namespace tti
    {
  
    /// A metafunction which checks whether the member 'type' returned from invoking the macro metafunction generated by TTI_MEMBER_TYPE ( TTI_TRAIT_MEMBER_TYPE ) or from invoking boost::tti::mf_member_type is a valid type.
    /**

        The metafunction types and return:

          T       = returned inner 'type' from invoking the macro metafunction generated by TTI_MEMBER_TYPE ( TTI_TRAIT_MEMBER_TYPE ) or from invoking boost::tti::mf_member_type.
      
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
      
    /// A metafunction which checks whether the member 'type' returned from invoking the macro metafunction generated by TTI_MEMBER_TYPE ( TTI_TRAIT_MEMBER_TYPE ) or from invoking boost::tti::mf_member_type is a valid type.
    /**

        The metafunction types and return:

          T       = the nullary metafunction from invoking the macro metafunction generated by TTI_MEMBER_TYPE ( TTI_TRAIT_MEMBER_TYPE ) or from invoking boost::tti::mf_member_type.
      
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
      
    /// A metafunction whose typedef 'type' is either the internal type or an unspecified type.
    /**

        This metafunction takes its enclosing type as a nullary metafunction whose typedef 'type' member is the actual type used.
    
        The metafunction types and return:

          MemberType = a Boost MPL lambda expression using the metafunction generated from the TTI_MEMBER_TYPE ( or TTI_TRAIT_MEMBER_TYPE ) macro.<br />
                       The easiest way to generate the lambda expression is to use a Boost MPL placeholder expression of the form 'metafunction\<_\>'.
                       You can also use the metafunction class generated by the TTI_MTFC_MEMBER_TYPE ( or TTI_MTFC_TRAIT_MEMBER_TYPE ) macro.
                       
          T          = the enclosing type as a nullary metafunction.
      
          returns = 'type' is the inner type of the 'name' in TTI_MEMBER_TYPE ( or TTI_TRAIT_MEMBER_TYPE ) 
                    if the inner type exists within the enclosing type,
                    else 'type' is an unspecified type.
                          
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
    
    }
  }
  
#endif // TTI_MEMBER_TYPE_HPP
