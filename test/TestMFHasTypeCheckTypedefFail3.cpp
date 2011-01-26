#include "TestMFHasTypeCheckTypedef.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong typedef type
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::TheInteger,
                      tti::member_type_BType<AType>,
                      boost::mpl::identity<long>
                      >
                  ));
  
  return 0;

  }
