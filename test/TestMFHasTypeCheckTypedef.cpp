#include "TestMFHasTypeCheckTypedef.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST((tti::mf_has_type
                <
                tti::has_type_AnIntType,
                boost::mpl::identity<AType>,
                boost::mpl::identity<int>
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_has_type
                <
                tti::NameStruct,
                boost::mpl::identity<AType>,
                tti::member_type_AStructType<AType>
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_has_type
                <
                tti::has_type_AnIntTypeReference,
                boost::mpl::identity<AType>,
                boost::mpl::identity<int &>
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_has_type
                <
                tti::has_type_BType,
                boost::mpl::identity<AType>,
                tti::member_type_BType<AType>
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_has_type
                <
                tti::TheInteger,
                tti::member_type_BType<AType>,
                boost::mpl::identity<int>
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_has_type
                <
                tti::has_type_CType,
                tti::member_type_BType<AType>,
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
                tti::has_type_AnotherIntegerType,
                tti::mf_member_type
                  <
                  tti::member_type_CType,
                  tti::member_type_BType<AType>
                  >,
                boost::mpl::identity<int>
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_has_type
                <
                tti::SomethingElse,
                boost::mpl::identity<AnotherType>,
                tti::member_type_AnIntType<AType>
                >
              ::value
            ));
            
  BOOST_TEST((!tti::mf_has_type
                <
                tti::has_type_NoOtherType,
                boost::mpl::identity<AnotherType>,
                boost::mpl::identity<double>
                >
              ::value
            ));
  
  return boost::report_errors();

  }
