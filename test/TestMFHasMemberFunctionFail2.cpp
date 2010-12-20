#include "TestMFHasMemberFunction.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong function signature
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::FunctionReturningInt,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<short>
                      >
                  ));
  
  return 0;

  }
