#include "test_has_static_mem_fun.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST((boost::tti::HaveTheSIntFunction<AType,int,boost::mpl::vector<long,double> >::value));
  BOOST_TEST((!boost::tti::TheTIntFunction<AType,AType,boost::mpl::vector<long,double> >::value));
  BOOST_TEST((boost::tti::TheTIntFunction<AnotherType,AType,boost::mpl::vector<long,double> >::value));
  BOOST_TEST((boost::tti::has_static_member_function_TSFunction<AnotherType,AType::AStructType,boost::mpl::vector<AType::AnIntType,double> >::value));
  BOOST_TEST((!boost::tti::Pickedname<AnotherType,void>::value));
  
  return boost::report_errors();

  }
