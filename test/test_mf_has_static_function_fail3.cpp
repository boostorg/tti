#include "test_mf_has_static_function.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong function parameter type
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_static_member_function
                      <
                      boost::tti::has_static_member_function_TSFunction<_,_,_>,
                      boost::mpl::identity<AnotherType>,
                      boost::tti::member_type_AStructType<AType>,
                      boost::mpl::vector
                        <
                        boost::tti::NameIntType<AnotherType>,
                        boost::mpl::identity<double>
                        >
                      >
                  ));
  
  return 0;

  }
