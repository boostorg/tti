#include "TestMFHasType.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::has_type_AnIntType,
                      boost::mpl::identity<AnotherType>
                      >
                  ));
  
  return 0;

  }
