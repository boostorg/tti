#if !defined(TEST_MF_HAS_MEMBER_FUNCTION_HPP)
#define TEST_MF_HAS_MEMBER_FUNCTION_HPP

#include "TestStructs.hpp"
#include <boost/tti/TTIntrospection.hpp>

TTI_HAS_MEMBER(VoidFunction)
TTI_TRAIT_HAS_MEMBER(FunctionReturningInt,IntFunction)
TTI_HAS_MEMBER(aFunction)
TTI_TRAIT_HAS_MEMBER(AnotherIntFunction,anotherFunction)
TTI_HAS_MEMBER(sFunction)
TTI_HAS_MEMBER(someFunctionMember)

TTI_MEMBER_TYPE(AnIntType)

#endif // TEST_MF_HAS_MEMBER_FUNCTION_HPP
