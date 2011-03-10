#include "test_has_static_member.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong function signature for SIntFunction
  
  BOOST_MPL_ASSERT((BOOST_TTI_TRAIT_GEN(HaveTheSIntFunction)<AType,int (float,double)>));
  
  return 0;

  }
