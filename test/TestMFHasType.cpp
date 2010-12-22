#include "TestMFHasType.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::has_type_AnIntType,
                boost::mpl::identity<AType>
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_has_type
                <
                tti::NameStruct,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::has_type_AnIntTypeReference,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::has_type_BType,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::TheInteger,
                tti::member_type_BType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::has_type_CType,
                tti::member_type_BType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::has_type_AnotherIntegerType,
                tti::mf_member_type
                  <
                  tti::member_type_CType,
                  tti::member_type_BType<AType>
                  >
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::SomethingElse,
                boost::mpl::identity<AnotherType>
                >
              ::value
            ));
            
  return boost::report_errors();

  }
