#include "TestHasTypeCheckTypedef.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  tti::TheInteger<AType::BType,short> aVar;
  tti::has_type_check_typedef_NoOtherType<AnotherType,double> aVar2;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((tti::has_type_check_typedef_AnIntType<AType,int>));
  BOOST_MPL_ASSERT((tti::NameStruct<AType,AType::AStructType>));
  BOOST_MPL_ASSERT((tti::has_type_check_typedef_AnIntTypeReference<AType,int &>));
  BOOST_MPL_ASSERT((tti::has_type_check_typedef_BType<AType,AType::BType>));
  BOOST_MPL_ASSERT((tti::TheInteger<AType::BType,int>));
  BOOST_MPL_ASSERT((tti::has_type_check_typedef_CType<AType::BType,AType::BType::CType>));
  BOOST_MPL_ASSERT((tti::has_type_check_typedef_AnotherIntegerType<AType::BType::CType,int>));
  BOOST_MPL_ASSERT((tti::SomethingElse<AnotherType,AType::AnIntType>));
  
  return 0;

  }
