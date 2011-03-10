#include "test_mf_has_template_cp.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Template does not exist
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template_check_params
                      <
                      BOOST_TTI_HAS_TEMPLATE_CHECK_PARAMS_GEN(TemplateNotExist)<_>,
                      boost::tti::mf_member_type
                        <
                        BOOST_TTI_MEMBER_TYPE_GEN(CType)<_>,
                        BOOST_TTI_TRAIT_GEN(MT_BType)<AType>
                        >
                      >
                  ));
  
  return 0;
  
  }
