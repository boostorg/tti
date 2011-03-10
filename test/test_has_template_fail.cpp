#include "test_has_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // TemplateNotExist does not exist at all
  
  BOOST_MPL_ASSERT((BOOST_TTI_HAS_TEMPLATE_GEN(TemplateNotExist)<AType>));
  
  return 0;

  }
