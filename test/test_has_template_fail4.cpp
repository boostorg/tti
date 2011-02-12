#include "test_has_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Not all 'typename' parameters
  
  BOOST_MPL_ASSERT((boost::tti::HaveAnotherMT<AType>));
  
  return 0;

  }
