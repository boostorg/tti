#include "test_mf_has_type_check_typedef.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::has_type_BType<_,_>,
                      boost::mpl::identity<AnotherType>,
                      tti::member_type_BType<AType>
                      >
                  ));
  
  return 0;

  }
