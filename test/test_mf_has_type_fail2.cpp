#include "test_mf_has_type.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      BOOST_TTI_HAS_TYPE_GEN(AnIntType)<_>,
                      boost::mpl::identity<AnotherType>
                      >
                  ));
  
  return 0;

  }
