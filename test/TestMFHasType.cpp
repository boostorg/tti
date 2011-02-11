#include "test_mf_has_type.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::has_type_AnIntType<_>,
                boost::mpl::identity<AType>
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_has_type
                <
                tti::NameStruct<_>,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::has_type_AnIntTypeReference<_>,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::has_type_BType<_>,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::TheInteger<_>,
                tti::member_type_BType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::has_type_CType<_>,
                tti::member_type_BType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::has_type_AnotherIntegerType<_>,
                tti::mf_member_type
                  <
                  tti::member_type_CType<_>,
                  tti::member_type_BType<AType>
                  >
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::SomethingElse<_>,
                boost::mpl::identity<AnotherType>
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_has_type
                <
                tti::mtfc_has_type_AnIntType,
                boost::mpl::identity<AType>
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_has_type
                <
                tti::MetaFNameStruct,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::mtfc_has_type_AnIntTypeReference,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::mtfc_has_type_BType,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::MClassTheInteger,
                tti::member_type_BType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::mtfc_has_type_CType,
                tti::member_type_BType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::mtfc_has_type_AnotherIntegerType,
                tti::mf_member_type
                  <
                  tti::mtfc_member_type_CType,
                  tti::member_type_BType<AType>
                  >
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::MTFCSomethingElse,
                boost::mpl::identity<AnotherType>
                >
              ::value
            ));
            
  return boost::report_errors();

  }
