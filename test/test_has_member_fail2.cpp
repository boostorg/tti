#include "test_has_member.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong data signature for aMember
  
  BOOST_MPL_ASSERT(( tti::has_member_aMember<int AnotherType::*> ));
  
  return 0;

  }
