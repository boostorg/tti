#include "test_has_mem_data.hpp"
#include <boost/tti/gen/trait_gen.hpp>
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST((BOOST_TTI_HAS_MEMBER_DATA_GEN(AnInt)<AType,int>::value));
  BOOST_TEST((BOOST_TTI_HAS_MEMBER_DATA_GEN(AnInt)<AnotherType,long>::value));
  BOOST_TEST((BOOST_TTI_HAS_MEMBER_DATA_GEN(aMember)<AnotherType,bool>::value));
  BOOST_TEST((!BOOST_TTI_HAS_MEMBER_DATA_GEN(aMember)<AnotherType,int>::value));
  BOOST_TEST((BOOST_TTI_TRAIT_GEN(CMember)<AnotherType,bool>::value));
  BOOST_TEST((!BOOST_TTI_HAS_MEMBER_DATA_GEN(someDataMember)<AType,short>::value));
  BOOST_TEST((BOOST_TTI_HAS_MEMBER_DATA_GEN(IntBT)<AType,AType::BType>::value));
  BOOST_TEST((BOOST_TTI_TRAIT_GEN(NestedData)<AType,AType::BType::CType>::value));
  BOOST_TEST((BOOST_TTI_TRAIT_GEN(AOther)<AnotherType,AType>::value));
  BOOST_TEST((BOOST_TTI_HAS_MEMBER_DATA_GEN(ONestStr)<AnotherType,AType::AStructType>::value));
  
  return boost::report_errors();

  }
