#include "TestMFHasTemplateCheckParams.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong template types
  
  BOOST_MPL_ASSERT((tti::mf_has_template_check_params
                      <
                      tti::WrongParametersForMP<_>,
                      boost::mpl::identity<AnotherType>
                      >
                  ));
  
  return 0;
  
  }
