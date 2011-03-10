#include "test_mf_has_template_cp.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template_check_params
                      <
                      BOOST_TTI_HAS_TEMPLATE_CHECK_PARAMS_GEN(CTManyParameters)<_>,
                      boost::tti::mf_member_type
                        <
                        BOOST_TTI_MEMBER_TYPE_GEN(CType)<_>,
                        boost::mpl::identity<AType>
                        >
                      >
                  ));
  
  return 0;
  
  }
