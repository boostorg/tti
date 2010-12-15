#include "TestVMHasTemplateCheckParams.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // TemplateNotExist does not exist at all
  
  BOOST_MPL_ASSERT((tti::has_template_check_params_TemplateNotExist<AType>));
  
  return 0;

  }
