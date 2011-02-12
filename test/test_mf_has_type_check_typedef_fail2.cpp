#include "test_mf_has_type_check_typedef.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      boost::tti::has_type_BType<_,_>,
                      boost::mpl::identity<AnotherType>,
                      boost::tti::member_type_BType<AType>
                      >
                  ));
  
  return 0;

  }
