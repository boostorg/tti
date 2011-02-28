#include "test_mf_has_mem_data.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_member_data
                      <
                      boost::tti::has_member_data_AnInt<_,_>,
                      boost::mpl::identity<AType>,
                      boost::mpl::identity<int> 
                      >
                  ));
                  
  BOOST_MPL_ASSERT((boost::tti::mf_has_member_data
                      <
                      boost::tti::has_member_data_AnInt<_,_>,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<long> 
                      >
                  ));
                  
  BOOST_MPL_ASSERT((boost::tti::mf_has_member_data
                      <
                      boost::tti::has_member_data_aMember<_,_>,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<bool> 
                      >
                  ));
                  
  BOOST_MPL_ASSERT((boost::tti::mf_has_member_data
                      <
                      boost::tti::CMember<_,_>,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<bool> 
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_member_data
                      <
                      boost::tti::has_member_data_IntBT<_,_>,
                      boost::mpl::identity<AType>,
                      boost::tti::member_type_BType<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_member_data
                      <
                      boost::tti::NestedData<_,_>,
                      boost::mpl::identity<AType>,
                      boost::tti::mf_member_type
                        <
                        boost::tti::member_type_CType<_>,
                        boost::tti::member_type_BType<AType>
                        >
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_member_data
                      <
                      boost::tti::AOther<_,_>,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_member_data
                      <
                      boost::tti::has_member_data_ONestStr<_,_>,
                      boost::mpl::identity<AnotherType>,
                      boost::tti::member_type_AStructType<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_member_data
                      <
                      boost::tti::mtfc_has_member_data_AnInt,
                      boost::mpl::identity<AType>,
                      boost::mpl::identity<int> 
                      >
                  ));
            
  BOOST_MPL_ASSERT((boost::tti::mf_has_member_data
                      <
                      boost::tti::mtfc_has_member_data_AnInt,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<long> 
                      >
                  ));
            
  BOOST_MPL_ASSERT((boost::tti::mf_has_member_data
                      <
                      boost::tti::mtfc_has_member_data_aMember,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<bool> 
                      >
                  ));
            
  BOOST_MPL_ASSERT((boost::tti::mf_has_member_data
                      <
                      boost::tti::MFCMember,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<bool> 
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_member_data
                      <
                      boost::tti::mtfc_has_member_data_IntBT,
                      boost::mpl::identity<AType>,
                      boost::tti::member_type_BType<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_member_data
                      <
                      boost::tti::MFNestedData,
                      boost::mpl::identity<AType>,
                      boost::tti::mf_member_type
                        <
                        boost::tti::mtfc_member_type_CType,
                        boost::tti::member_type_BType<AType>
                        >
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_member_data
                      <
                      boost::tti::MFAOther,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_member_data
                      <
                      boost::tti::mtfc_has_member_data_ONestStr,
                      boost::mpl::identity<AnotherType>,
                      boost::tti::member_type_AStructType<AType>
                      >
                  ));
  
  return 0;

  }
