#include "TestMFHasStaticFunction.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // SomeStaticFunction does not exist at all
  
  BOOST_MPL_ASSERT((tti::mf_has_static_member_function
                      <
                      tti::Pickedname,
                      boost::mpl::identity<AType>,
                      boost::mpl::identity<short>,
                      boost::mpl::vector
                        <
                        boost::mpl::identity<int>,
                        boost::mpl::identity<long>
                        >
                      >
                  ));
  
  return 0;

  }
