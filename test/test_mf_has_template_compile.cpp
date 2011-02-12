#include "test_mf_has_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // You can always instantiate without compiler errors
  
  boost::tti::mf_has_template
    <
    boost::tti::has_template_TemplateNotExist<_>,
    boost::tti::MT_BType<AType>
    > aVar;
    
  boost::tti::mf_has_template
    <
    boost::tti::mtfc_has_template_ATPMemberTemplate,
    boost::mpl::identity<AnotherType>
    > aVar2;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template
                      <
                      boost::tti::HaveMStr<_>,
                      boost::tti::member_type_AStructType<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template
                      <
                      boost::tti::has_template_ATPMemberTemplate<_>,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template
                      <
                      boost::tti::HaveCL<_>,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template
                      <
                      boost::tti::has_template_SimpleTMP<_>,
                      boost::mpl::identity<AnotherType>
                      >
                  ));

  BOOST_MPL_ASSERT((boost::tti::mf_has_template
                      <
                      boost::tti::MetaHaveMStr,
                      boost::tti::member_type_AStructType<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template
                      <
                      boost::tti::mtfc_has_template_ATPMemberTemplate,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template
                      <
                      boost::tti::MFClassHaveCL,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template
                      <
                      boost::tti::mtfc_has_template_SimpleTMP,
                      boost::mpl::identity<AnotherType>
                      >
                  ));
  
  return 0;
  
  }
