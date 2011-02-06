#include "TestMFHasMemberFunction.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // someFunctionMember does not exist at all
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::has_member_function_someFunctionMember<_,_,_>,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<short>,
                      boost::mpl::vector
                        <
                        boost::mpl::identity<double>,
                        boost::mpl::identity<int>,
                        boost::mpl::identity<long>
                        >
                      >
                  ));
  
  return 0;

  }
