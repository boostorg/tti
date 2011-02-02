#include "TestMFHasMemberData.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  BOOST_MPL_ASSERT((tti::mf_has_member_data
                      <
                      tti::has_member_data_AnInt,
                      boost::mpl::identity<AType>,
                      boost::mpl::identity<int> 
                      >
                  ));
                  
  BOOST_MPL_ASSERT((tti::mf_has_member_data
                      <
                      tti::has_member_data_AnInt,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<long> 
                      >
                  ));
                  
  BOOST_MPL_ASSERT((tti::mf_has_member_data
                      <
                      tti::has_member_data_aMember,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<bool> 
                      >
                  ));
                  
  BOOST_MPL_ASSERT((tti::mf_has_member_data
                      <
                      tti::CMember,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<bool> 
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_member_data
                <
                tti::has_member_data_IntBT,
                boost::mpl::identity<AType>,
                tti::member_type_BType<AType>
                >
            ));
  
  BOOST_MPL_ASSERT((tti::mf_has_member_data
                <
                tti::NestedData,
                boost::mpl::identity<AType>,
                tti::mf_member_type
                  <
                  tti::member_type_CType,
                  tti::member_type_BType<AType>
                  >
                >
            ));
  
  BOOST_MPL_ASSERT((tti::mf_has_member_data
                <
                tti::AOther,
                boost::mpl::identity<AnotherType>,
                boost::mpl::identity<AType>
                >
            ));
  
  BOOST_MPL_ASSERT((tti::mf_has_member_data
                <
                tti::has_member_data_ONestStr,
                boost::mpl::identity<AnotherType>,
                tti::member_type_AStructType<AType>
                >
            ));
  
  return 0;

  }
