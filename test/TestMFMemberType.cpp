#include "TestMFMemberType.hpp"
#include <boost/detail/lightweight_test.hpp>
#include <boost/type_traits/is_same.hpp>

int main()
  {
  
  BOOST_TEST((boost::is_same
                <
                tti::mf_member_type
                  <
                  tti::member_type_AnIntType,
                  boost::mpl::identity<AType>
                  >
                ::type,
                AType::AnIntType
                >
              ::value
            ));
            
  BOOST_TEST((boost::is_same
                <
                tti::mf_member_type
                  <
                  tti::NameStruct,
                  boost::mpl::identity<AType>
                  >
                ::type,
                AType::AStructType
                >
              ::value
            ));
            
  BOOST_TEST((boost::is_same
                <
                tti::mf_member_type
                  <
                  tti::member_type_AnIntTypeReference,
                  boost::mpl::identity<AType>
                  >
                ::type,
                AType::AnIntTypeReference
                >
              ::value
            ));
            
  BOOST_TEST((boost::is_same
                <
                tti::mf_member_type
                  <
                  tti::member_type_BType,
                  boost::mpl::identity<AType>
                  >
                ::type,
                AType::BType
                >
              ::value
            ));
            
  BOOST_TEST((boost::is_same
                <
                tti::mf_member_type
                  <
                  tti::TheInteger,
                  tti::member_type_BType<AType>
                  >
                ::type,
                AType::BType::AnIntegerType
                >
              ::value
            ));
            
  BOOST_TEST((boost::is_same
                <
                tti::mf_member_type
                  <
                  tti::member_type_CType,
                  tti::member_type_BType<AType>
                  >
                ::type,
                AType::BType::CType
                >
              ::value
            ));
            
  BOOST_TEST((boost::is_same
                <
                tti::mf_member_type
                  <
                  tti::member_type_AnotherIntegerType,
                  tti::mf_member_type
                    <
                    tti::member_type_CType,
                    tti::member_type_BType<AType>
                    >
                  >
                ::type,
                AType::BType::CType::AnotherIntegerType
                >
              ::value
            ));
            
  BOOST_TEST((boost::is_same
                <
                tti::mf_member_type
                  <
                  tti::SomethingElse,
                  boost::mpl::identity<AnotherType>
                  >
                ::type,
                AnotherType::someOtherType
                >
              ::value
            ));
  
  return boost::report_errors();

  }
