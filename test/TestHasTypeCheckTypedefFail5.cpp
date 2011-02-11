#include "test_has_type_check_typedef.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong typedef type
  
  BOOST_MPL_ASSERT((tti::has_type_AnotherIntegerType<AType::BType::CType,long>));
  
  return 0;

  }
