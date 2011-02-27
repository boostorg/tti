#if !defined(TTI_STATIC_MEM_FUN_TEMPLATE_HPP)
#define TTI_STATIC_MEM_FUN_TEMPLATE_HPP

#include <boost/config.hpp>
#include <boost/function_types/property_tags.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/preprocessor/cat.hpp>
#include "mf_static_mem_fun_template.hpp"
#include "detail/dstatic_mem_fun_template.hpp"

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
namespace boost \
  { \
  namespace tti \
    { \
    namespace detail \
      { \
      TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(trait,name,tpseq) \
      } \
    template<class T,class R,class FS = boost::mpl::vector<>,class TAG = boost::function_types::null_tag> \
    struct trait : \
      detail::trait<T,typename detail::tfunction_seq<R,FS,TAG>::type> \
      { \
      }; \
    } \
  } \
/**/

/// Expands to a metafunction class which tests whether a static member function template with a particular name and signature exists.
/**

    trait = the name of the metafunction class within the tti namespace.
    
    name  = the name of the inner member.

    tpseq = a Boost PP sequence which has the function template parameters.
            Each part of the template parameters separated by a comma ( , )
            is put in a separate sequence element.

    returns = a metafunction class called "boost::tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction class's 'apply' metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.
                
                R   = the return type of the static member function.
                
                FS  = an optional parameter which are the parameters of the static member function as a boost::mpl forward sequence.
                
                TAG = an optional parameter which is a boost::function_types tag to apply to the static member function.
                
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_MTFC_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(trait,name,tpseq) \
namespace boost \
  { \
  namespace tti \
    { \
    namespace detail \
      { \
      TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(trait,name,tpseq) \
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
  BOOST_PP_CAT(has_static_member_function_template_,name), \
  name, \
  tpseq \
  ) \
/**/

/// Expands to a metafunction class which tests whether a static member function template with a particular name and signature exists.
/**

    name  = the name of the inner member.

    tpseq = a Boost PP sequence which has the function template parameters.
            Each part of the template parameters separated by a comma ( , )
            is put in a separate sequence element.

    returns = a metafunction class called "boost::tti::mtfc_has_static_member_function_name" where 'name' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.
                
                R   = the return type of the static member function.
                
                FS  = an optional parameter which are the parameters of the static member function as a boost::mpl forward sequence.
                
                TAG = an optional parameter which is a boost::function_types tag to apply to the static member function.
                
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_MTFC_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(name,tpseq) \
  BOOST_TTI_MTFC_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE \
  ( \
  BOOST_PP_CAT(mtfc_has_static_member_function_template_,name), \
  name, \
  tpseq \
  ) \
/**/

#endif // TTI_STATIC_MEM_FUN_TEMPLATE_HPP
