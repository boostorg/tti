#include "TestMFHasTemplateCheckParams.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // You can always instantiate without compiler errors
  
  tti::mf_has_template_check_params
                <
                tti::has_template_check_params_TemplateNotExist<_>,
                tti::mf_member_type
                  <
                  tti::mtfc_member_type_CType,
                  tti::MT_BType<AType>
                  >
                > aVar;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((tti::mf_has_template_check_params
                      <
                      tti::HT_Str<_>,
                      tti::member_type_AStructType<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_template_check_params
                      <
                      tti::has_template_check_params_AnotherMemberTemplate<_>,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_template_check_params
                      <
                      tti::has_template_check_params_CTManyParameters<_>,
                      tti::mf_member_type
                        <
                        tti::member_type_CType<_>,
                        tti::MT_BType<AType>
                        >
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_template_check_params
                      <
                      tti::MF_HT_Str,
                      tti::member_type_AStructType<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_template_check_params
                      <
                      tti::mtfc_has_template_check_params_AnotherMemberTemplate,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_template_check_params
                      <
                      tti::mtfc_has_template_check_params_CTManyParameters,
                      tti::mf_member_type
                        <
                        tti::mtfc_member_type_CType,
                        tti::MT_BType<AType>
                        >
                      >
                  ));
  
  return 0;
  
  }
