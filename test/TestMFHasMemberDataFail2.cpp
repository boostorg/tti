#include "TestMFHasMemberData.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong data signature for AnInt
  
  BOOST_MPL_ASSERT((tti::mf_has_member_data
                      <
                      tti::has_member_AnInt,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<double> 
                      >
                  ));
  
  return 0;

  }
