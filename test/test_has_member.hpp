#if !defined(TEST_HAS_MEMBER_HPP)
#define TEST_HAS_MEMBER_HPP

#include "test_structs.hpp"
#include <boost/tti/comp_mem_fun.hpp>

BOOST_TTI_HAS_MEMBER(AnInt)
BOOST_TTI_HAS_MEMBER(VoidFunction)
BOOST_TTI_TRAIT_HAS_MEMBER(FunctionReturningInt,IntFunction)
BOOST_TTI_HAS_MEMBER(aFunction)
BOOST_TTI_TRAIT_HAS_MEMBER(AnotherIntFunction,anotherFunction)
BOOST_TTI_HAS_MEMBER(sFunction)
BOOST_TTI_HAS_MEMBER(aMember)
BOOST_TTI_TRAIT_HAS_MEMBER(CMember,cMem)
BOOST_TTI_HAS_MEMBER(someDataMember)
BOOST_TTI_HAS_MEMBER(someFunctionMember)
BOOST_TTI_HAS_MEMBER(IntBT)
BOOST_TTI_TRAIT_HAS_MEMBER(NestedData,NestedCT)
BOOST_TTI_TRAIT_HAS_MEMBER(AOther,OtherAT)
BOOST_TTI_HAS_MEMBER(ONestStr)

#endif // TEST_HAS_MEMBER_HPP
