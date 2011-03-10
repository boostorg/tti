#include "test_has_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Not all 'typename' parameters
  
  BOOST_MPL_ASSERT((BOOST_TTI_TRAIT_GEN(HaveAnotherMT)<AType>));
  
  return 0;

  }
