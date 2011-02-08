#include "TestMFHasTemplate.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // You can always instantiate without compiler errors
  
  tti::mf_has_template
    <
    tti::has_template_TemplateNotExist<_>,
    tti::MT_BType<AType>
    > aVar;
    
  tti::mf_has_template
    <
    tti::mtfc_has_template_ATPMemberTemplate,
    boost::mpl::identity<AnotherType>
    > aVar2;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((tti::mf_has_template
                      <
                      tti::HaveMStr<_>,
                      tti::member_type_AStructType<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_template
                      <
                      tti::has_template_ATPMemberTemplate<_>,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_template
                      <
                      tti::HaveCL<_>,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_template
                      <
                      tti::has_template_SimpleTMP<_>,
                      boost::mpl::identity<AnotherType>
                      >
                  ));

  BOOST_MPL_ASSERT((tti::mf_has_template
                      <
                      tti::MetaHaveMStr,
                      tti::member_type_AStructType<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_template
                      <
                      tti::mtfc_has_template_ATPMemberTemplate,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_template
                      <
                      tti::MFClassHaveCL,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_template
                      <
                      tti::mtfc_has_template_SimpleTMP,
                      boost::mpl::identity<AnotherType>
                      >
                  ));
  
  return 0;
  
  }
