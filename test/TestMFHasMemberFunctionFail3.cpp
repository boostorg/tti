#include "TestMFHasMemberFunction.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong enclosing type for nested type
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::has_member_sFunction,
                      boost::mpl::identity<AnotherType>,
                      tti::member_type_AnIntType<AnotherType>,
                      boost::mpl::identity<int>,
                      boost::mpl::identity<long>,
                      boost::mpl::identity<double>
                      >
                  ));
  
  return 0;

  }
