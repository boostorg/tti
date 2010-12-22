#if !defined(TEST_MEMBER_TYPE_HPP)
#define TEST_MEMBER_TYPE_HPP

#include "TestStructs.hpp"
#include <boost/tti/TTIntrospection.hpp>

TTI_MEMBER_TYPE(AnIntType)
TTI_TRAIT_MEMBER_TYPE(NameStruct,AStructType)
TTI_MEMBER_TYPE(AnIntTypeReference)
TTI_MEMBER_TYPE(BType)
TTI_TRAIT_MEMBER_TYPE(TheInteger,AnIntegerType)
TTI_MEMBER_TYPE(CType)
TTI_MEMBER_TYPE(AnotherIntegerType)
TTI_TRAIT_MEMBER_TYPE(SomethingElse,someOtherType)

#endif // TEST_MEMBER_TYPE_HPP
