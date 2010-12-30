#if !defined(TT_INTROSPECTION_TEMPLATE_HPP)
#define TT_INTROSPECTION_TEMPLATE_HPP

#include "detail/TTIntrospectionDetail.hpp"

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

namespace tti
  {
  
/// A metafunction which checks whether a class template exists within an enclosing type.
/**

    This metafunction takes all its types as nullary metafunctions whose typedef 'type' member is the actual type used.
    
    The metafunction types and return:

      HasTemplate = Template class generated from either TTI_HAS_TEMPLATE ( or TTI_TRAIT_HAS_TEMPLATE ) 
                    or TTI_HAS_TEMPLATE_CHECK_PARAMS ( or TTI_TRAIT_HAS_TEMPLATE_CHECK_PARAMS ) 
                    or TTI_VM_HAS_TEMPLATE_CHECK_PARAMS ( or TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS ) macros.<br />
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
    
  }
  
#endif // TT_INTROSPECTION_TEMPLATE_HPP
