#include "TestMFHasTemplateCheckParams.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Template does not exist
  
  BOOST_MPL_ASSERT((tti::mf_has_template_check_params
                      <
                      tti::has_template_check_params_TemplateNotExist,
                      tti::mf_member_type
                        <
                        tti::member_type_CType,
                        tti::MT_BType<AType>
                        >
                      >
                  ));
  
  return 0;
  
  }
