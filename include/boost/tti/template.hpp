#if !defined(TTI_TEMPLATE_HPP)
#define TTI_TEMPLATE_HPP

#include <boost/config.hpp>
#include <boost/mpl/has_xxx.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/preprocessor/cat.hpp>
#include "gen/template_gen.hpp"

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/// Expands to a metafunction which tests whether an inner class template with a particular name exists.
/**

    trait = the name of the metafunction within the tti namespace.
    
    name  = the name of the inner template.

    returns = a metafunction called "boost::tti::trait" where 'trait' is the macro parameter.
    
              The metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.
                
                returns = 'value' is true if the 'name' template exists within the enclosing type,
                          otherwise 'value' is false.
                          
                The template must have all 'class' ( or 'typename' ) parameters types.
    
*/
#define BOOST_TTI_TRAIT_HAS_TEMPLATE(trait,name) \
namespace boost \
  { \
  namespace tti \
    { \
    namespace detail \
      { \
      BOOST_MPL_HAS_XXX_TEMPLATE_NAMED_DEF(trait, name, false) \
      } \
    template<class T> \
    struct trait : \
      detail::trait<T> \
      { \
      }; \
    } \
  } \
/**/
  
/// Expands to a metafunction class which tests whether an inner class template with a particular name exists.
/**

    trait = the name of the metafunction class within the tti namespace.
    
    name  = the name of the inner template.

    returns = a metafunction class called "boost::tti::trait" where 'trait' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.
                
                returns = 'value' is true if the 'name' template exists within the enclosing type,
                          otherwise 'value' is false.
                          
                The template must have all 'class' ( or 'typename' ) parameters types.
    
*/
#define BOOST_TTI_MTFC_TRAIT_HAS_TEMPLATE(trait,name) \
namespace boost \
  { \
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
        detail::trait<T> \
        { \
        }; \
      }; \
    } \
  } \
/**/
  
/// Expands to a metafunction which tests whether an inner class template with a particular name exists.
/**

    name  = the name of the inner template.

    returns = a metafunction called "boost::tti::has_template_name" where 'name' is the macro parameter.
    
              The metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.
                
                returns = 'value' is true if the 'name' template exists within the enclosing type,
                          otherwise 'value' is false.
                          
                The template must have all 'class' ( or 'typename' ) parameters types.
    
*/
#define BOOST_TTI_HAS_TEMPLATE(name) \
  BOOST_TTI_TRAIT_HAS_TEMPLATE \
  ( \
  BOOST_TTI_HAS_TEMPLATE_GEN_BASE(name), \
  name \
  ) \
/**/

/// Expands to a metafunction class which tests whether an inner class template with a particular name exists.
/**

    name  = the name of the inner template.

    returns = a metafunction class called "boost::tti::mtfc_has_template_name" where 'name' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.
                
                returns = 'value' is true if the 'name' template exists within the enclosing type,
                          otherwise 'value' is false.
                          
                The template must have all 'class' ( or 'typename' ) parameters types.
    
*/
#define BOOST_TTI_MTFC_HAS_TEMPLATE(name) \
  BOOST_TTI_MTFC_TRAIT_HAS_TEMPLATE \
  ( \
  BOOST_TTI_MTFC_HAS_TEMPLATE_GEN_BASE(name), \
  name \
  ) \
/**/

namespace boost
  {
  namespace tti
    {
  
    /// A metafunction which checks whether a class template exists within an enclosing type.
    /**

        This metafunction takes its enclosing type as nullary metafunctions whose typedef 'type' member is the actual type used.
    
        The metafunction types and return:

          HasTemplate = a Boost MPL lambda expression using the metafunction generated from the TTI_HAS_TEMPLATE ( TTI_TRAIT_HAS_TEMPLATE ) macro.<br />
                        The easiest way to generate the lambda expression is to use a Boost MPL placeholder expression of the form 'metafunction\<_\>'.
                        You can also use the metafunction class generated by the TTI_MTFC_HAS_TEMPLATE ( TTI_MTFC_TRAIT_HAS_TEMPLATE ) macro.
                        
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
    }
  }
  
#endif // TTI_TEMPLATE_HPP
