#include "TestMFHasTemplate.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Not all 'typename' parameters
  
  BOOST_MPL_ASSERT((tti::mf_has_template
                      <
                      tti::AMT<_>,
                      boost::mpl::identity<AType>
                      >
                  ));
  
  return 0;
  
  }
