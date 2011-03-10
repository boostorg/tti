#include "test_vm_has_template_cp.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
#if !defined(BOOST_NO_VARIADIC_MACROS)

  // TemplateNotExist does not exist at all
  
  BOOST_MPL_ASSERT((BOOST_TTI_VM_HAS_TEMPLATE_CHECK_PARAMS_GEN(TemplateNotExist)<AType>));
  
#else
  
  BOOST_MPL_ASSERT((boost::mpl::false_));
  
#endif //!defined(BOOST_NO_VARIADIC_MACROS)

  return 0;

  }
