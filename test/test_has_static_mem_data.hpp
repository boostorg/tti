#if !defined(TEST_HAS_STATIC_MEMBER_DATA_HPP)
#define TEST_HAS_STATIC_MEMBER_DATA_HPP

#include "test_structs.hpp"
#include <boost/tti/static_mem_data.hpp>

BOOST_TTI_HAS_STATIC_MEMBER_DATA(DSMember)
BOOST_TTI_TRAIT_HAS_STATIC_MEMBER_DATA(StatName,AnStat)
BOOST_TTI_HAS_STATIC_MEMBER_DATA(SomeStaticData)

#endif // TEST_HAS_STATIC_MEMBER_DATA_HPP
