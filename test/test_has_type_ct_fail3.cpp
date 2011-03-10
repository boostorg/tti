#include "test_has_type_ct.hpp"
#include <boost/tti/gen/trait_gen.hpp>

int main()
  {
  
  // Enclosing type does not exist
  
  BOOST_TTI_TRAIT_GEN(TheInteger)<AType::EType,double> aVar;
  
  return 0;

  }
