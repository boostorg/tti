#include "test_mf_has_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template
                      <
                      BOOST_TTI_TRAIT_GEN(HaveMStr)<_>,
                      BOOST_TTI_MEMBER_TYPE_GEN(AStructType)<AnotherType>
                      >
                  ));
  
  return 0;
  
  }
