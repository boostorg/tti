#include "TestMFHasTypeCheckTypedef.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST((tti::mf_has_type_check_typedef
                <
                tti::has_type_check_typedef_AnIntType,
                boost::mpl::identity<AType>,
                boost::mpl::identity<int>
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_has_type_check_typedef
                <
                tti::NameStruct,
                boost::mpl::identity<AType>,
                tti::member_type_AStructType<AType>
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_has_type_check_typedef
                <
                tti::has_type_check_typedef_AnIntTypeReference,
                boost::mpl::identity<AType>,
                boost::mpl::identity<int &>
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_has_type_check_typedef
                <
                tti::has_type_check_typedef_BType,
                boost::mpl::identity<AType>,
                tti::member_type_BType<AType>
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_has_type_check_typedef
                <
                tti::TheInteger,
                tti::member_type_BType<AType>,
                boost::mpl::identity<int>
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_has_type_check_typedef
                <
                tti::has_type_check_typedef_CType,
                tti::member_type_BType<AType>,
                tti::mf_member_type
                  <
                  tti::member_type_CType,
                  tti::member_type_BType<AType>
                  >
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_has_type_check_typedef
                <
                tti::has_type_check_typedef_AnotherIntegerType,
                tti::mf_member_type
                  <
                  tti::member_type_CType,
                  tti::member_type_BType<AType>
                  >,
                boost::mpl::identity<int>
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_has_type_check_typedef
                <
                tti::SomethingElse,
                boost::mpl::identity<AnotherType>,
                tti::member_type_AnIntType<AType>
                >
              ::value
            ));
            
  BOOST_TEST((!tti::mf_has_type_check_typedef
                <
                tti::has_type_check_typedef_NoOtherType,
                boost::mpl::identity<AnotherType>,
                boost::mpl::identity<double>
                >
              ::value
            ));
  
  return boost::report_errors();

  }
