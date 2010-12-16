#include "TestMFHasMemberData.hpp"
#include <boost/mpl/assert.hpp>
#include <boost/mpl/identity.hpp>

int main()
  {
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((tti::mf_has_member_data<tti::has_member_aMember,boost::mpl::identity<AType>,boost::mpl::identity<bool> >));
  
  return 0;

  }
