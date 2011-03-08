#include "test_vm_mf_has_static_fun_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
#if !defined(BOOST_NO_VARIADIC_MACROS)

  using namespace boost::mpl::placeholders;
  
  // You can always instantiate without compiler errors
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((boost::mpl::false_));
  
#else
  
  BOOST_MPL_ASSERT((boost::mpl::false_));
  
#endif //!defined(BOOST_NO_VARIADIC_MACROS)

  return 0;

  }
