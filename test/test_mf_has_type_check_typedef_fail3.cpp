#include "test_mf_has_type_check_typedef.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong typedef type
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      boost::tti::TheInteger<_,_>,
                      boost::tti::member_type_BType<AType>,
                      boost::mpl::identity<long>
                      >
                  ));
  
  return 0;

  }
