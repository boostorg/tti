#if !defined(TTI_STATIC_MEMBER_FUNCTION_HPP)
#define TTI_STATIC_MEMBER_FUNCTION_HPP

#include <boost/config.hpp>
#include <boost/function_types/property_tags.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/preprocessor/cat.hpp>
#include "detail/dstatic_mem_fun.hpp"
#include "detail/dtfunction.hpp"
#include "detail/dtself.hpp"

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/// Expands to a metafunction which tests whether a static member function with a particular name and signature exists.
/**

    trait = the name of the metafunction within the tti namespace.
    
    name  = the name of the inner member.

    returns = a metafunction called "boost::tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.
                
                R   = the return type of the static member function.
                
                FS  = an optional parameter which are the parameters of the static member function as a boost::mpl forward sequence.
                
                TAG = an optional parameter which is a boost::function_types tag to apply to the static member function.
                
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_TRAIT_HAS_STATIC_MEMBER_FUNCTION(trait,name) \
namespace boost \
  { \
  namespace tti \
    { \
    namespace detail \
      { \
      TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION(trait,name) \
      } \
    template<class T,class R,class FS = boost::mpl::vector<>,class TAG = boost::function_types::null_tag> \
    struct trait : \
      detail::trait<T,typename detail::tfunction_seq<R,FS,TAG>::type> \
      { \
      }; \
    } \
  } \
/**/

/// Expands to a metafunction class which tests whether a static member function with a particular name and signature exists.
/**

    trait = the name of the metafunction class within the tti namespace.
    
    name  = the name of the inner member.

    returns = a metafunction class called "boost::tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction class's 'apply' metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.
                
                R   = the return type of the static member function.
                
                FS  = an optional parameter which are the parameters of the static member function as a boost::mpl forward sequence.
                
                TAG = an optional parameter which is a boost::function_types tag to apply to the static member function.
                
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_MTFC_TRAIT_HAS_STATIC_MEMBER_FUNCTION(trait,name) \
namespace boost \
  { \
  namespace tti \
    { \
    namespace detail \
      { \
      TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION(trait,name) \
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

/// Expands to a metafunction which tests whether a static member function with a particular name and signature exists.
/**

    name  = the name of the inner member.

    returns = a metafunction called "boost::tti::has_static_member_function_name" where 'name' is the macro parameter.
    
              The metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.
                
                R   = the return type of the static member function.
                
                FS  = an optional parameter which are the parameters of the static member function as a boost::mpl forward sequence.
                
                TAG = an optional parameter which is a boost::function_types tag to apply to the static member function.
                
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_HAS_STATIC_MEMBER_FUNCTION(name) \
  BOOST_TTI_TRAIT_HAS_STATIC_MEMBER_FUNCTION \
  ( \
  BOOST_PP_CAT(has_static_member_function_,name), \
  name \
  ) \
/**/

/// Expands to a metafunction class which tests whether a static member function with a particular name and signature exists.
/**

    name  = the name of the inner member.

    returns = a metafunction class called "boost::tti::mtfc_has_static_member_function_name" where 'name' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.
                
                R   = the return type of the static member function.
                
                FS  = an optional parameter which are the parameters of the static member function as a boost::mpl forward sequence.
                
                TAG = an optional parameter which is a boost::function_types tag to apply to the static member function.
                
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_MTFC_HAS_STATIC_MEMBER_FUNCTION(name) \
  BOOST_TTI_MTFC_TRAIT_HAS_STATIC_MEMBER_FUNCTION \
  ( \
  BOOST_PP_CAT(mtfc_has_static_member_function_,name), \
  name \
  ) \
/**/

namespace boost
  {
  namespace tti
    {
  
    /// A metafunction which checks whether a static member function exists within an enclosing type.
    /**

        This metafunction takes its specific types, except for the optional parameters, as nullary metafunctions whose typedef 'type' member is the actual type used.
    
        The metafunction types and return:

          HasStaticMemberFunction = a Boost MPL lambda expression using the metafunction generated from the TTI_HAS_STATIC_MEMBER_FUNCTION ( or TTI_TRAIT_HAS_STATIC_MEMBER_FUNCTION ) macro.<br />
                                    The easiest way to generate the lambda expression is to use a Boost MPL placeholder expression of the form 'metafunction\<_,_\> ( or optionally 'metafunction\<_,_,_\> or ' 'metafunction\<_,_,_,_\> )'.
                                    You can also use the metafunction class generated by the TTI_MTFC_HAS_STATIC_MEMBER_FUNCTION ( or TTI_MTFC_TRAIT_HAS_STATIC_MEMBER_FUNCTION ) macro.
                                    
          T               = the enclosing type as a nullary metafunction.
          
          R               = the return type of the static member function as a nullary metafunction.
          
          FS              = an optional parameter which is the parameters of the static member function, each as a nullary metafunction, as a boost::mpl forward sequence.
          
          TAG             = an optional parameter which is a boost::function_types tag to apply to the static member function.
      
          returns = 'value' is true if the member function exists within the enclosing type,
                    otherwise 'value' is false.
                          
    */
    template
      <
      class HasStaticMemberFunction,
      class T,
      class R,
      class FS = boost::mpl::vector<>,
      class TAG = boost::function_types::null_tag
      >
    struct mf_has_static_member_function :
      boost::mpl::apply
        <
        HasStaticMemberFunction,
        typename T::type,
        typename R::type,
        typename boost::mpl::transform<FS,detail::tself<boost::mpl::_1> >::type,
        TAG
        >::type
      {
      };
    }
  }
  
#endif // TTI_STATIC_MEMBER_FUNCTION_HPP
