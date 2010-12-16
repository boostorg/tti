#include "TestMFHasMemberData.hpp"
#include <boost/detail/lightweight_test.hpp>
#include <boost/mpl/identity.hpp>

int main()
  {
  
  BOOST_TEST((tti::mf_has_member_data<tti::has_member_AnInt,boost::mpl::identity<AType>,boost::mpl::identity<int> >::value));
  BOOST_TEST((tti::mf_has_member_data<tti::has_member_AnInt,boost::mpl::identity<AnotherType>,boost::mpl::identity<long> >::value));
  BOOST_TEST((tti::mf_has_member_data<tti::has_member_aMember,boost::mpl::identity<AnotherType>,boost::mpl::identity<bool> >::value));
  BOOST_TEST((tti::mf_has_member_data<tti::CMember,boost::mpl::identity<AnotherType>,boost::mpl::identity<bool> >::value));
  
  return boost::report_errors();

  }
