#include "test_has_type_ct.hpp"

int main()
  {
  
  // Enclosing type does not exist
  
  boost::tti::TheInteger<AType::EType,double> aVar;
  
  return 0;

  }
