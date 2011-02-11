#include "test_mf_has_template_check_params.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  BOOST_TEST((tti::mf_has_template_check_params
                <
                tti::HT_Str<_>,
                tti::member_type_AStructType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_template_check_params
                <
                tti::has_template_check_params_AnotherMemberTemplate<_>,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((!tti::mf_has_template_check_params
                <
                tti::WrongParametersForMP<_>,
                boost::mpl::identity<AnotherType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_template_check_params
                <
                tti::has_template_check_params_CTManyParameters<_>,
                tti::mf_member_type
                  <
                  tti::member_type_CType<_>,
                  tti::MT_BType<AType>
                  >
                >
              ::value
            ));
  
  BOOST_TEST((!tti::mf_has_template_check_params
                <
                tti::has_template_check_params_TemplateNotExist<_>,
                tti::mf_member_type
                  <
                  tti::member_type_CType<_>,
                  tti::MT_BType<AType>
                  >
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_template_check_params
                <
                tti::MF_HT_Str,
                tti::member_type_AStructType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_template_check_params
                <
                tti::mtfc_has_template_check_params_AnotherMemberTemplate,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((!tti::mf_has_template_check_params
                <
                tti::MetaCWrongParametersForMP,
                boost::mpl::identity<AnotherType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_template_check_params
                <
                tti::mtfc_has_template_check_params_CTManyParameters,
                tti::mf_member_type
                  <
                  tti::member_type_CType<_>,
                  tti::MT_BType<AType>
                  >
                >
              ::value
            ));
  
  BOOST_TEST((!tti::mf_has_template_check_params
                <
                tti::mtfc_has_template_check_params_TemplateNotExist,
                tti::mf_member_type
                  <
                  tti::member_type_CType<_>,
                  tti::MT_BType<AType>
                  >
                >
              ::value
            ));
  
  return boost::report_errors();
  
  }
