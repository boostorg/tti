#include "test_has_type_ct.hpp"

int main()
  {
  
  // Typedef type does not exist ( BType is a nested type )
  
  BOOST_TTI_HAS_TYPE_GEN(BType)<AType,BType> aVar;
  
  return 0;

  }
