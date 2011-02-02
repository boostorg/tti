#include "TestHasStaticMemberFunction.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong function signature for SIntFunction
  
  BOOST_MPL_ASSERT((tti::HaveTheSIntFunction<AType,int,boost::mpl::vector<float,double> >));
  
  return 0;

  }
