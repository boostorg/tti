#include "test_has_static_member_function.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST((tti::HaveTheSIntFunction<AType,int,boost::mpl::vector<long,double> >::value));
  BOOST_TEST((!tti::TheTIntFunction<AType,AType,boost::mpl::vector<long,double> >::value));
  BOOST_TEST((tti::TheTIntFunction<AnotherType,AType,boost::mpl::vector<long,double> >::value));
  BOOST_TEST((tti::has_static_member_function_TSFunction<AnotherType,AType::AStructType,boost::mpl::vector<AType::AnIntType,double> >::value));
  BOOST_TEST((!tti::Pickedname<AnotherType,void>::value));
  
  return boost::report_errors();

  }
