#include "test_has_member_data.hpp"

int main()
  {
  
  // Data signature has type which does not exist
  
  tti::has_member_data_aMember<AnotherType,AType::NTHType> aVar;
  
  return 0;

  }
