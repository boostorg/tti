#include "test_has_type.hpp"

int main()
  {
  
  // Enclosing type does not exist
  
  BOOST_TTI_TRAIT_GEN(TheInteger)<AType::EType> aVar;
  
  return 0;

  }
