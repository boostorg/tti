#if !defined(BOOST_TTI_STATIC_MEM_FUN_TEMPLATE_HPP)
#define BOOST_TTI_STATIC_MEM_FUN_TEMPLATE_HPP

#include <boost/preprocessor/config/config.hpp>
#include <boost/function_types/property_tags.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/tti/gen/namespace_gen.hpp>
#include <boost/tti/gen/static_mem_fun_template_gen.hpp>
#include <boost/tti/detail/ddeftype.hpp>
#include <boost/tti/detail/dstatic_mem_fun_template.hpp>
#include <boost/tti/detail/dtfunction.hpp>

#if BOOST_PP_VARIADICS

#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/list/adt.hpp>
#include <boost/preprocessor/variadic/elem.hpp>
#include <boost/preprocessor/variadic/size.hpp>
#include <boost/preprocessor/variadic/to_list.hpp>

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
#define BOOST_TTI_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(trait,...) \
  BOOST_TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE \
    ( \
    trait, \
    BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__), \
    BOOST_PP_IIF \
      ( \
      BOOST_PP_EQUAL \
        ( \
        BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), \
        1 \
        ), \
      BOOST_PP_NIL, \
      BOOST_PP_LIST_REST \
        ( \
        BOOST_PP_VARIADIC_TO_LIST(__VA_ARGS__) \
        ) \
      ) \
    ) \
  template<class T,class R = BOOST_TTI_NAMESPACE::detail::deftype,class FS = boost::mpl::vector<>,class TAG = boost::function_types::null_tag> \
  struct trait \
    { \
    typedef typename \
    BOOST_PP_CAT(trait,_detail_hsmft)<BOOST_TTI_TP_T,BOOST_TTI_TP_R,BOOST_TTI_TP_FS,BOOST_TTI_TP_TAG>::type type; \
    BOOST_STATIC_CONSTANT(bool,value=type::value); \
    }; \
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
#define BOOST_TTI_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(...) \
  BOOST_TTI_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE \
  ( \
  BOOST_TTI_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE_GEN(BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__)), \
  __VA_ARGS__ \
  ) \
/**/

#else

#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/seq/to_tuple.hpp>
#include <boost/preprocessor/tuple/to_list.hpp>

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/// Expands to a metafunction which tests whether a static member function template with a particular name and signature exists.
/**

    trait = the name of the metafunction within the tti namespace.
    
    name  = the name of the inner member.

    tpseq = a Boost PP sequence which has the function template parameters.
            Each part of the template parameters separated by a comma ( , )
            is put in a separate sequence element.

    returns = a metafunction called "boost::tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.
                
                R   = the return type of the static member function.
                
                FS  = an optional parameter which are the parameters of the static member function as a boost::mpl forward sequence.
                
                TAG = an optional parameter which is a boost::function_types tag to apply to the static member function.
                
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(trait,name,tpseq) \
  BOOST_TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(trait,name,BOOST_PP_TUPLE_TO_LIST(BOOST_PP_SEQ_SIZE(tpseq),BOOST_PP_SEQ_TO_TUPLE(tpseq))) \
  template<class T,class R = BOOST_TTI_NAMESPACE::detail::deftype,class FS = boost::mpl::vector<>,class TAG = boost::function_types::null_tag> \
  struct trait \
    { \
    typedef typename \
    BOOST_PP_CAT(trait,_detail_hsmft)<BOOST_TTI_TP_T,BOOST_TTI_TP_R,BOOST_TTI_TP_FS,BOOST_TTI_TP_TAG>::type type; \
    BOOST_STATIC_CONSTANT(bool,value=type::value); \
    }; \
/**/

/// Expands to a metafunction which tests whether a static member function template with a particular name and signature exists.
/**

    name  = the name of the inner member.

    tpseq = a Boost PP sequence which has the function template parameters.
            Each part of the template parameters separated by a comma ( , )
            is put in a separate sequence element.

    returns = a metafunction called "boost::tti::has_static_member_function_name" where 'name' is the macro parameter.
    
              The metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.
                
                R   = the return type of the static member function.
                
                FS  = an optional parameter which are the parameters of the static member function as a boost::mpl forward sequence.
                
                TAG = an optional parameter which is a boost::function_types tag to apply to the static member function.
                
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(name,tpseq) \
  BOOST_TTI_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE \
  ( \
  BOOST_TTI_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE_GEN(name), \
  name, \
  tpseq \
  ) \
/**/

#endif

#endif // BOOST_TTI_STATIC_MEM_FUN_TEMPLATE_HPP
