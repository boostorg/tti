#if !defined(TTI_COMP_MEM_FUN_TEMPLATE_HPP)
#define TTI_COMP_MEM_FUN_TEMPLATE_HPP

#include <boost/config.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/seq/to_tuple.hpp>
#include <boost/preprocessor/tuple/to_list.hpp>
#include "gen/comp_mem_fun_template_gen.hpp"
#include "detail/dcomp_mem_fun_template.hpp"

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/// Expands to a metafunction which tests whether a member function template with a particular name and signature exists.
/**

    trait = the name of the metafunction within the tti namespace.
    
    name  = the name of the inner member.

    tpseq = a Boost PP sequence which has the function template parameters.
            Each part of the template parameters separated by a comma ( , )
            is put in a separate sequence element.

    returns = a metafunction called "boost::tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction types and return:
    
                T = the type, in the form of a member function pointer, 
                    in which to look for our 'name'.
                    
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_TRAIT_HAS_COMP_MEMBER_FUNCTION_TEMPLATE(trait,name,tpseq) \
namespace boost \
  { \
  namespace tti \
    { \
    namespace detail \
      { \
      TTI_DETAIL_TRAIT_HAS_COMP_MEMBER_FUNCTION_TEMPLATE(trait,name,BOOST_PP_TUPLE_TO_LIST(BOOST_PP_SEQ_SIZE(tpseq),BOOST_PP_SEQ_TO_TUPLE(tpseq))) \
      } \
    template<class T> \
    struct trait : \
      detail::trait<T> \
      { \
      }; \
    } \
  } \
/**/

/// Expands to a metafunction class which tests whether a member function template with a particular name and signature exists.
/**

    trait = the name of the metafunction class within the tti namespace.
    
    name  = the name of the inner member.

    tpseq = a Boost PP sequence which has the function template parameters.
            Each part of the template parameters separated by a comma ( , )
            is put in a separate sequence element.

    returns = a metafunction class called "boost::tti::trait" where 'trait' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T = the type, in the form of a member function pointer, 
                    in which to look for our 'name'.
                    
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_MTFC_TRAIT_HAS_COMP_MEMBER_FUNCTION_TEMPLATE(trait,name,tpseq) \
namespace boost \
  { \
  namespace tti \
    { \
    namespace detail \
      { \
      TTI_DETAIL_TRAIT_HAS_COMP_MEMBER_FUNCTION_TEMPLATE(trait,name,BOOST_PP_TUPLE_TO_LIST(BOOST_PP_SEQ_SIZE(tpseq),BOOST_PP_SEQ_TO_TUPLE(tpseq))) \
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

/// Expands to a metafunction which tests whether a member function template with a particular name and signature exists.
/**

    name  = the name of the inner member.

    tpseq = a Boost PP sequence which has the function template parameters.
            Each part of the template parameters separated by a comma ( , )
            is put in a separate sequence element.

    returns = a metafunction called "boost::tti::has_comp_member_function_template_name" where 'name' is the macro parameter.
    
              The metafunction types and return:
    
                T = the type, in the form of a member function pointer,
                    in which to look for our 'name'.
                    
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_HAS_COMP_MEMBER_FUNCTION_TEMPLATE(name,tpseq) \
  BOOST_TTI_TRAIT_HAS_COMP_MEMBER_FUNCTION_TEMPLATE \
  ( \
  BOOST_TTI_HAS_COMP_MEMBER_FUNCTION_TEMPLATE_GEN_BASE(name), \
  name, \
  tpseq \
  ) \
/**/

/// Expands to a metafunction class which tests whether a member function template with a particular name and signature exists.
/**

    name  = the name of the inner member.

    tpseq = a Boost PP sequence which has the function template parameters.
            Each part of the template parameters separated by a comma ( , )
            is put in a separate sequence element.

    returns = a metafunction class called "boost::tti::mtfc_has_comp_member_function_template_name" where 'name' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T = the type, in the form of a member function pointer, 
                    in which to look for our 'name'.
                    
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_MTFC_HAS_COMP_MEMBER_FUNCTION_TEMPLATE(name,tpseq) \
  BOOST_TTI_MTFC_TRAIT_HAS_COMP_MEMBER_FUNCTION_TEMPLATE \
  ( \
  BOOST_TTI_MTFC_HAS_COMP_MEMBER_FUNCTION_TEMPLATE_GEN_BASE(name), \
  name, \
  tpseq \
  ) \
/**/

#endif // TTI_COMP_MEM_FUN_TEMPLATE_HPP
