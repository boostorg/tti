#include "TestMFHasMemberData.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // someDataMember does not exist at all
  
  BOOST_MPL_ASSERT((tti::mf_has_member_data
                      <
                      tti::has_member_data_someDataMember<_,_>,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<short> 
                      >
                  ));
  
  return 0;

  }
