#if !defined(TEST_HAS_MEMBER_HPP)
#define TEST_HAS_MEMBER_HPP

#include "test_structs.hpp"
#include <boost/tti/comp_mem_fun.hpp>

BOOST_TTI_HAS_COMP_MEMBER_FUNCTION(VoidFunction)
BOOST_TTI_TRAIT_HAS_COMP_MEMBER_FUNCTION(FunctionReturningInt,IntFunction)
BOOST_TTI_HAS_COMP_MEMBER_FUNCTION(aFunction)
BOOST_TTI_TRAIT_HAS_COMP_MEMBER_FUNCTION(AnotherIntFunction,anotherFunction)
BOOST_TTI_HAS_COMP_MEMBER_FUNCTION(sFunction)
BOOST_TTI_HAS_COMP_MEMBER_FUNCTION(someFunctionMember)

#endif // TEST_HAS_MEMBER_HPP
