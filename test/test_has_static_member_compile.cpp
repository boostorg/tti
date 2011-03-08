#include "test_has_static_member.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  boost::tti::TheTIntFunction<AType,void (long,double)> aVar;
  boost::tti::Pickedname<AnotherType,AType (long,long)> aVar3;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((boost::tti::HaveTheSIntFunction<AType,int (long,double)>));
  BOOST_MPL_ASSERT((boost::tti::TheTIntFunction<AnotherType,AType (long,double)>));
  BOOST_MPL_ASSERT((boost::tti::has_static_member_TSFunction<AnotherType,AType::AStructType (AType::AnIntType,double)>));
  
  return 0;

  }
