#include "test_mf_has_type_check_typedef.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong typedef type
  
  BOOST_MPL_ASSERT((tti::mf_has_type
                      <
                      tti::TheInteger<_,_>,
                      tti::member_type_BType<AType>,
                      boost::mpl::identity<long>
                      >
                  ));
  
  return 0;

  }
