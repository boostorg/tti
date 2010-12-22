#include "TestMFHasType.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // NoOtherType does not exist at all
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::has_type_NoOtherType,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  return 0;

  }
