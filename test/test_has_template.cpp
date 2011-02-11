#include "test_has_template.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST(tti::has_template_ATPMemberTemplate<AType>::value);
  BOOST_TEST(tti::HaveCL<AType>::value);
  BOOST_TEST(!tti::has_template_AMemberTemplate<AType>::value);
  BOOST_TEST(!tti::HaveAnotherMT<AType>::value);
  BOOST_TEST(!tti::has_template_SomeMemberTemplate<AnotherType>::value);
  BOOST_TEST(!tti::ATemplateWithParms<AnotherType>::value);
  BOOST_TEST(tti::has_template_SimpleTMP<AnotherType>::value);

  return boost::report_errors();
  
  }
