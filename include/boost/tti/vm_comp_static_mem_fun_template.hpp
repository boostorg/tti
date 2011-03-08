#if !defined(TTI_VM_COMP_STATIC_MEM_FUN_TEMPLATE_HPP)
#define TTI_VM_COMP_STATIC_MEM_FUN_TEMPLATE_HPP

#include <boost/config.hpp>

#if !defined(BOOST_NO_VARIADIC_MACROS)

#include <boost/mpl/apply.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/list/adt.hpp>
#include <boost/variadic_macro_data/vmd.hpp>
#include "detail/dcomp_static_mem_fun_template.hpp"

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/// Expands to a metafunction which tests whether a static member function template with a particular name/optional signature and composite type exists.
/**

    trait = the name of the metafunction within the tti namespace.
    
    ...   = variadic macro data which has the name and optionally the function template parameters.

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
#define BOOST_TTI_VM_TRAIT_HAS_COMP_STATIC_MEMBER_FUNCTION_TEMPLATE(trait,...) \
namespace boost \
  { \
  namespace tti \
    { \
    namespace detail \
      { \
      TTI_DETAIL_TRAIT_HAS_COMP_STATIC_MEMBER_FUNCTION_TEMPLATE \
        ( \
        trait, \
        BOOST_VMD_DATA_ELEM(0,__VA_ARGS__), \
        BOOST_PP_IIF \
          ( \
          BOOST_PP_EQUAL \
            ( \
            BOOST_VMD_DATA_SIZE(__VA_ARGS__), \
            1 \
            ), \
          BOOST_PP_NIL, \
          BOOST_PP_LIST_REST \
            ( \
            BOOST_VMD_DATA_TO_PP_LIST(__VA_ARGS__) \
            ) \
          ) \
        ) \
      } \
    template<class T,class Type> \
    struct trait : \
      detail::trait<T,Type> \
      { \
      }; \
    } \
  } \
/**/

/// Expands to a metafunction class which tests whether a static member function template with a particular name/optional signature and composite type exists.
/**

    trait = the name of the metafunction class within the tti namespace.
    
    ...   = variadic macro data which has the name and optionally the function template parameters.

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
#define BOOST_TTI_VM_MTFC_TRAIT_HAS_COMP_STATIC_MEMBER_FUNCTION_TEMPLATE(trait,...) \
namespace boost \
  { \
  namespace tti \
    { \
    namespace detail \
      { \
      TTI_DETAIL_MTFC_TRAIT_HAS_COMP_STATIC_MEMBER_FUNCTION_TEMPLATE \
        ( \
        trait, \
        BOOST_VMD_DATA_ELEM(0,__VA_ARGS__), \
        BOOST_PP_IIF \
          ( \
          BOOST_PP_EQUAL \
            ( \
            BOOST_VMD_DATA_SIZE(__VA_ARGS__), \
            1 \
            ), \
          BOOST_PP_NIL, \
          BOOST_PP_LIST_REST \
            ( \
            BOOST_VMD_DATA_TO_PP_LIST(__VA_ARGS__) \
            ) \
          ) \
        ) \
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


/// Expands to a metafunction which tests whether a static member function template with a particular name/optional signature and composite type exists.
/**

    ...   = variadic macro data which has the name and optionally the function template parameters.

    returns = a metafunction called "boost::tti::has_comp_static_member_function_template_name" where 'name' is the macro parameter.<br />
    
              The metafunction types and return:
    
                T    = the enclosing type.
                
                Type = the static member function type,
                       in the form of a composite function type - 'return_type (parameter_types...)',
                       in which to look for our 'name'.
                       
                returns = 'value' is true if the 'name' exists within the enclosing type,
                          with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_VM_HAS_COMP_STATIC_MEMBER_FUNCTION_TEMPLATE(...) \
  BOOST_TTI_VM_TRAIT_HAS_COMP_STATIC_MEMBER_FUNCTION_TEMPLATE \
  ( \
  BOOST_PP_CAT(has_comp_static_member_function_template_,BOOST_VMD_DATA_ELEM(0,__VA_ARGS__)), \
  __VA_ARGS__ \
  ) \
/**/

/// Expands to a metafunction class which tests whether a static member function template with a particular name/optional signature and composite type exists.
/**

    ...   = variadic macro data which has the name and optionally the function template parameters.

    returns = a metafunction class called "boost::tti::mtfc_has_comp_static_member_function_template_name" where 'name' is the macro parameter.<br />
    
              The metafunction class's 'apply' metafunction types and return:
    
                T    = the enclosing type.
                
                Type = the static member function type,
                       in the form of a composite function type - 'return_type (parameter_types...)',
                       in which to look for our 'name'.
                       
                returns = 'value' is true if the 'name' exists within the enclosing type,
                          with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_VM_MTFC_HAS_COMP_STATIC_MEMBER_FUNCTION_TEMPLATE(...) \
  BOOST_TTI_VM_MTFC_TRAIT_HAS_COMP_STATIC_MEMBER_FUNCTION_TEMPLATE \
  ( \
  BOOST_PP_CAT(mtfc_has_comp_static_member_function_template_,BOOST_VMD_DATA_ELEM(0,__VA_ARGS__)), \
  __VA_ARGS__ \
  ) \
/**/

#endif // !defined(BOOST_NO_VARIADIC_MACROS)
#endif // TTI_VM_COMP_STATIC_MEM_FUN_TEMPLATE_HPP
