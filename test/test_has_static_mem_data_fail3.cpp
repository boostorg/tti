#include "test_has_static_mem_data.hpp"

int main()
  {
  
  // Data signature has type which does not exist
  
  BOOST_TTI_HAS_STATIC_MEMBER_DATA_GEN(DSMember)<NoType,short> aVar;
  
  return 0;

  }
