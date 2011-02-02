#include "TestMFHasStaticFunction.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((tti::mf_has_static_member_function
                      <
                      tti::HaveTheSIntFunction,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<int>,
                      boost::mpl::vector
                        <
                        boost::mpl::identity<long>,
                        boost::mpl::identity<double>
                        >
                      >
                  ));
  
  return 0;

  }
