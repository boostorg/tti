#include "TestMFHasTemplate.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // You can always instantiate without compiler errors
  
  tti::mf_has_template
    <
    tti::has_template_TemplateNotExist,
    tti::MT_BType<AType>
    > aVar;
    
  tti::mf_has_template
    <
    tti::has_template_ATPMemberTemplate,
    boost::mpl::identity<AnotherType>
    > aVar2;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((tti::mf_has_template
                      <
                      tti::HaveMStr,
                      tti::member_type_AStructType<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_template
                      <
                      tti::has_template_ATPMemberTemplate,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_template
                      <
                      tti::HaveCL,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_template
                      <
                      tti::has_template_SimpleTMP,
                      boost::mpl::identity<AnotherType>
                      >
                  ));
  
  return 0;
  
  }
