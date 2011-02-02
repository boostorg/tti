#include "TestHasStaticMemberFunction.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  tti::TheTIntFunction<AType,void,boost::mpl::vector<long,double> > aVar;
  tti::Pickedname<AnotherType,AType,boost::mpl::vector<long,long> > aVar3;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((tti::HaveTheSIntFunction<AType,int,boost::mpl::vector<long,double> >));
  BOOST_MPL_ASSERT((tti::TheTIntFunction<AnotherType,AType,boost::mpl::vector<long,double> >));
  BOOST_MPL_ASSERT((tti::has_static_member_function_TSFunction<AnotherType,AType::AStructType,boost::mpl::vector<AType::AnIntType,double> >));
  
  return 0;

  }
