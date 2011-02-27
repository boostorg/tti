#include "test_mf_has_mem_data.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  BOOST_TEST((boost::tti::mf_has_member_data
                <
                boost::tti::has_member_data_AnInt<_,_>,
                boost::mpl::identity<AType>,
                boost::mpl::identity<int> 
                >
              ::value
            ));
            
  BOOST_TEST((boost::tti::mf_has_member_data
                <
                boost::tti::has_member_data_AnInt<_,_>,
                boost::mpl::identity<AnotherType>,
                boost::mpl::identity<long> 
                >
              ::value
            ));
            
  BOOST_TEST((boost::tti::mf_has_member_data
                <
                boost::tti::has_member_data_aMember<_,_>,
                boost::mpl::identity<AnotherType>,
                boost::mpl::identity<bool> 
                >
              ::value
            ));
            
  BOOST_TEST((boost::tti::mf_has_member_data
                <
                boost::tti::CMember<_,_>,
                boost::mpl::identity<AnotherType>,
                boost::mpl::identity<bool> 
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_member_data
                <
                boost::tti::has_member_data_IntBT<_,_>,
                boost::mpl::identity<AType>,
                boost::tti::member_type_BType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_member_data
                <
                boost::tti::NestedData<_,_>,
                boost::mpl::identity<AType>,
                boost::tti::mf_member_type
                  <
                  boost::tti::member_type_CType<_>,
                  boost::tti::member_type_BType<AType>
                  >
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_member_data
                <
                boost::tti::AOther<_,_>,
                boost::mpl::identity<AnotherType>,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_member_data
                <
                boost::tti::has_member_data_ONestStr<_,_>,
                boost::mpl::identity<AnotherType>,
                boost::tti::member_type_AStructType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_member_data
                <
                boost::tti::mtfc_has_member_data_AnInt,
                boost::mpl::identity<AType>,
                boost::mpl::identity<int> 
                >
              ::value
            ));
            
  BOOST_TEST((boost::tti::mf_has_member_data
                <
                boost::tti::mtfc_has_member_data_AnInt,
                boost::mpl::identity<AnotherType>,
                boost::mpl::identity<long> 
                >
              ::value
            ));
            
  BOOST_TEST((boost::tti::mf_has_member_data
                <
                boost::tti::mtfc_has_member_data_aMember,
                boost::mpl::identity<AnotherType>,
                boost::mpl::identity<bool> 
                >
              ::value
            ));
            
  BOOST_TEST((boost::tti::mf_has_member_data
                <
                boost::tti::MFCMember,
                boost::mpl::identity<AnotherType>,
                boost::mpl::identity<bool> 
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_member_data
                <
                boost::tti::mtfc_has_member_data_IntBT,
                boost::mpl::identity<AType>,
                boost::tti::member_type_BType<AType>
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_member_data
                <
                boost::tti::MFNestedData,
                boost::mpl::identity<AType>,
                boost::tti::mf_member_type
                  <
                  boost::tti::mtfc_member_type_CType,
                  boost::tti::member_type_BType<AType>
                  >
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_member_data
                <
                boost::tti::MFAOther,
                boost::mpl::identity<AnotherType>,
                boost::mpl::identity<AType>
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_member_data
                <
                boost::tti::mtfc_has_member_data_ONestStr,
                boost::mpl::identity<AnotherType>,
                boost::tti::member_type_AStructType<AType>
                >
              ::value
            ));
  
  return boost::report_errors();

  }
