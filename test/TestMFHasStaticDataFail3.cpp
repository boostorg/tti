#include "TestMFHasStaticData.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong member type
  
  BOOST_MPL_ASSERT((tti::mf_has_static_data
                      <
                      tti::has_static_member_DSMember,
                      boost::mpl::identity<AType>,
                      boost::mpl::identity<int>
                      >
                  ));
  
  return 0;

  }
