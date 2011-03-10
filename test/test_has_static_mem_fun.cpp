#include "test_has_static_mem_fun.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST((BOOST_TTI_TRAIT_GEN(HaveTheSIntFunction)<AType,int,boost::mpl::vector<long,double> >::value));
  BOOST_TEST((!BOOST_TTI_TRAIT_GEN(TheTIntFunction)<AType,AType,boost::mpl::vector<long,double> >::value));
  BOOST_TEST((BOOST_TTI_TRAIT_GEN(TheTIntFunction)<AnotherType,AType,boost::mpl::vector<long,double> >::value));
  BOOST_TEST((BOOST_TTI_HAS_STATIC_MEMBER_FUNCTION_GEN(TSFunction)<AnotherType,AType::AStructType,boost::mpl::vector<AType::AnIntType,double> >::value));
  BOOST_TEST((!BOOST_TTI_TRAIT_GEN(Pickedname)<AnotherType,void>::value));
  
  return boost::report_errors();

  }
