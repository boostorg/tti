#include "test_has_type_check_typedef.hpp"

int main()
  {
  
  // Typedef type does not exist ( BType is a nested type )
  
  tti::has_type_BType<AType,BType> aVar;
  
  return 0;

  }
