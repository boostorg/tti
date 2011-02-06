#include "TestMFHasMemberData.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  BOOST_TEST((tti::mf_has_member_data
                <
                tti::has_member_data_AnInt<_,_>,
                boost::mpl::identity<AType>,
                boost::mpl::identity<int> 
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_has_member_data
                <
                tti::has_member_data_AnInt<_,_>,
                boost::mpl::identity<AnotherType>,
                boost::mpl::identity<long> 
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_has_member_data
                <
                tti::has_member_data_aMember<_,_>,
                boost::mpl::identity<AnotherType>,
                boost::mpl::identity<bool> 
                >
              ::value
            ));
            
  BOOST_TEST((tti::mf_has_member_data
                <
                tti::CMember<_,_>,
                boost::mpl::identity<AnotherType>,
                boost::mpl::identity<bool> 
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_member_data
                <
                tti::has_member_data_IntBT<_,_>,
                boost::mpl::identity<AType>,
                tti::member_type_BType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_member_data
                <
                tti::NestedData<_,_>,
                boost::mpl::identity<AType>,
                tti::mf_member_type
                  <
                  tti::member_type_CType<_>,
                  tti::member_type_BType<AType>
                  >
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_member_data
                <
                tti::AOther<_,_>,
                boost::mpl::identity<AnotherType>,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_member_data
                <
                tti::has_member_data_ONestStr<_,_>,
                boost::mpl::identity<AnotherType>,
                tti::member_type_AStructType<AType>
                >
              ::value
            ));
  
  return boost::report_errors();

  }
