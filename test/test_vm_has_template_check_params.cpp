#include "test_vm_has_template_cp.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
#if !defined(BOOST_NO_VARIADIC_MACROS)

  BOOST_TEST(boost::tti::has_template_check_params_ATPMemberTemplate<AType>::value);
  BOOST_TEST(boost::tti::HaveCL<AType>::value);
  BOOST_TEST(boost::tti::has_template_check_params_AMemberTemplate<AType>::value);
  BOOST_TEST(boost::tti::HaveAnotherMT<AType>::value);
  BOOST_TEST(boost::tti::has_template_check_params_SomeMemberTemplate<AnotherType>::value);
  BOOST_TEST(boost::tti::ATemplateWithParms<AnotherType>::value);
  BOOST_TEST(boost::tti::has_template_check_params_SimpleTMP<AnotherType>::value);
  BOOST_TEST(!boost::tti::has_template_check_params_TemplateNotExist<AnotherType>::value);

#endif //!defined(BOOST_NO_VARIADIC_MACROS)

  return boost::report_errors();

  }
