#include "test_mf_has_template_check_params.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  BOOST_TEST((boost::tti::mf_has_template_check_params
                <
                boost::tti::HT_Str<_>,
                boost::tti::member_type_AStructType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_template_check_params
                <
                boost::tti::has_template_check_params_AnotherMemberTemplate<_>,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((!boost::tti::mf_has_template_check_params
                <
                boost::tti::WrongParametersForMP<_>,
                boost::mpl::identity<AnotherType>
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_template_check_params
                <
                boost::tti::has_template_check_params_CTManyParameters<_>,
                boost::tti::mf_member_type
                  <
                  boost::tti::member_type_CType<_>,
                  boost::tti::MT_BType<AType>
                  >
                >
              ::value
            ));
  
  BOOST_TEST((!boost::tti::mf_has_template_check_params
                <
                boost::tti::has_template_check_params_TemplateNotExist<_>,
                boost::tti::mf_member_type
                  <
                  boost::tti::member_type_CType<_>,
                  boost::tti::MT_BType<AType>
                  >
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_template_check_params
                <
                boost::tti::MF_HT_Str,
                boost::tti::member_type_AStructType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_template_check_params
                <
                boost::tti::mtfc_has_template_check_params_AnotherMemberTemplate,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((!boost::tti::mf_has_template_check_params
                <
                boost::tti::MetaCWrongParametersForMP,
                boost::mpl::identity<AnotherType>
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_template_check_params
                <
                boost::tti::mtfc_has_template_check_params_CTManyParameters,
                boost::tti::mf_member_type
                  <
                  boost::tti::member_type_CType<_>,
                  boost::tti::MT_BType<AType>
                  >
                >
              ::value
            ));
  
  BOOST_TEST((!boost::tti::mf_has_template_check_params
                <
                boost::tti::mtfc_has_template_check_params_TemplateNotExist,
                boost::tti::mf_member_type
                  <
                  boost::tti::member_type_CType<_>,
                  boost::tti::MT_BType<AType>
                  >
                >
              ::value
            ));
  
  return boost::report_errors();
  
  }
