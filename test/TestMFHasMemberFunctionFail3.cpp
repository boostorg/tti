#include "TestMFHasMemberFunction.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong enclosing type for nested type
  
  BOOST_MPL_ASSERT((tti::mf_has_member_function
                      <
                      tti::has_member_function_sFunction<_,_,_>,
                      boost::mpl::identity<AnotherType>,
                      tti::member_type_AnIntType<AnotherType>,
                      boost::mpl::vector
                        <
                        boost::mpl::identity<int>,
                        boost::mpl::identity<long>,
                        boost::mpl::identity<double>
                        >
                      >
                  ));
  
  return 0;

  }
