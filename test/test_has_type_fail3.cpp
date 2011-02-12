#include "test_has_type.hpp"

int main()
  {
  
  // Enclosing type does not exist
  
  boost::tti::TheInteger<AType::EType> aVar;
  
  return 0;

  }
