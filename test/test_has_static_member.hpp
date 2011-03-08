#if !defined(TEST_HAS_STATIC_MEMBER_HPP)
#define TEST_HAS_STATIC_MEMBER_HPP

#include "test_structs.hpp"
#include <boost/tti/static_member.hpp>

BOOST_TTI_TRAIT_HAS_STATIC_MEMBER(HaveTheSIntFunction,SIntFunction)
BOOST_TTI_TRAIT_HAS_STATIC_MEMBER(TheTIntFunction,TIntFunction)
BOOST_TTI_HAS_STATIC_MEMBER(TSFunction)
BOOST_TTI_TRAIT_HAS_STATIC_MEMBER(Pickedname,SomeStaticFunction)

#endif // TEST_HAS_STATIC_MEMBER_HPP
