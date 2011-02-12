#include "test_mf_has_template.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  BOOST_TEST((boost::tti::mf_has_template
                <
                boost::tti::HaveMStr<_>,
                boost::tti::member_type_AStructType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((!boost::tti::mf_has_template
                <
                boost::tti::has_template_TemplateNotExist<_>,
                boost::tti::MT_BType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_template
                <
                boost::tti::has_template_ATPMemberTemplate<_>,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_template
                <
                boost::tti::HaveCL<_>,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_template
                <
                boost::tti::has_template_SimpleTMP<_>,
                boost::mpl::identity<AnotherType>
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_template
                <
                boost::tti::MetaHaveMStr,
                boost::tti::member_type_AStructType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((!boost::tti::mf_has_template
                <
                boost::tti::mtfc_has_template_TemplateNotExist,
                boost::tti::MT_BType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_template
                <
                boost::tti::mtfc_has_template_ATPMemberTemplate,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_template
                <
                boost::tti::MFClassHaveCL,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_template
                <
                boost::tti::mtfc_has_template_SimpleTMP,
                boost::mpl::identity<AnotherType>
                >
              ::value
            ));
  
  return boost::report_errors();
  
  }
