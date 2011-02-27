#include "test_has_static_mem_fun.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong function signature for SIntFunction
  
  BOOST_MPL_ASSERT((boost::tti::HaveTheSIntFunction<AType,int,boost::mpl::vector<float,double> >));
  
  return 0;

  }
