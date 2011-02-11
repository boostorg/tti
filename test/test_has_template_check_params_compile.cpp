#include "test_has_template_check_params.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  tti::has_template_check_params_TemplateNotExist<AnotherType> aVar1;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((tti::has_template_check_params_ATPMemberTemplate<AType>));
  BOOST_MPL_ASSERT((tti::HaveCL<AType>));
  BOOST_MPL_ASSERT((tti::has_template_check_params_AMemberTemplate<AType>));
  BOOST_MPL_ASSERT((tti::HaveAnotherMT<AType>));
  BOOST_MPL_ASSERT((tti::has_template_check_params_SomeMemberTemplate<AnotherType>));
  BOOST_MPL_ASSERT((tti::ATemplateWithParms<AnotherType>));
  BOOST_MPL_ASSERT((tti::has_template_check_params_SimpleTMP<AnotherType>));
  
  return 0;

  }
