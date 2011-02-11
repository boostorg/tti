#include "test_has_type_check_typedef.hpp"

int main()
  {
  
  // Enclosing type does not exist
  
  tti::TheInteger<AType::EType,double> aVar;
  
  return 0;

  }
