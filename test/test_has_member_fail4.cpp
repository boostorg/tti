#include "test_has_member.hpp"

int main()
  {
  
  // Data signature has type which does not exist
  
  boost::tti::has_member_aMember<AType::NTHType AnotherType::*> aVar;
  
  return 0;

  }
