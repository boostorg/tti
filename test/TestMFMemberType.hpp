#if !defined(TEST_MF_MEMBER_TYPE_HPP)
#define TEST_MF_MEMBER_TYPE_HPP

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

TTI_MTFC_MEMBER_TYPE(AnIntType)
TTI_MTFC_TRAIT_MEMBER_TYPE(MFNameStruct,AStructType)
TTI_MTFC_MEMBER_TYPE(AnIntTypeReference)
TTI_MTFC_MEMBER_TYPE(BType)
TTI_MTFC_TRAIT_MEMBER_TYPE(MFTheInteger,AnIntegerType)
TTI_MTFC_MEMBER_TYPE(CType)
TTI_MTFC_MEMBER_TYPE(AnotherIntegerType)
TTI_MTFC_TRAIT_MEMBER_TYPE(MetaClSomethingElse,someOtherType)

#endif // TEST_MF_MEMBER_TYPE_HPP
