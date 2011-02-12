#include "test_vm_has_template_check_params.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
#if !defined(BOOST_NO_VARIADIC_MACROS)

  // TemplateNotExist does not exist at all
  
  BOOST_MPL_ASSERT((boost::tti::has_template_check_params_TemplateNotExist<AType>));
  
#endif //!defined(BOOST_NO_VARIADIC_MACROS)

  return 0;

  }
