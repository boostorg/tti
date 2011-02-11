#include "test_mf_has_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((tti::mf_has_template
                      <
                      tti::HaveMStr<_>,
                      tti::member_type_AStructType<AnotherType>
                      >
                  ));
  
  return 0;
  
  }
