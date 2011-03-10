#include "test_has_member.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong function signature for sFunction
  
  BOOST_MPL_ASSERT(( BOOST_TTI_HAS_COMP_MEMBER_FUNCTION_GEN(sFunction)<AType::AnIntType (AnotherType::*)(short,long,double)> ));
  
  return 0;

  }
