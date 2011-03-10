#include "test_has_template_cp.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong template parameters
  
  BOOST_MPL_ASSERT((BOOST_TTI_TRAIT_GEN(WrongParameters2ForMP)<AnotherType>));
  
  return 0;

  }
