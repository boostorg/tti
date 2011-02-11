#include "test_has_template_check_params.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST(tti::has_template_check_params_ATPMemberTemplate<AType>::value);
  BOOST_TEST(tti::HaveCL<AType>::value);
  BOOST_TEST(tti::has_template_check_params_AMemberTemplate<AType>::value);
  BOOST_TEST(tti::HaveAnotherMT<AType>::value);
  BOOST_TEST(tti::has_template_check_params_SomeMemberTemplate<AnotherType>::value);
  BOOST_TEST(tti::ATemplateWithParms<AnotherType>::value);
  BOOST_TEST(tti::has_template_check_params_SimpleTMP<AnotherType>::value);
  BOOST_TEST(!tti::has_template_check_params_TemplateNotExist<AnotherType>::value);

  return boost::report_errors();

  }
