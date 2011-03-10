#include "test_mf_has_static_data.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong member type
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_static_member_data
                      <
                      BOOST_TTI_HAS_STATIC_MEMBER_DATA_GEN(DSMember)<_,_>,
                      boost::mpl::identity<AType>,
                      boost::mpl::identity<int>
                      >
                  ));
  
  return 0;

  }
