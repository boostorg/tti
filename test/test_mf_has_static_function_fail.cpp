#include "test_mf_has_static_function.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // SomeStaticFunction does not exist at all
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_static_member_function
                      <
                      boost::tti::Pickedname<_,_,_>,
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
