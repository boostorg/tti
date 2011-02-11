#include "test_mf_has_static_function.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong function parameter type
  
  BOOST_MPL_ASSERT((tti::mf_has_static_member_function
                      <
                      tti::has_static_member_function_TSFunction<_,_,_>,
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
