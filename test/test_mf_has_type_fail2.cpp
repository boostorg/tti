#include "test_mf_has_type.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      boost::tti::has_type_AnIntType<_>,
                      boost::mpl::identity<AnotherType>
                      >
                  ));
  
  return 0;

  }
