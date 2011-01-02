#include "TestMFHasTemplateCheckParams.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST((tti::mf_has_template_check_params
                <
                tti::HT_Str,
                tti::member_type_AStructType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_template_check_params
                <
                tti::has_template_check_params_AnotherMemberTemplate,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((!tti::mf_has_template_check_params
                <
                tti::WrongParametersForMP,
                boost::mpl::identity<AnotherType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_template_check_params
                <
                tti::has_template_check_params_CTManyParameters,
                tti::mf_member_type
                  <
                  tti::member_type_CType,
                  tti::MT_BType<AType>
                  >
                >
              ::value
            ));
  
  BOOST_TEST((!tti::mf_has_template_check_params
                <
                tti::has_template_check_params_TemplateNotExist,
                tti::mf_member_type
                  <
                  tti::member_type_CType,
                  tti::MT_BType<AType>
                  >
                >
              ::value
            ));
  
  return boost::report_errors();
  
  }
