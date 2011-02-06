#include "TestMFHasMemberData.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong data signature for AnInt
  
  BOOST_MPL_ASSERT((tti::mf_has_member_data
                      <
                      tti::has_member_data_AnInt<_,_>,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<double> 
                      >
                  ));
  
  return 0;

  }
