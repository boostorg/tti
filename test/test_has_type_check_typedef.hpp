#if !defined(TEST_HAS_TYPE_CHECK_TYPEDEF_HPP)
#define TEST_HAS_TYPE_CHECK_TYPEDEF_HPP

#include "test_structs.hpp"
#include <boost/tti/tti.hpp>

TTI_HAS_TYPE(AnIntType)
TTI_TRAIT_HAS_TYPE(NameStruct,AStructType)
TTI_HAS_TYPE(AnIntTypeReference)
TTI_HAS_TYPE(BType)
TTI_TRAIT_HAS_TYPE(TheInteger,AnIntegerType)
TTI_HAS_TYPE(CType)
TTI_HAS_TYPE(AnotherIntegerType)
TTI_TRAIT_HAS_TYPE(SomethingElse,someOtherType)
TTI_HAS_TYPE(NoOtherType)

#endif // TEST_HAS_TYPE_CHECK_TYPEDEF_HPP
