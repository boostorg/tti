#include "TestMFHasTemplate.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((tti::mf_has_template
                      <
                      tti::HaveMStr,
                      tti::member_type_AStructType<AnotherType>
                      >
                  ));
  
  return 0;
  
  }
