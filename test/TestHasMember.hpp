#if !defined(TEST_HAS_MEMBER_HPP)
#define TEST_HAS_MEMBER_HPP

#include "TestStructs.hpp"
#include <boost/tti/TTIntrospection.hpp>

TTI_HAS_MEMBER(AnInt)
TTI_HAS_MEMBER(VoidFunction)
TTI_TRAIT_HAS_MEMBER(FunctionReturningInt,IntFunction)
TTI_HAS_MEMBER(aFunction)
TTI_TRAIT_HAS_MEMBER(AnotherIntFunction,anotherFunction)
TTI_HAS_MEMBER(sFunction)
TTI_HAS_MEMBER(aMember)
TTI_TRAIT_HAS_MEMBER(CMember,cMem)
TTI_HAS_MEMBER(someDataMember)
TTI_HAS_MEMBER(someFunctionMember)
TTI_HAS_MEMBER(IntBT)
TTI_TRAIT_HAS_MEMBER(NestedData,NestedCT)
TTI_TRAIT_HAS_MEMBER(AOther,OtherAT)
TTI_HAS_MEMBER(ONestStr)

#endif // TEST_HAS_MEMBER_HPP
