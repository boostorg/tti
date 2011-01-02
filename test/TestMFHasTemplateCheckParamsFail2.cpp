#include "TestMFHasTemplateCheckParams.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((tti::mf_has_template_check_params
                      <
                      tti::has_template_check_params_CTManyParameters,
                      tti::mf_member_type
                        <
                        tti::member_type_CType,
                        boost::mpl::identity<AType>
                        >
                      >
                  ));
  
  return 0;
  
  }
