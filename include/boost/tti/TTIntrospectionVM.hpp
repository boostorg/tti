#if !defined(TT_INTROSPECTION_VM_HPP)
#define TT_INTROSPECTION_VM_HPP

#include <boost/config.hpp>
#include <boost/mpl/has_xxx.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/add.hpp>
#include <boost/variadic_macro_data/VariadicMacroData.hpp>
#include "detail/TTIntrospectionDetail.hpp"

#if !defined(BOOST_NO_VARIADIC_MACROS)
#if !defined(BOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE)
#if !BOOST_WORKAROUND(BOOST_MSVC, <= 1400)

#define TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(trait,name,...) \
namespace tti \
  { \
  TTI_DETAIL_HAS_MEMBER_WITH_FUNCTION_SFINAE \
    (  \
      ( BOOST_PP_ADD(VMD_DATA_SIZE(__VA_ARGS__),4), ( trait, name, 1, false, __VA_ARGS__ ) )  \
    )  \
  } \
/**/

#else // !!BOOST_WORKAROUND(BOOST_MSVC, <= 1400)

#define TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(trait,name,...) \
namespace tti \
  { \
  TTI_DETAIL_HAS_MEMBER_WITH_TEMPLATE_SFINAE \
    ( \
      ( BOOST_PP_ADD(VMD_DATA_SIZE(__VA_ARGS__),4), ( trait, name, 1, false, __VA_ARGS__ ) )  \
    ) \
  } \
/**/

#endif // !BOOST_WORKAROUND(BOOST_MSVC, <= 1400)
#else // !!defined(BOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE)

#define TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS(trait,name,...) \
TTI_DETAIL_SAME(trait,name) \
/**/

#endif // !defined(BOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE)

#define TTI_VM_HAS_TEMPLATE_CHECK_PARAMS(name,...) \
  TTI_VM_TRAIT_HAS_TEMPLATE_CHECK_PARAMS \
  ( \
  BOOST_PP_CAT(has_template_check_params_,name), \
  name, \
  __VA_ARGS__ \
  ) \
/**/

#endif // !defined(BOOST_NO_VARIADIC_MACROS)
#endif // TT_INTROSPECTION_VM_HPP
