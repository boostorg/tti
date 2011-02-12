#include "test_mf_member_type.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  BOOST_TEST((boost::tti::mf_valid_member_type
                <
                boost::tti::mf_member_type
                  <
                  boost::tti::member_type_AnIntType<_>,
                  boost::mpl::identity<AType>
                  >
                >
              ::value
            ));
            
  BOOST_TEST((boost::tti::mf_valid_member_type
                <
                boost::tti::mf_member_type
                  <
                  boost::tti::NameStruct<_>,
                  boost::mpl::identity<AType>
                  >
                >
              ::value
            ));
            
  BOOST_TEST((boost::tti::mf_valid_member_type
                <
                boost::tti::mf_member_type
                  <
                  boost::tti::member_type_AnIntTypeReference<_>,
                  boost::mpl::identity<AType>
                  >
                >
              ::value
            ));
            
  BOOST_TEST((boost::tti::mf_valid_member_type
                <
                boost::tti::mf_member_type
                  <
                  boost::tti::member_type_BType<_>,
                  boost::mpl::identity<AType>
                  >
                >
              ::value
            ));
            
  BOOST_TEST((boost::tti::mf_valid_member_type
                <
                boost::tti::mf_member_type
                  <
                  boost::tti::TheInteger<_>,
                  boost::tti::member_type_BType<AType>
                  >
                >
              ::value
            ));
            
  BOOST_TEST((boost::tti::mf_valid_member_type
                <
                boost::tti::mf_member_type
                  <
                  boost::tti::member_type_CType<_>,
                  boost::tti::member_type_BType<AType>
                  >
                >
              ::value
            ));
            
  BOOST_TEST((boost::tti::mf_valid_member_type
                <
                boost::tti::mf_member_type
                  <
                  boost::tti::member_type_AnotherIntegerType<_>,
                  boost::tti::mf_member_type
                    <
                    boost::tti::member_type_CType<_>,
                    boost::tti::member_type_BType<AType>
                    >
                  >
                >
              ::value
            ));
            
  BOOST_TEST((boost::tti::mf_valid_member_type
                <
                boost::tti::mf_member_type
                  <
                  boost::tti::SomethingElse<_>,
                  boost::mpl::identity<AnotherType>
                  >
                >
              ::value
            ));

  BOOST_TEST((boost::tti::mf_valid_member_type
                <
                boost::tti::mf_member_type
                  <
                  boost::tti::mtfc_member_type_AnIntType,
                  boost::mpl::identity<AType>
                  >
                >
              ::value
            ));
            
  BOOST_TEST((boost::tti::mf_valid_member_type
                <
                boost::tti::mf_member_type
                  <
                  boost::tti::MFNameStruct,
                  boost::mpl::identity<AType>
                  >
                >
              ::value
            ));
            
  BOOST_TEST((boost::tti::mf_valid_member_type
                <
                boost::tti::mf_member_type
                  <
                  boost::tti::mtfc_member_type_AnIntTypeReference,
                  boost::mpl::identity<AType>
                  >
                >
              ::value
            ));
            
  BOOST_TEST((boost::tti::mf_valid_member_type
                <
                boost::tti::mf_member_type
                  <
                  boost::tti::mtfc_member_type_BType,
                  boost::mpl::identity<AType>
                  >
                >
              ::value
            ));
            
  BOOST_TEST((boost::tti::mf_valid_member_type
                <
                boost::tti::mf_member_type
                  <
                  boost::tti::MFTheInteger,
                  boost::tti::member_type_BType<AType>
                  >
                >
              ::value
            ));
            
  BOOST_TEST((boost::tti::mf_valid_member_type
                <
                boost::tti::mf_member_type
                  <
                  boost::tti::mtfc_member_type_CType,
                  boost::tti::member_type_BType<AType>
                  >
                >
              ::value
            ));
            
  BOOST_TEST((boost::tti::mf_valid_member_type
                <
                boost::tti::mf_member_type
                  <
                  boost::tti::mtfc_member_type_AnotherIntegerType,
                  boost::tti::mf_member_type
                    <
                    boost::tti::member_type_CType<_>,
                    boost::tti::member_type_BType<AType>
                    >
                  >
                >
              ::value
            ));
            
  BOOST_TEST((boost::tti::mf_valid_member_type
                <
                boost::tti::mf_member_type
                  <
                  boost::tti::MetaClSomethingElse,
                  boost::mpl::identity<AnotherType>
                  >
                >
              ::value
            ));

  return boost::report_errors();

  }
