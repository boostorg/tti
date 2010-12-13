#include "TestHasStaticMember.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong function signature for SIntFunction
  
  BOOST_MPL_ASSERT((tti::HaveTheSIntFunction<AType,int (float,double)>));
  
  return 0;

  }
