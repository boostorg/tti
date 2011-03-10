#include "test_has_mem_fun.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST((BOOST_TTI_HAS_MEMBER_FUNCTION_GEN(VoidFunction)<AType,void>::value));
  BOOST_TEST((BOOST_TTI_TRAIT_GEN(FunctionReturningInt)<AType,int>::value));
  BOOST_TEST((BOOST_TTI_TRAIT_GEN(FunctionReturningInt)<AnotherType,double,boost::mpl::vector<int> >::value));
  BOOST_TEST((BOOST_TTI_HAS_MEMBER_FUNCTION_GEN(aFunction)<AnotherType,AType,boost::mpl::vector<int> >::value));
  BOOST_TEST((BOOST_TTI_TRAIT_GEN(AnotherIntFunction)<AnotherType,int,boost::mpl::vector<AType> >::value));
  BOOST_TEST((BOOST_TTI_HAS_MEMBER_FUNCTION_GEN(sFunction)<AnotherType,AType::AnIntType,boost::mpl::vector<int,long,double> >::value));
  BOOST_TEST((!BOOST_TTI_HAS_MEMBER_FUNCTION_GEN(someFunctionMember)<AnotherType,AType,boost::mpl::vector<long,int> >::value));
  
  return boost::report_errors();

  }
