#include "TestHasTypeCheckTypedef.hpp"

int main()
  {
  
  // Typedef type does not exist ( BType is a nested type )
  
  tti::has_type_check_typedef_BType<AType,BType> aVar;
  
  return 0;

  }
