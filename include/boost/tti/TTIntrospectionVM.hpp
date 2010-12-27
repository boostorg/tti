#if !defined(TT_INTROSPECTION_VM_HPP)
#define TT_INTROSPECTION_VM_HPP

#include <boost/config.hpp>
#include <boost/mpl/has_xxx.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/add.hpp>
#include <boost/variadic_macro_data/VariadicMacroData.hpp>
#include "detail/TTIntrospectionDetail.hpp"

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

#if !defined(BOOST_NO_VARIADIC_MACROS)
#if !defined(BOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE)
#if !BOOST_WORKAROUND(BOOST_MSVC, <= 1400)

/// Expands to a metafunction which tests whether an inner class template with a particular name and signature exists.
/**

    trait = the name of the metafunction within the tti namespace.<br />
    name  = the name of the inner class template.<br />
    ...   = variadic macro data which has the class template parameters.

    returns = a metafunction called "tti::trait" where 'trait' is the macro parameter.
    
              The metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' class template, with the signature
                          as defined by the '...' variadic macro data, exists within the enclosing type,
                          otherwise 'value' is false.
    
*/
#define TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(trait,name,...) \
namespace tti \
  { \
  TTI_DETAIL_HAS_MEMBER_WITH_FUNCTION_SFINAE \
    (  \
      ( BOOST_PP_ADD(VMD_DATA_SIZE(__VA_ARGS__),4), ( trait, name, 1, false, __VA_ARGS__ ) )  \
    )  \
  } \
/**/

#else // !!BOOST_WORKAROUND(BOOST_MSVC, <= 1400)

/// Expands to a metafunction which tests whether an inner class template with a particular name and signature exists.
/**

    trait = the name of the metafunction within the tti namespace.<br />
    name  = the name of the inner class template.<br />
    ...   = variadic macro data which has the class template parameters.

    returns = a metafunction called "tti::trait" where 'trait' is the macro parameter.
    
              The metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' class template, with the signature
                          as defined by the '...' variadic macro data, exists within the enclosing type,
                          otherwise 'value' is false.
    
*/
#define TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(trait,name,...) \
namespace tti \
  { \
  TTI_DETAIL_HAS_MEMBER_WITH_TEMPLATE_SFINAE \
    ( \
      ( BOOST_PP_ADD(VMD_DATA_SIZE(__VA_ARGS__),4), ( trait, name, 1, false, __VA_ARGS__ ) )  \
    ) \
  } \
/**/

#endif // !BOOST_WORKAROUND(BOOST_MSVC, <= 1400)
#else // !!defined(BOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE)

/// Expands to a metafunction which tests whether an inner class template with a particular name and signature exists.
/**

    trait = the name of the metafunction within the tti namespace.<br />
    name  = the name of the inner class template.<br />
    ...   = variadic macro data which has the class template parameters.

    returns = a metafunction called "tti::trait" where 'trait' is the macro parameter.
    
              The metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' class template, with the signature
                          as defined by the '...' variadic macro data, exists within the enclosing type,
                          otherwise 'value' is false.
    
*/
#define TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(trait,name,...) \
TTI_DETAIL_SAME(trait,name) \
/**/

#endif // !defined(BOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE)

/// Expands to a metafunction which tests whether an inner class template with a particular name and signature exists.
/**

    name  = the name of the inner class template.<br />
    ...   = variadic macro data which has the class template parameters.

    returns = a metafunction called "tti::has_template_check_params_name" where 'name' is the macro parameter.
    
              The metafunction types and return:
    
                T = the enclosing type in which to look for our 'name'.<br />
                returns = 'value' is true if the 'name' class template, with the signature
                          as defined by the '...' variadic macro data, exists within the enclosing type,
                          otherwise 'value' is false.
    
*/
#define TTI_VM_HAS_TEMPLATE_CHECK_PARAMS(name,...) \
  TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS \
  ( \
  BOOST_PP_CAT(has_template_check_params_,name), \
  name, \
  __VA_ARGS__ \
  ) \
/**/

#endif // !defined(BOOST_NO_VARIADIC_MACROS)
#endif // TT_INTROSPECTION_VM_HPP
