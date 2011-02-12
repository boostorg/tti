#include "test_has_static_member_function.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  boost::tti::TheTIntFunction<AType,void,boost::mpl::vector<long,double> > aVar;
  boost::tti::Pickedname<AnotherType,AType,boost::mpl::vector<long,long> > aVar3;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((boost::tti::HaveTheSIntFunction<AType,int,boost::mpl::vector<long,double> >));
  BOOST_MPL_ASSERT((boost::tti::TheTIntFunction<AnotherType,AType,boost::mpl::vector<long,double> >));
  BOOST_MPL_ASSERT((boost::tti::has_static_member_function_TSFunction<AnotherType,AType::AStructType,boost::mpl::vector<AType::AnIntType,double> >));
  
  return 0;

  }
