#include "test_mf_has_template_check_params.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template_check_params
                      <
                      boost::tti::has_template_check_params_CTManyParameters<_>,
                      boost::tti::mf_member_type
                        <
                        boost::tti::member_type_CType<_>,
                        boost::mpl::identity<AType>
                        >
                      >
                  ));
  
  return 0;
  
  }
