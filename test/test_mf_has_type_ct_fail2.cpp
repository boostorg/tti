#include "test_mf_has_type_ct.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_type
                      <
                      BOOST_TTI_HAS_TYPE_GEN(BType)<_,_>,
                      boost::mpl::identity<AnotherType>,
                      BOOST_TTI_MEMBER_TYPE_GEN(BType)<AType>
                      >
                  ));
  
  return 0;

  }
