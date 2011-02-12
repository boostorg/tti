#include "test_has_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  boost::tti::has_template_AMemberTemplate<AnotherType> aVar;
  boost::tti::HaveAnotherMT<AnotherType> aVar2;
  boost::tti::has_template_SomeMemberTemplate<AType> aVar3;
  boost::tti::has_template_TemplateNotExist<AType> aVar4;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((boost::tti::has_template_ATPMemberTemplate<AType>));
  BOOST_MPL_ASSERT((boost::tti::HaveCL<AType>));
  BOOST_MPL_ASSERT((boost::tti::has_template_SimpleTMP<AnotherType>));
  
  return 0;

  }
