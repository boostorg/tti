#if !defined(TT_INTROSPECTION_TEMPLATE_HPP)
#define TT_INTROSPECTION_TEMPLATE_HPP

#include <boost/mpl/bool.hpp>
#include <boost/mpl/identity.hpp>
#include "detail/TTIntrospectionDetail.hpp"

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

namespace tti
  {
  
#if !defined(TTI_GNUC3)

/// A metafunction which checks whether a class template with its parameters exists within an enclosing type.
/**

    This metafunction takes all its types as nullary metafunctions whose typedef 'type' member is the actual type used.
    
    The metafunction types and return:

      HasTemplateCheckParams = Template class generated from either TTI_HAS_TEMPLATE_CHECK_PARAMS ( TTI_TRAIT_HAS_TEMPLATE_CHECK_PARAMS ) 
                    or TTI_VM_HAS_TEMPLATE_CHECK_PARAMS ( TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS ) macros.<br />
      T           = The enclosing type as a nullary metafunction.
      
      returns = 'value' is true if the template exists within the enclosing type,
                otherwise 'value' is false.
                          
*/
  template
    <
    template<class,class = boost::mpl::false_> class HasTemplateCheckParams,
    class T
    >
  struct mf_has_template_check_params :
    tti::detail::eval
      <
      HasTemplateCheckParams
        <
        T
        >
      >
    {
    };
    
#else

/// A metafunction which checks whether a class template with its parameters exists within an enclosing type.
/**

    This metafunction takes all its types as nullary metafunctions whose typedef 'type' member is the actual type used.
    
    The metafunction types and return:

      HasTemplateCheckParams = Template class generated from either TTI_HAS_TEMPLATE_CHECK_PARAMS ( TTI_TRAIT_HAS_TEMPLATE_CHECK_PARAMS ) 
                    or TTI_VM_HAS_TEMPLATE_CHECK_PARAMS ( TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS ) macros.<br />
      T           = The enclosing type as a nullary metafunction.
      
      returns = 'value' is true if the template exists within the enclosing type,
                otherwise 'value' is false.
                          
*/
  template
    <
    template<class,class = boost::mpl::false_> class HasTemplateCheckParams,
    class T
    >
  struct mf_has_template_check_params :
    tti::detail::eval_gcc3
      <
      HasTemplateCheckParams
        <
        T
        >,
      1
      >
    {
    };
    
#endif

  }
  
#endif // TT_INTROSPECTION_TEMPLATE_HPP
