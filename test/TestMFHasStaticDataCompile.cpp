#include "TestMFHasStaticData.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // You can always instantiate without compiler errors
  
  tti::mf_has_static_data
    <
    tti::has_static_member_SomeStaticData<_,_>,
    boost::mpl::identity<AnotherType>,
    boost::mpl::identity<double>
    > aVar;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((tti::mf_has_static_data
                      <
                      tti::has_static_member_DSMember<_,_>,
                      boost::mpl::identity<AType>,
                      boost::mpl::identity<short>
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_static_data
                      <
                      tti::mtfc_has_static_member_DSMember,
                      boost::mpl::identity<AType>,
                      boost::mpl::identity<short>
                      >
                  ));
  
  return 0;

  }
