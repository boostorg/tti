#include "TestMFHasStaticFunction.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong function parameter type
  
  BOOST_MPL_ASSERT((tti::mf_has_static_member_function
                      <
                      tti::has_static_member_function_TSFunction,
                      boost::mpl::identity<AnotherType>,
                      tti::member_type_AStructType<AType>,
                      boost::mpl::vector
                        <
                        tti::NameIntType<AnotherType>,
                        boost::mpl::identity<double>
                        >
                      >
                  ));
  
  return 0;

  }
