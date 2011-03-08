#include "test_has_static_mem_data.hpp"

int main()
  {
  
  // Data signature has type which does not exist
  
  boost::tti::has_static_member_data_DSMember<NoType,short> aVar;
  
  return 0;

  }
