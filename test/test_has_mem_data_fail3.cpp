#include "test_has_mem_data.hpp"

int main()
  {
  
  // Data signature has type which does not exist
  
  BOOST_TTI_HAS_MEMBER_DATA_GEN(aMember)<AnotherType,AType::NTHType> aVar;
  
  return 0;

  }
