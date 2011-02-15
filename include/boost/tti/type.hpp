#if !defined(TTI_TYPE_HPP)
#define TTI_TYPE_HPP

#include <boost/config.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/preprocessor/cat.hpp>
#include "detail/dtype.hpp"
#include "detail/dnotype.hpp"

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/// Expands to a metafunction which tests whether an inner type with a particular name exists and optionally is a particular type.
/**

    trait = the name of the metafunction within the tti namespace.<br />
    name  = the name of the inner type.

    returns = a metafunction called "boost::tti::trait" where 'trait' is the macro parameter.
    
              The metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                U = the type of the inner type named 'name' as an optional parameter.<br />
                returns = 'value' is true if the 'name' type exists within the enclosing type
                          and, if type U is specified, the 'name' type is the same as the type U,
                          otherwise 'value' is false.
    
*/
#define BOOST_TTI_TRAIT_HAS_TYPE(trait,name) \
namespace boost \
  { \
  namespace tti \
    { \
    namespace detail \
      { \
      TTI_DETAIL_TRAIT_HAS_TYPE(trait,name) \
      } \
    template<class T,class U = detail::notype> \
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
  } \
/**/

/// Expands to a metafunction class which tests whether an inner type with a particular name exists and optionally is a particular type.
/**

    trait = the name of the metafunction class within the tti namespace.<br />
    name  = the name of the inner type.

    returns = a metfunction class called "boost::tti::trait" where 'trait' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                U = the type of the inner type named 'name' as an optional parameter.<br />
                returns = 'value' is true if the 'name' type exists within the enclosing type
                          and, if type U is specified, the 'name' type is the same as the type U,
                          otherwise 'value' is false.
    
*/
#define BOOST_TTI_MTFC_TRAIT_HAS_TYPE(trait,name) \
namespace boost \
  { \
  namespace tti \
    { \
    namespace detail \
      { \
      TTI_DETAIL_TRAIT_HAS_TYPE(trait,name) \
      } \
    struct trait \
      { \
      template<class T,class U = detail::notype> \
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
  } \
/**/

/// Expands to a metafunction which tests whether an inner type with a particular name exists and optionally is a particular type.
/**

    name  = the name of the inner type.

    returns = a metafunction called "boost::tti::has_type_name" where 'name' is the macro parameter.
    
              The metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                U = the type of the inner type named 'name' as an optional parameter.<br />
                returns = 'value' is true if the 'name' type exists within the enclosing type
                          and, if type U is specified, the 'name' type is the same as the type U,
                          otherwise 'value' is false.
    
*/
#define BOOST_TTI_HAS_TYPE(name) \
  BOOST_TTI_TRAIT_HAS_TYPE \
  ( \
  BOOST_PP_CAT(has_type_,name), \
  name \
  ) \
/**/

/// Expands to a metafunction class which tests whether an inner type with a particular name exists and optionally is a particular type.
/**

    name  = the name of the inner type.

    returns = a metafunction class called "boost::tti::mtfc_has_type_name" where 'name' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                U = the type of the inner type named 'name' as an optional parameter.<br />
                returns = 'value' is true if the 'name' type exists within the enclosing type
                          and, if type U is specified, the 'name' type is the same as the type U,
                          otherwise 'value' is false.
    
*/
#define BOOST_TTI_MTFC_HAS_TYPE(name) \
  BOOST_TTI_MTFC_TRAIT_HAS_TYPE \
  ( \
  BOOST_PP_CAT(mtfc_has_type_,name), \
  name \
  ) \
/**/

namespace boost
  {
  namespace tti
    {
  
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
      class U = boost::mpl::identity<detail::notype>
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
    }
  }
  
#endif // TTI_TYPE_HPP
