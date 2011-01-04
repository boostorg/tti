#include "TestMFHasTemplate.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Not all 'typename' parameters
  
  BOOST_MPL_ASSERT((tti::mf_has_template
                      <
                      tti::AMT,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  return 0;
  
  }
