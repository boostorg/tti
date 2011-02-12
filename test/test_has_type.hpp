#if !defined(TEST_HAS_TYPE_HPP)
#define TEST_HAS_TYPE_HPP

#include "test_structs.hpp"
#include <boost/tti/tti.hpp>

BOOST_TTI_HAS_TYPE(AnIntType)
BOOST_TTI_TRAIT_HAS_TYPE(NameStruct,AStructType)
BOOST_TTI_HAS_TYPE(AnIntTypeReference)
BOOST_TTI_HAS_TYPE(BType)
BOOST_TTI_TRAIT_HAS_TYPE(TheInteger,AnIntegerType)
BOOST_TTI_HAS_TYPE(CType)
BOOST_TTI_HAS_TYPE(AnotherIntegerType)
BOOST_TTI_TRAIT_HAS_TYPE(SomethingElse,someOtherType)
BOOST_TTI_HAS_TYPE(NoOtherType)

#endif // TEST_HAS_TYPE_HPP
