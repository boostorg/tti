#include "TestHasStaticMemberFunction.hpp"

int main()
  {
  
  // Function signature has type which does not exist
  
  tti::has_static_member_TSFunction<AnotherType,AType::AClassType,boost::mpl::vector<AType::AnIntType,double> > aVar;
  
  return 0;

  }
