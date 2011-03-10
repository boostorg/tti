#include "test_has_type.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST(BOOST_TTI_HAS_TYPE_GEN(AnIntType)<AType>::value);
  BOOST_TEST(BOOST_TTI_HAS_TYPE_GEN(AnIntTypeReference)<AType>::value);
  BOOST_TEST(BOOST_TTI_TRAIT_GEN(NameStruct)<AType>::value);
  BOOST_TEST(BOOST_TTI_HAS_TYPE_GEN(BType)<AType>::value);
  BOOST_TEST(BOOST_TTI_TRAIT_GEN(TheInteger)<AType::BType>::value);
  BOOST_TEST(BOOST_TTI_HAS_TYPE_GEN(CType)<AType::BType>::value);
  BOOST_TEST(BOOST_TTI_HAS_TYPE_GEN(AnotherIntegerType)<AType::BType::CType>::value);
  BOOST_TEST(BOOST_TTI_TRAIT_GEN(SomethingElse)<AnotherType>::value);
  BOOST_TEST(!BOOST_TTI_HAS_TYPE_GEN(NoOtherType)<AnotherType>::value);
  
  return boost::report_errors();

  }
