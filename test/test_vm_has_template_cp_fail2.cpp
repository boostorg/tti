#include "test_vm_has_template_cp.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
#if !defined(BOOST_NO_VARIADIC_MACROS)

  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((BOOST_TTI_TRAIT_GEN(HaveCL)<AnotherType>));
  
#else
  
  BOOST_MPL_ASSERT((boost::mpl::false_));
  
#endif //!defined(BOOST_NO_VARIADIC_MACROS)

  return 0;

  }
