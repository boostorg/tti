#include "TestMFMemberType.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST((tti::mf_member_type
                <
                tti::member_type_AnIntType,
                boost::mpl::identity<AType>
                >
              ::valid
            ));
            
  BOOST_TEST((tti::mf_member_type
                <
                tti::NameStruct,
                boost::mpl::identity<AType>
                >
              ::valid
            ));
            
  BOOST_TEST((tti::mf_member_type
                <
                tti::member_type_AnIntTypeReference,
                boost::mpl::identity<AType>
                >
              ::valid
            ));
            
  BOOST_TEST((tti::mf_member_type
                <
                tti::member_type_BType,
                boost::mpl::identity<AType>
                >
              ::valid
            ));
            
  BOOST_TEST((tti::mf_member_type
                <
                tti::TheInteger,
                tti::member_type_BType<AType>
                >
              ::valid
            ));
            
  BOOST_TEST((tti::mf_member_type
                <
                tti::member_type_CType,
                tti::member_type_BType<AType>
                >
              ::valid
            ));
            
  BOOST_TEST((tti::mf_member_type
                <
                tti::member_type_AnotherIntegerType,
                tti::mf_member_type
                  <
                  tti::member_type_CType,
                  tti::member_type_BType<AType>
                  >
                >
              ::valid
            ));
            
  BOOST_TEST((tti::mf_member_type
                <
                tti::SomethingElse,
                boost::mpl::identity<AnotherType>
                >
              ::valid
            ));
  
  return boost::report_errors();

  }
