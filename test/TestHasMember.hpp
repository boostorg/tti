#if !defined(TEST_HAS_MEMBER_HPP)
#define TEST_HAS_MEMBER_HPP

#include "TestStructs.hpp"
#include <boost/tti/TTIntrospection.hpp>

TTI_HAS_MEMBER(AnInt)
TTI_HAS_MEMBER(VoidFunction)
TTI_HAS_MEMBER(IntFunction)
TTI_HAS_MEMBER(aFunction)
TTI_HAS_MEMBER(anotherFunction)
TTI_HAS_MEMBER(sFunction)
TTI_HAS_MEMBER(aMember)
TTI_HAS_MEMBER(cMem)
TTI_HAS_MEMBER(someDataMember)
TTI_HAS_MEMBER(someFunctionMember)

#endif // TEST_HAS_MEMBER_HPP
