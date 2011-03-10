#include "test_mf_has_template_cp.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong template types
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template_check_params
                      <
                      BOOST_TTI_TRAIT_GEN(WrongParametersForMP)<_>,
                      boost::mpl::identity<AnotherType>
                      >
                  ));
  
  return 0;
  
  }
