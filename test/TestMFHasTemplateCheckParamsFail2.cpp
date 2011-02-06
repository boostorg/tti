#include "TestMFHasTemplateCheckParams.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((tti::mf_has_template_check_params
                      <
                      tti::has_template_check_params_CTManyParameters<_>,
                      tti::mf_member_type
                        <
                        tti::member_type_CType<_>,
                        boost::mpl::identity<AType>
                        >
                      >
                  ));
  
  return 0;
  
  }
