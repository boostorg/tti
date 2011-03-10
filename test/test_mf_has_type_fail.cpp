#include "test_mf_has_type.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // NoOtherType does not exist at all
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      BOOST_TTI_HAS_TYPE_GEN(NoOtherType)<_>,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  return 0;

  }
