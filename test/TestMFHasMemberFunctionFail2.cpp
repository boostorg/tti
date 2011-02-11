#include "test_mf_has_member_function.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong function signature
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::FunctionReturningInt<_,_>,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<short>
                      >
                  ));
  
  return 0;

  }
