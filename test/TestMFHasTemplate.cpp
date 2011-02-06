#include "TestMFHasTemplate.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  BOOST_TEST((tti::mf_has_template
                <
                tti::HaveMStr<_>,
                tti::member_type_AStructType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((!tti::mf_has_template
                <
                tti::has_template_TemplateNotExist<_>,
                tti::MT_BType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_template
                <
                tti::has_template_ATPMemberTemplate<_>,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_template
                <
                tti::HaveCL<_>,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_template
                <
                tti::has_template_SimpleTMP<_>,
                boost::mpl::identity<AnotherType>
                >
              ::value
            ));
  
  return boost::report_errors();
  
  }
