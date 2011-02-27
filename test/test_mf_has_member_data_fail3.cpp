#include "test_mf_has_mem_data.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_member_data
                      <
                      boost::tti::has_member_data_aMember<_,_>,
                      boost::mpl::identity<AType>,
                      boost::mpl::identity<bool> 
                      >
                  ));
  
  return 0;

  }
