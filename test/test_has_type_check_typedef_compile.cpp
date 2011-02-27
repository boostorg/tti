#include "test_has_type_ct.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  boost::tti::TheInteger<AType::BType,short> aVar;
  boost::tti::has_type_NoOtherType<AnotherType,double> aVar2;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((boost::tti::has_type_AnIntType<AType,int>));
  BOOST_MPL_ASSERT((boost::tti::NameStruct<AType,AType::AStructType>));
  BOOST_MPL_ASSERT((boost::tti::has_type_AnIntTypeReference<AType,int &>));
  BOOST_MPL_ASSERT((boost::tti::has_type_BType<AType,AType::BType>));
  BOOST_MPL_ASSERT((boost::tti::TheInteger<AType::BType,int>));
  BOOST_MPL_ASSERT((boost::tti::has_type_CType<AType::BType,AType::BType::CType>));
  BOOST_MPL_ASSERT((boost::tti::has_type_AnotherIntegerType<AType::BType::CType,int>));
  BOOST_MPL_ASSERT((boost::tti::SomethingElse<AnotherType,AType::AnIntType>));
  
  return 0;

  }
