#include "test_has_type_ct.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong typedef type
  
  BOOST_MPL_ASSERT((boost::tti::has_type_AnotherIntegerType<AType::BType::CType,long>));
  
  return 0;

  }
