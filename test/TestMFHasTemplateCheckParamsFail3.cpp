#include "TestMFHasTemplateCheckParams.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Wrong template types
  
  BOOST_MPL_ASSERT((tti::mf_has_template_check_params
                      <
                      tti::WrongParametersForMP,
                      boost::mpl::identity<AnotherType>
                      >
                  ));
  
  return 0;
  
  }
