#include "test_has_template_cp.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // TemplateNotExist does not exist at all
  
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_TEMPLATE_CHECK_PARAMS_GEN(TemplateNotExist)<AType>));
  
  return 0;

  }
