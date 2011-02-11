#include "test_has_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  tti::has_template_AMemberTemplate<AnotherType> aVar;
  tti::HaveAnotherMT<AnotherType> aVar2;
  tti::has_template_SomeMemberTemplate<AType> aVar3;
  tti::has_template_TemplateNotExist<AType> aVar4;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((tti::has_template_ATPMemberTemplate<AType>));
  BOOST_MPL_ASSERT((tti::HaveCL<AType>));
  BOOST_MPL_ASSERT((tti::has_template_SimpleTMP<AnotherType>));
  
  return 0;

  }
