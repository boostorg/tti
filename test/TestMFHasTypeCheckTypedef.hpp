#if !defined(TEST_MF_HAS_TYPE_CHECK_TYPEDEF_HPP)
#define TEST_MF_HAS_TYPE_CHECK_TYPEDEF_HPP

#include "TestStructs.hpp"
#include <boost/tti/TTIntrospection.hpp>

TTI_HAS_TYPE(AnIntType)
TTI_TRAIT_HAS_TYPE(NameStruct,AStructType)
TTI_HAS_TYPE(AnIntTypeReference)
TTI_HAS_TYPE(BType)
TTI_TRAIT_HAS_TYPE(TheInteger,AnIntegerType)
TTI_HAS_TYPE(CType)
TTI_HAS_TYPE(AnotherIntegerType)
TTI_TRAIT_HAS_TYPE(SomethingElse,someOtherType)
TTI_HAS_TYPE(NoOtherType)

TTI_MTFC_HAS_TYPE(AnIntType)
TTI_MTFC_TRAIT_HAS_TYPE(MFunctionNameStruct,AStructType)
TTI_MTFC_HAS_TYPE(AnIntTypeReference)
TTI_MTFC_HAS_TYPE(BType)
TTI_MTFC_TRAIT_HAS_TYPE(MFCTheInteger,AnIntegerType)
TTI_MTFC_HAS_TYPE(CType)
TTI_MTFC_HAS_TYPE(AnotherIntegerType)
TTI_MTFC_TRAIT_HAS_TYPE(FClassSomethingElse,someOtherType)
TTI_MTFC_HAS_TYPE(NoOtherType)

TTI_MEMBER_TYPE(AStructType)
TTI_MEMBER_TYPE(BType)
TTI_MEMBER_TYPE(CType)
TTI_MEMBER_TYPE(AnIntType)

TTI_MTFC_MEMBER_TYPE(CType)

#endif // TEST_MF_HAS_TYPE_CHECK_TYPEDEF_HPP
