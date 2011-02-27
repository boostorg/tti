#if !defined(TTI_VM_MEMBER_FUNCTION_TEMPLATE_HPP)
#define TTI_VM_MEMBER_FUNCTION_TEMPLATE_HPP

#include <boost/config.hpp>

#if !defined(BOOST_NO_VARIADIC_MACROS)

#include <boost/function_types/property_tags.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/variadic_macro_data/vmd.hpp>
#include "mf_member_function_template.hpp"
#include "detail/dmember_function_template.hpp"

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/// Expands to a metafunction which tests whether a member function template with a particular name and signature exists.
/**

    trait = the name of the metafunction within the tti namespace.
    
    name  = the name of the inner member.
    
    ...   = variadic macro data which has the function template parameters.

    returns = a metafunction called "boost::tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.
                
                R   = the return type of a valid instantiation of the member function template.
                
                FS  = an optional parameter which are the parameters of a valid instantiation of the member function template, in the form of a boost::mpl forward sequence.
                
                TAG = an optional parameter which is a boost::function_types tag to apply to a valid instantiation of the member function template.
                
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_VM_TRAIT_HAS_MEMBER_FUNCTION_TEMPLATE(trait,name,...) \
namespace boost \
  { \
  namespace tti \
    { \
    namespace detail \
      { \
      TTI_DETAIL_TRAIT_HAS_MEMBER_FUNCTION_TEMPLATE(trait,name,BOOST_VMD_DATA_TO_PP_SEQ(__VA_ARGS__)) \
      } \
    template<class T,class R,class FS = boost::mpl::vector<>,class TAG = boost::function_types::null_tag> \
    struct trait : \
      detail::trait<typename detail::ptmf_seq<T,R,FS,TAG>::type,typename boost::remove_const<T>::type> \
      { \
      }; \
    } \
  } \
/**/

/// Expands to a metafunction class which tests whether a member function template with a particular name and signature exists.
/**

    trait = the name of the metafunction class within the tti namespace.
    
    name  = the name of the inner member.

    ...   = variadic macro data which has the function template parameters.

    returns = a metafunction class called "boost::tti::trait" where 'trait' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.
                
                R   = the return type of a valid instantiation of the member function template.
                
                FS  = an optional parameter which are the parameters of a valid instantiation of the member function template, in the form of a boost::mpl forward sequence.
                
                TAG = an optional parameter which is a boost::function_types tag to apply to a valid instantiation of the member function template.
                
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_VM_MTFC_TRAIT_HAS_MEMBER_FUNCTION_TEMPLATE(trait,name,...) \
namespace boost \
  { \
  namespace tti \
    { \
    namespace detail \
      { \
      TTI_DETAIL_TRAIT_HAS_MEMBER_FUNCTION_TEMPLATE(trait,name,BOOST_VMD_DATA_TO_PP_SEQ(__VA_ARGS__)) \
      } \
    struct trait \
      { \
      template<class T,class R,class FS = boost::mpl::vector<>,class TAG = boost::function_types::null_tag> \
      struct apply : \
        detail::trait<typename detail::ptmf_seq<T,R,FS,TAG>::type,typename boost::remove_const<T>::type> \
        { \
        }; \
      }; \
    } \
  } \
/**/

/// Expands to a metafunction which tests whether a member function templaten with a particular name and signature exists.
/**

    name  = the name of the inner member.
    
    ...   = variadic macro data which has the function template parameters.

    returns = a metafunction called "boost::tti::has_member_function_template_name" where 'name' is the macro parameter.
    
              The metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.
                
                R   = the return type of a valid instantiation of the member function template.
                
                FS  = an optional parameter which are the parameters of a valid instantiation of the member function template, in the form of a boost::mpl forward sequence.
                
                TAG = an optional parameter which is a boost::function_types tag to apply to a valid instantiation of the member function template.
                
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_VM_HAS_MEMBER_FUNCTION_TEMPLATE(name,...) \
  BOOST_TTI_VM_TRAIT_HAS_MEMBER_FUNCTION_TEMPLATE \
  ( \
  BOOST_PP_CAT(has_member_function_template_,name), \
  name, \
  __VA_ARGS__ \
  ) \
/**/

/// Expands to a metafunction class which tests whether a member function template with a particular name and signature exists.
/**

    name  = the name of the inner member.

    ...   = variadic macro data which has the function template parameters.

    returns = a metafunction class called "boost::tti::mtfc_has_member_function_template_name" where 'name' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.
                
                R   = the return type of a valid instantiation of the member function template.
                
                FS  = an optional parameter which are the parameters of a valid instantiation of the member function template, in the form of a boost::mpl forward sequence.
                
                TAG = an optional parameter which is a boost::function_types tag to apply to a valid instantiation of the member function template.
                
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_VM_MTFC_HAS_MEMBER_FUNCTION_TEMPLATE(name,...) \
  BOOST_TTI_VM_MTFC_TRAIT_HAS_MEMBER_FUNCTION_TEMPLATE \
  ( \
  BOOST_PP_CAT(mtfc_has_member_function_template_,name), \
  name, \
  __VA_ARGS__ \
  ) \
/**/

#endif // !defined(BOOST_NO_VARIADIC_MACROS)
#endif // TTI_VM_MEMBER_FUNCTION_TEMPLATE_HPP
