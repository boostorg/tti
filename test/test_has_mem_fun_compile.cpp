#include "test_has_mem_fun.hpp"
#include <boost/tti/gen/trait_gen.hpp>
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  BOOST_TTI_HAS_MEMBER_FUNCTION_GEN(someFunctionMember)<AnotherType,double,boost::mpl::vector<short,short,long,int> > aVar3;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_MEMBER_FUNCTION_GEN(VoidFunction)<AType,void>));
  BOOST_MPL_ASSERT((BOOST_TTI_TRAIT_GEN(FunctionReturningInt)<AType,int>));
  BOOST_MPL_ASSERT((BOOST_TTI_TRAIT_GEN(FunctionReturningInt)<AnotherType,double,boost::mpl::vector<int> >));
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_MEMBER_FUNCTION_GEN(aFunction)<AnotherType,AType,boost::mpl::vector<int> >));
  BOOST_MPL_ASSERT((BOOST_TTI_TRAIT_GEN(AnotherIntFunction)<AnotherType,int,boost::mpl::vector<AType> >));
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_MEMBER_FUNCTION_GEN(sFunction)<AnotherType,AType::AnIntType,boost::mpl::vector<int,long,double> >));
  
  return 0;

  }
