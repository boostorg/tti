#if !defined(TT_INTROSPECTION_DETAIL_HPP)
#define TT_INTROSPECTION_DETAIL_HPP

#include <boost/config.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/has_xxx.hpp>
#include <boost/mpl/remove.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/preprocessor/arithmetic/add.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/array/elem.hpp>
#include <boost/preprocessor/array/size.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/iteration/iterate.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_shifted.hpp>
#include <boost/preprocessor/repetition/enum_shifted_params.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/function_types/member_function_pointer.hpp>
#include <boost/function_types/function_type.hpp>

#if !defined(BOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE)

#define TTI_DETAIL_TEMPLATE_PARAMETERS(z,n,args) \
BOOST_PP_ARRAY_ELEM(BOOST_PP_ADD(4,n),args) \
/**/

#define TTI_DETAIL_HAS_MEMBER_IMPLEMENTATION(args,introspect_macro) \
   template \
     < \
     typename T, \
     typename fallback_ \
       = boost::mpl::bool_< BOOST_PP_ARRAY_ELEM(3, args) > \
     > \
   class BOOST_PP_ARRAY_ELEM(0, args) \
     { \
     introspect_macro(args) \
     public: \
       static const bool value \
         = BOOST_MPL_HAS_MEMBER_INTROSPECTION_NAME(args)< T >::value; \
       typedef typename BOOST_MPL_HAS_MEMBER_INTROSPECTION_NAME(args) \
         < \
         T \
         >::type type; \
     }; \
/**/

#if !BOOST_WORKAROUND(BOOST_MSVC, <= 1400)

#define TTI_DETAIL_HAS_MEMBER_MULTI_SUBSTITUTE(z,n,args) \
  template \
    < \
    template \
      < \
      BOOST_PP_ENUM_ ## z \
        ( \
        BOOST_PP_SUB \
          ( \
          BOOST_PP_ARRAY_SIZE(args), \
          4 \
          ), \
        TTI_DETAIL_TEMPLATE_PARAMETERS, \
        args \
        ) \
      > \
    class V \
    > \
  struct BOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_NAME(args, n) \
    { \
    }; \
/**/

#define TTI_DETAIL_HAS_MEMBER_SUBSTITUTE(args) \
  BOOST_PP_REPEAT \
    ( \
    BOOST_PP_ARRAY_ELEM(2, args), \
    TTI_DETAIL_HAS_MEMBER_MULTI_SUBSTITUTE, \
    args \
    ) \
/**/

#define TTI_DETAIL_HAS_MEMBER_INTROSPECT(args) \
  template< typename U > \
  struct BOOST_MPL_HAS_MEMBER_INTROSPECTION_NAME(args) \
    { \
    TTI_DETAIL_HAS_MEMBER_SUBSTITUTE(args) \
    BOOST_MPL_HAS_MEMBER_REJECT(args, BOOST_PP_NIL) \
    BOOST_MPL_HAS_MEMBER_ACCEPT(args, BOOST_PP_NIL) \
    BOOST_STATIC_CONSTANT \
      ( \
      bool, value = BOOST_MPL_HAS_MEMBER_TEST(args) \
      ); \
    typedef boost::mpl::bool_< value > type; \
    }; \
/**/

#define TTI_DETAIL_HAS_MEMBER_WITH_FUNCTION_SFINAE(args) \
  TTI_DETAIL_HAS_MEMBER_IMPLEMENTATION \
    ( \
    args, \
    TTI_DETAIL_HAS_MEMBER_INTROSPECT \
    ) \
/**/

#else // !!BOOST_WORKAROUND(BOOST_MSVC, <= 1400)

#define TTI_DETAIL_HAS_MEMBER_MULTI_SUBSTITUTE_WITH_TEMPLATE_SFINAE(z,n,args) \
  template \
    < \
    template \
      < \
      BOOST_PP_ENUM_ ## z \
        ( \
        BOOST_PP_SUB \
          ( \
          BOOST_PP_ARRAY_SIZE(args), \
          4 \
          ), \
        TTI_DETAIL_TEMPLATE_PARAMETERS, \
        args \
        ) \
      > \
    class U \
    > \
  struct BOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_NAME_WITH_TEMPLATE_SFINAE \
    ( \
    args, \
    n \
    ) \
    { \
    typedef \
      BOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_TAG_NAME(args) \
      type; \
    }; \
/**/

#define TTI_DETAIL_HAS_MEMBER_SUBSTITUTE_WITH_TEMPLATE_SFINAE(args) \
  typedef void \
      BOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_TAG_NAME(args); \
  BOOST_PP_REPEAT \
    ( \
    BOOST_PP_ARRAY_ELEM(2, args), \
    TTI_DETAIL_HAS_MEMBER_MULTI_SUBSTITUTE_WITH_TEMPLATE_SFINAE, \
    args \
    ) \
/**/

#define TTI_DETAIL_HAS_MEMBER_INTROSPECT_WITH_TEMPLATE_SFINAE(args) \
  BOOST_MPL_HAS_MEMBER_REJECT_WITH_TEMPLATE_SFINAE(args,BOOST_PP_NIL) \
  BOOST_MPL_HAS_MEMBER_ACCEPT_WITH_TEMPLATE_SFINAE(args,BOOST_PP_NIL) \
  template< typename U > \
  struct BOOST_MPL_HAS_MEMBER_INTROSPECTION_NAME(args) \
      : BOOST_MPL_HAS_MEMBER_INTROSPECTION_TEST_NAME(args)< U > { \
  }; \
/**/

#define TTI_DETAIL_HAS_MEMBER_WITH_TEMPLATE_SFINAE(args) \
  TTI_DETAIL_HAS_MEMBER_SUBSTITUTE_WITH_TEMPLATE_SFINAE \
    ( \
    args \
    ) \
  TTI_DETAIL_HAS_MEMBER_IMPLEMENTATION \
    ( \
    args, \
    TTI_DETAIL_HAS_MEMBER_INTROSPECT_WITH_TEMPLATE_SFINAE \
    ) \
/**/

#endif // !BOOST_WORKAROUND(BOOST_MSVC, <= 1400)
#else // !!defined(BOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE)

#define TTI_DETAIL_SAME(trait,name) \
namespace tti \
  { \
  BOOST_MPL_HAS_XXX_TEMPLATE_NAMED_DEF \
    ( \
    trait, \
    name, \
    false \
    ) \
  } \
/**/

#endif // !defined(BOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE)

#define TTI_DETAIL_TRAIT_HAS_TYPE(trait,name) \
namespace mpl \
  { \
  BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, false) \
  } \
template<class T> \
struct trait \
  { \
  typedef typename mpl::trait<T>::type type; \
  \
  BOOST_STATIC_CONSTANT(bool,value=type::value); \
  }; \
/**/

#define TTI_DETAIL_TRAIT_MEMBER_TYPE(trait,name) \
namespace member_type \
  { \
  template<class T> \
  struct trait \
    { \
    typedef typename T::name type; \
    }; \
  } \
/**/

#define TTI_DETAIL_PP_REPEAT_CLASS(z,n,data) \
  BOOST_PP_COMMA_IF(n) data \
/**/

#define TTI_DETAIL_PP_ENUM_SHIFTED_TYPENAME(z,n,data) \
  BOOST_PP_CAT(typename P,n::type) \
/**/

#if !defined(TTI_MAX_PARAMETERS) || TTI_MAX_PARAMETERS < 1 || TTI_MAX_PARAMETERS > 254
#define TTI_MAX_PARAMETERS 10
#endif

namespace tti
  {
  namespace detail
    {
    struct notype
      {
      };
    struct noparam
      {
      typedef tti::detail::noparam type;
      };
      
    template<class T>
    struct eval;
    
#define BOOST_PP_ITERATION_LIMITS (1,BOOST_PP_ADD(2,TTI_MAX_PARAMETERS))
#define BOOST_PP_FILENAME_1 <boost\tti\detail\TTIntrospectionIterateEval.hpp>
#include BOOST_PP_ITERATE()

    template
      <
      class T,
      class R,
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(TTI_MAX_PARAMETERS,class P,tti::detail::noparam)
      >
    struct ptmf
      {
      typedef boost::mpl::vector<R,T,BOOST_PP_ENUM_PARAMS(TTI_MAX_PARAMETERS,P) > fseq;
      typedef typename boost::mpl::remove<fseq,tti::detail::noparam>::type ftseq;
      typedef typename boost::function_types::member_function_pointer<ftseq>::type type;
      };
      
    template
      <
      class T,
      class R
      >
    struct ptmd
      {
      typedef R T::* type;
      };
      
    template
      <
      class R,
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(TTI_MAX_PARAMETERS,class P,tti::detail::noparam)
      >
    struct tfunction
      {
      typedef boost::mpl::vector<R,BOOST_PP_ENUM_PARAMS(TTI_MAX_PARAMETERS,P) > fseq;
      typedef typename boost::mpl::remove<fseq,tti::detail::noparam>::type ftseq;
      typedef typename boost::function_types::function_type<ftseq>::type type;
      };
      
    }
  }
  
#endif // TT_INTROSPECTION_DETAIL_HPP
