#include "TestMFHasTypeCheckTypedef.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::has_type_BType,
                      boost::mpl::identity<AnotherType>,
                      tti::member_type_BType<AType>
                      >
                  ));
  
  return 0;

  }
