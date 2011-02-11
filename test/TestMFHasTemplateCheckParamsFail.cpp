#include "test_mf_has_template_check_params.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Template does not exist
  
  BOOST_MPL_ASSERT((tti::mf_has_template_check_params
                      <
                      tti::has_template_check_params_TemplateNotExist<_>,
                      tti::mf_member_type
                        <
                        tti::member_type_CType<_>,
                        tti::MT_BType<AType>
                        >
                      >
                  ));
  
  return 0;
  
  }
