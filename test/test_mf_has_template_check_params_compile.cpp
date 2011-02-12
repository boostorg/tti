#include "test_mf_has_template_check_params.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // You can always instantiate without compiler errors
  
  boost::tti::mf_has_template_check_params
                <
                boost::tti::has_template_check_params_TemplateNotExist<_>,
                boost::tti::mf_member_type
                  <
                  boost::tti::mtfc_member_type_CType,
                  boost::tti::MT_BType<AType>
                  >
                > aVar;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template_check_params
                      <
                      boost::tti::HT_Str<_>,
                      boost::tti::member_type_AStructType<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template_check_params
                      <
                      boost::tti::has_template_check_params_AnotherMemberTemplate<_>,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template_check_params
                      <
                      boost::tti::has_template_check_params_CTManyParameters<_>,
                      boost::tti::mf_member_type
                        <
                        boost::tti::member_type_CType<_>,
                        boost::tti::MT_BType<AType>
                        >
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template_check_params
                      <
                      boost::tti::MF_HT_Str,
                      boost::tti::member_type_AStructType<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template_check_params
                      <
                      boost::tti::mtfc_has_template_check_params_AnotherMemberTemplate,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template_check_params
                      <
                      boost::tti::mtfc_has_template_check_params_CTManyParameters,
                      boost::tti::mf_member_type
                        <
                        boost::tti::mtfc_member_type_CType,
                        boost::tti::MT_BType<AType>
                        >
                      >
                  ));
  
  return 0;
  
  }
