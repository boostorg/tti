#if !defined(TTI_VM_STATIC_MEM_FUN_TEMPLATE_HPP)
#define TTI_VM_STATIC_MEM_FUN_TEMPLATE_HPP

#include <boost/config.hpp>

#if !defined(BOOST_NO_VARIADIC_MACROS)

#include <boost/function_types/property_tags.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/list/adt.hpp>
#include <boost/variadic_macro_data/vmd.hpp>
#include "mf_static_mem_fun_template.hpp"
#include "detail/dstatic_mem_fun_template.hpp"
#include "detail/dtfunction.hpp"

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/// Expands to a metafunction which tests whether a static member function template with a particular name and an optional signature exists.
/**

    trait = the name of the metafunction within the tti namespace.
    
    ...   = variadic macro data which has the name and optionally the function template parameters.

    returns = a metafunction called "boost::tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.
                
                R   = the return type of the static member function.
                
                FS  = an optional parameter which are the parameters of the static member function as a boost::mpl forward sequence.
                
                TAG = an optional parameter which is a boost::function_types tag to apply to the static member function.
                
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_VM_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(trait,...) \
namespace boost \
  { \
  namespace tti \
    { \
    namespace detail \
      { \
      TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE \
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
    template<class T,class R,class FS = boost::mpl::vector<>,class TAG = boost::function_types::null_tag> \
    struct trait : \
      detail::trait<T,typename detail::tfunction_seq<R,FS,TAG>::type> \
      { \
      }; \
    } \
  } \
/**/

/// Expands to a metafunction class which tests whether a static member function template with a particular name and an optional signature exists.
/**

    trait = the name of the metafunction class within the tti namespace.
    
    ...   = variadic macro data which has the name and optionally the function template parameters.
    
    returns = a metafunction class called "boost::tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction class's 'apply' metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.
                
                R   = the return type of the static member function.
                
                FS  = an optional parameter which are the parameters of the static member function as a boost::mpl forward sequence.
                
                TAG = an optional parameter which is a boost::function_types tag to apply to the static member function.
                
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_VM_MTFC_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(trait,...) \
namespace boost \
  { \
  namespace tti \
    { \
    namespace detail \
      { \
      TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE \
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
      template<class T,class R,class FS = boost::mpl::vector<>,class TAG = boost::function_types::null_tag> \
      struct apply : \
        detail::trait<T,typename detail::tfunction_seq<R,FS,TAG>::type> \
        { \
        }; \
      }; \
    } \
  } \
/**/

/// Expands to a metafunction which tests whether a static member function template with a particular name and an optional signature exists.
/**

    ...   = variadic macro data which has the name and optionally the function template parameters.
    
    returns = a metafunction called "boost::tti::has_static_member_function_template_name" where 'name' is the first variadic macro parameter.
    
              The metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.
                
                R   = the return type of the static member function.
                
                FS  = an optional parameter which are the parameters of the static member function as a boost::mpl forward sequence.
                
                TAG = an optional parameter which is a boost::function_types tag to apply to the static member function.
                
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_VM_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(...) \
  BOOST_TTI_VM_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE \
  ( \
  BOOST_PP_CAT(has_static_member_function_template_,BOOST_VMD_DATA_ELEM(0,__VA_ARGS__)), \
  __VA_ARGS__ \
  ) \
/**/

/// Expands to a metafunction class which tests whether a static member function template with a particular name and an optional signature exists.
/**

    ...   = variadic macro data which has the name and optionally the function template parameters.
    
    returns = a metafunction class called "boost::tti::mtfc_has_static_member_function_template_name" where 'name' is the first variadic macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.
                
                R   = the return type of the static member function.
                
                FS  = an optional parameter which are the parameters of the static member function as a boost::mpl forward sequence.
                
                TAG = an optional parameter which is a boost::function_types tag to apply to the static member function.
                
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_VM_MTFC_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(...) \
  BOOST_TTI_VM_MTFC_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE \
  ( \
  BOOST_PP_CAT(mtfc_has_static_member_function_template_,BOOST_VMD_DATA_ELEM(0,__VA_ARGS__)), \
  __VA_ARGS__ \
  ) \
/**/

#endif // !defined(BOOST_NO_VARIADIC_MACROS)
#endif // TTI_VM_STATIC_MEM_FUN_TEMPLATE_HPP
