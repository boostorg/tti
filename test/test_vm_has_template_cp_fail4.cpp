#include "test_vm_has_template_cp.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
#if !defined(BOOST_NO_VARIADIC_MACROS)

  // Wrong template parameters
  
  BOOST_MPL_ASSERT((boost::tti::WrongParameters2ForMP<AnotherType>));
  
#endif //!defined(BOOST_NO_VARIADIC_MACROS)

  return 0;

  }
