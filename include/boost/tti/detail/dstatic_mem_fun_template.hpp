#if !defined(BOOST_TTI_DETAIL_STATIC_MEM_FUN_TEMPLATE_HPP)
#define BOOST_TTI_DETAIL_STATIC_MEM_FUN_TEMPLATE_HPP

#include <boost/function_types/is_function.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/list/enum.hpp>
#include <boost/type_traits/is_class.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/is_union.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>
#include <boost/tti/detail/dnullptr.hpp>
#include <boost/tti/detail/dtfunction.hpp>
#include <boost/tti/gen/namespace_gen.hpp>

#if defined(__SUNPRO_CC)

#define BOOST_TTI_DETAIL_TRAIT_IMPL_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(trait,name,tplst) \
  template<class BOOST_TTI_DETAIL_TP_T,class BOOST_TTI_DETAIL_TP_TYPE> \
  struct trait \
    { \
    template<BOOST_TTI_DETAIL_TP_TYPE *> \
    struct helper {}; \
    \
    template<class U> \
    static ::boost::type_traits::yes_type check(helper<&U::template name<BOOST_PP_LIST_ENUM(tplst)> > *); \
    \
    template<class U> \
    static ::boost::type_traits::no_type check(...); \
    \
    typedef boost::mpl::bool_<sizeof(check<BOOST_TTI_DETAIL_TP_T>(BOOST_TTI_DETAIL_NULLPTR))==sizeof(::boost::type_traits::yes_type)> type; \
    }; \
/**/

#else

#define BOOST_TTI_DETAIL_TRAIT_IMPL_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(trait,name,tplst) \
  template<class BOOST_TTI_DETAIL_TP_T,class BOOST_TTI_DETAIL_TP_TYPE> \
  struct trait \
    { \
    template<BOOST_TTI_DETAIL_TP_TYPE *> \
    struct helper; \
    \
    template<class U> \
    static ::boost::type_traits::yes_type check(helper<&U::template name<BOOST_PP_LIST_ENUM(tplst)> > *); \
    \
    template<class U> \
    static ::boost::type_traits::no_type check(...); \
    \
    typedef boost::mpl::bool_<sizeof(check<BOOST_TTI_DETAIL_TP_T>(BOOST_TTI_DETAIL_NULLPTR))==sizeof(::boost::type_traits::yes_type)> type; \
    }; \
/**/

#endif

#define BOOST_TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE_OP(trait,name,tplst) \
  BOOST_TTI_DETAIL_TRAIT_IMPL_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(trait,name,tplst) \
  template<class BOOST_TTI_DETAIL_TP_T,class BOOST_TTI_DETAIL_TP_R,class BOOST_TTI_DETAIL_TP_FS,class BOOST_TTI_DETAIL_TP_TAG> \
  struct BOOST_PP_CAT(trait,_detail_hsmft_op) : \
    BOOST_PP_CAT(trait,_detail_ihsmft) \
      < \
      BOOST_TTI_DETAIL_TP_T, \
      typename \
      boost::mpl::eval_if \
        < \
        boost::mpl::and_ \
          < \
          boost::function_types::is_function<BOOST_TTI_DETAIL_TP_R>, \
          boost::is_same<BOOST_TTI_DETAIL_TP_FS,boost::mpl::vector<> >, \
          boost::is_same<BOOST_TTI_DETAIL_TP_TAG,boost::function_types::null_tag> \
          >, \
        boost::mpl::identity<BOOST_TTI_DETAIL_TP_R>, \
        BOOST_TTI_NAMESPACE::detail::tfunction_seq<BOOST_TTI_DETAIL_TP_R,BOOST_TTI_DETAIL_TP_FS,BOOST_TTI_DETAIL_TP_TAG> \
        >::type \
      > \
    { \
    }; \
/**/

#define BOOST_TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(trait,name,tplst) \
  BOOST_TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE_OP(trait,name,tplst) \
  template<class BOOST_TTI_DETAIL_TP_T,class BOOST_TTI_DETAIL_TP_R,class BOOST_TTI_DETAIL_TP_FS,class BOOST_TTI_DETAIL_TP_TAG> \
  struct BOOST_PP_CAT(trait,_detail_hsmft) : \
    boost::mpl::eval_if \
        < \
        boost::mpl::or_ \
            < \
            boost::is_class<BOOST_TTI_DETAIL_TP_T>, \
            boost::is_union<BOOST_TTI_DETAIL_TP_T> \
            >, \
        BOOST_PP_CAT(trait,_detail_hsmft_op)<BOOST_TTI_DETAIL_TP_T,BOOST_TTI_DETAIL_TP_R,BOOST_TTI_DETAIL_TP_FS,BOOST_TTI_DETAIL_TP_TAG>, \
        boost::mpl::false_ \
        > \
    { \
    }; \
/**/

#endif // BOOST_TTI_DETAIL_STATIC_MEM_FUN_TEMPLATE_HPP
