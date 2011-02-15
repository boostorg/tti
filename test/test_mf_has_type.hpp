#if !defined(TEST_MF_HAS_TYPE_HPP)
#define TEST_MF_HAS_TYPE_HPP

#include "test_structs.hpp"
#include <boost/tti/type.hpp>
#include <boost/tti/member_type.hpp>

BOOST_TTI_HAS_TYPE(AnIntType)
BOOST_TTI_TRAIT_HAS_TYPE(NameStruct,AStructType)
BOOST_TTI_HAS_TYPE(AnIntTypeReference)
BOOST_TTI_HAS_TYPE(BType)
BOOST_TTI_TRAIT_HAS_TYPE(TheInteger,AnIntegerType)
BOOST_TTI_HAS_TYPE(CType)
BOOST_TTI_HAS_TYPE(AnotherIntegerType)

BOOST_TTI_TRAIT_HAS_TYPE(SomethingElse,someOtherType)
BOOST_TTI_HAS_TYPE(NoOtherType)

BOOST_TTI_MTFC_HAS_TYPE(AnIntType)
BOOST_TTI_MTFC_TRAIT_HAS_TYPE(MetaFNameStruct,AStructType)
BOOST_TTI_MTFC_HAS_TYPE(AnIntTypeReference)
BOOST_TTI_MTFC_HAS_TYPE(BType)
BOOST_TTI_MTFC_TRAIT_HAS_TYPE(MClassTheInteger,AnIntegerType)
BOOST_TTI_MTFC_HAS_TYPE(CType)
BOOST_TTI_MTFC_HAS_TYPE(AnotherIntegerType)

BOOST_TTI_MTFC_TRAIT_HAS_TYPE(MTFCSomethingElse,someOtherType)
BOOST_TTI_MTFC_HAS_TYPE(NoOtherType)

BOOST_TTI_MEMBER_TYPE(BType)
BOOST_TTI_MEMBER_TYPE(CType)

BOOST_TTI_MTFC_MEMBER_TYPE(CType)

#endif // TEST_MF_HAS_TYPE_HPP
