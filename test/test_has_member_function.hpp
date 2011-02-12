#if !defined(TEST_HAS_MEMBER_FUNCTION_HPP)
#define TEST_HAS_MEMBER_FUNCTION_HPP

#include "test_structs.hpp"
#include <boost/tti/tti.hpp>

BOOST_TTI_HAS_MEMBER_FUNCTION(VoidFunction)
BOOST_TTI_TRAIT_HAS_MEMBER_FUNCTION(FunctionReturningInt,IntFunction)
BOOST_TTI_HAS_MEMBER_FUNCTION(aFunction)
BOOST_TTI_TRAIT_HAS_MEMBER_FUNCTION(AnotherIntFunction,anotherFunction)
BOOST_TTI_HAS_MEMBER_FUNCTION(sFunction)
BOOST_TTI_HAS_MEMBER_FUNCTION(someFunctionMember)

#endif // TEST_HAS_MEMBER_FUNCTION_HPP
