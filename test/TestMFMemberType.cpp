#include "TestMFMemberType.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  BOOST_TEST((tti::mf_valid_member_type
                <
                tti::mf_member_type
                  <
                  tti::member_type_AnIntType<_>,
                  boost::mpl::identity<AType>
                  >
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_valid_member_type
                <
                tti::mf_member_type
                  <
                  tti::NameStruct<_>,
                  boost::mpl::identity<AType>
                  >
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_valid_member_type
                <
                tti::mf_member_type
                  <
                  tti::member_type_AnIntTypeReference<_>,
                  boost::mpl::identity<AType>
                  >
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_valid_member_type
                <
                tti::mf_member_type
                  <
                  tti::member_type_BType<_>,
                  boost::mpl::identity<AType>
                  >
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_valid_member_type
                <
                tti::mf_member_type
                  <
                  tti::TheInteger<_>,
                  tti::member_type_BType<AType>
                  >
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_valid_member_type
                <
                tti::mf_member_type
                  <
                  tti::member_type_CType<_>,
                  tti::member_type_BType<AType>
                  >
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_valid_member_type
                <
                tti::mf_member_type
                  <
                  tti::member_type_AnotherIntegerType<_>,
                  tti::mf_member_type
                    <
                    tti::member_type_CType<_>,
                    tti::member_type_BType<AType>
                    >
                  >
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_valid_member_type
                <
                tti::mf_member_type
                  <
                  tti::SomethingElse<_>,
                  boost::mpl::identity<AnotherType>
                  >
                >
              ::value
            ));
  
  return boost::report_errors();

  }
