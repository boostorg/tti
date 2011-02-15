#if !defined(TTI_MEMBER_DATA_HPP)
#define TTI_MEMBER_DATA_HPP

#include <boost/config.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/type_traits/remove_const.hpp>
#include "detail/dmember_data.hpp"

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/// Expands to a metafunction which tests whether a member data with a particular name and type exists.
/**

    trait = the name of the metafunction within the tti namespace.<br />
    name  = the name of the inner member.

    returns = a metafunction called "boost::tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.<br />
                R   = the type of the member data.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_TRAIT_HAS_MEMBER_DATA(trait,name) \
namespace boost \
  { \
  namespace tti \
    { \
    namespace detail \
      { \
      TTI_DETAIL_TRAIT_HAS_MEMBER_DATA(trait,name) \
      } \
    template<class T,class R> \
    struct trait : \
      detail::trait<typename detail::ptmd<T,R>::type,typename boost::remove_const<T>::type> \
      { \
      }; \
    } \
  } \
/**/

/// Expands to a metafunction class which tests whether a member data with a particular name and type exists.
/**

    trait = the name of the metafunction class within the tti namespace.<br />
    name  = the name of the inner member.

    returns = a metafunction class called "boost::tti::trait" where 'trait' is the macro parameter.<br />
    
              The metafunction class's 'apply' metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.<br />
                R   = the type of the member data.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_MTFC_TRAIT_HAS_MEMBER_DATA(trait,name) \
namespace boost \
  { \
  namespace tti \
    { \
    namespace detail \
      { \
      TTI_DETAIL_TRAIT_HAS_MEMBER_DATA(trait,name) \
      } \
    struct trait \
      { \
      template<class T,class R> \
      struct apply : \
        detail::trait<typename detail::ptmd<T,R>::type,typename boost::remove_const<T>::type> \
        { \
        }; \
      }; \
    } \
  } \
/**/

/// Expands to a metafunction which tests whether a member data with a particular name and type exists.
/**

    name  = the name of the inner member.

    returns = a metafunction called "boost::tti::has_member_data_name" where 'name' is the macro parameter.
    
              The metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.<br />
                R   = the type of the member data.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_HAS_MEMBER_DATA(name) \
  BOOST_TTI_TRAIT_HAS_MEMBER_DATA \
  ( \
  BOOST_PP_CAT(has_member_data_,name), \
  name \
  ) \
/**/

/// Expands to a metafunction class which tests whether a member data with a particular name and type exists.
/**

    name  = the name of the inner member.

    returns = a metafunction class called "boost::tti::mtfc_has_member_data_name" where 'name' is the macro parameter.
    
              The metafunction class's 'apply' metafunction types and return:
    
                T   = the enclosing type in which to look for our 'name'.<br />
                R   = the type of the member data.<br />
                returns = 'value' is true if the 'name' exists, with the appropriate type,
                          otherwise 'value' is false.
                          
*/
#define BOOST_TTI_MTFC_HAS_MEMBER_DATA(name) \
  BOOST_TTI_MTFC_TRAIT_HAS_MEMBER_DATA \
  ( \
  BOOST_PP_CAT(mtfc_has_member_data_,name), \
  name \
  ) \
/**/

namespace boost
  {
  namespace tti
    {
  
    /// A metafunction which checks whether a member data exists within an enclosing type.
    /**

        This metafunction takes its specific types as nullary metafunctions whose typedef 'type' member is the actual type used.
    
        The metafunction types and return:

          HasMemberData = a Boost MPL lambda expression using the metafunction generated from the TTI_HAS_MEMBER_DATA ( or TTI_TRAIT_HAS_MEMBER_DATA ) macro.<br />
                          The easiest way to generate the lambda expression is to use a Boost MPL placeholder expression of the form 'metafunction\<_,_\>'.
                          You can also use the metafunction class generated by the TTI_MTFC_HAS_MEMBER_DATA ( or TTI_MTFC_TRAIT_HAS_MEMBER_DATA ) macro.<br />
          T         = the enclosing type as a nullary metafunction.<br />
          R         = the type of the member data as a nullary metafunction.
      
          returns = 'value' is true if the member data exists within the enclosing type,
                    otherwise 'value' is false.
                          
    */
    template
      <
      class HasMemberData,
      class T,
      class R
      >
    struct mf_has_member_data :
      boost::mpl::apply
        <
        HasMemberData,
        typename T::type,
        typename R::type
        >::type 
      {
      };
    }
  }
  
#endif // TTI_MEMBER_DATA_HPP
