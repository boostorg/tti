#include "TestMFHasTemplate.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST((tti::mf_has_template
                <
                tti::HaveMStr,
                tti::member_type_AStructType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((!tti::mf_has_template
                <
                tti::has_template_TemplateNotExist,
                tti::MT_BType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_template
                <
                tti::has_template_ATPMemberTemplate,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_template
                <
                tti::HaveCL,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_template
                <
                tti::has_template_SimpleTMP,
                boost::mpl::identity<AnotherType>
                >
              ::value
            ));
  
  return boost::report_errors();
  
  }
