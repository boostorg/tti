#if !defined(TEST_MF_HAS_MEMBER_DATA_HPP)
#define TEST_MF_HAS_MEMBER_DATA_HPP

#include "TestStructs.hpp"
#include <boost/tti/TTIntrospection.hpp>

TTI_HAS_MEMBER(AnInt)
TTI_HAS_MEMBER(aMember)
TTI_TRAIT_HAS_MEMBER(CMember,cMem)
TTI_HAS_MEMBER(someDataMember)

#endif // TEST_MF_HAS_MEMBER_DATA_HPP
