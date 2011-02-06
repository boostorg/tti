#include "TestMFHasStaticData.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // SomeStaticData does not exist at all
  
  BOOST_MPL_ASSERT((tti::mf_has_static_data
                      <
                      tti::has_static_member_SomeStaticData<_,_>,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<int>
                      >
                  ));
  
  return 0;

  }
