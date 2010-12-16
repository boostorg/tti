#include "TestMFHasMemberData.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  BOOST_MPL_ASSERT((tti::mf_has_member_data<tti::has_member_AnInt,boost::mpl::identity<AType>,boost::mpl::identity<int> >));
  BOOST_MPL_ASSERT((tti::mf_has_member_data<tti::has_member_AnInt,boost::mpl::identity<AnotherType>,boost::mpl::identity<long> >));
  BOOST_MPL_ASSERT((tti::mf_has_member_data<tti::has_member_aMember,boost::mpl::identity<AnotherType>,boost::mpl::identity<bool> >));
  BOOST_MPL_ASSERT((tti::mf_has_member_data<tti::CMember,boost::mpl::identity<AnotherType>,boost::mpl::identity<bool> >));
  
  return 0;

  }
