#include "test_has_mem_data.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong data signature for aMember
  
  BOOST_MPL_ASSERT(( BOOST_TTI_HAS_MEMBER_DATA_GEN(aMember)<AnotherType,int> ));
  
  return 0;

  }
