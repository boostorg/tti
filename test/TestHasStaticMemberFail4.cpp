#include "test_has_static_member.hpp"

int main()
  {
  
  // Data signature has type which does not exist
  
  tti::has_static_member_DSMember<NoType,short> aVar;
  
  return 0;

  }
