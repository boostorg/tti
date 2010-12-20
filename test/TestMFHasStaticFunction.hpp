#if !defined(TEST_MF_HAS_STATIC_FUNCTION_HPP)
#define TEST_MF_HAS_STATIC_FUNCTION_HPP

#include "TestStructs.hpp"
#include <boost/tti/TTIntrospection.hpp>

TTI_TRAIT_HAS_STATIC_MEMBER(HaveTheSIntFunction,SIntFunction)
TTI_TRAIT_HAS_STATIC_MEMBER(TheTIntFunction,TIntFunction)
TTI_HAS_STATIC_MEMBER(TSFunction)
TTI_TRAIT_HAS_STATIC_MEMBER(Pickedname,SomeStaticFunction)

TTI_MEMBER_TYPE(AStructType)
TTI_TRAIT_MEMBER_TYPE(NameIntType,AnIntType)

#endif // TEST_MF_HAS_STATIC_FUNCTION_HPP
