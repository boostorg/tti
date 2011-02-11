#if !defined(TEST_HAS_STATIC_MEMBER_HPP)
#define TEST_HAS_STATIC_MEMBER_HPP

#include "test_structs.hpp"
#include <boost/tti/tti.hpp>

TTI_HAS_STATIC_MEMBER(DSMember)
TTI_TRAIT_HAS_STATIC_MEMBER(HaveTheSIntFunction,SIntFunction)
TTI_TRAIT_HAS_STATIC_MEMBER(TheTIntFunction,TIntFunction)
TTI_HAS_STATIC_MEMBER(TSFunction)
TTI_HAS_STATIC_MEMBER(SomeStaticData)
TTI_TRAIT_HAS_STATIC_MEMBER(Pickedname,SomeStaticFunction)

#endif // TEST_HAS_STATIC_MEMBER_HPP
