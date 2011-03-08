#include "test_vm_mf_has_static_fun_template.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
#if !defined(BOOST_NO_VARIADIC_MACROS)

  using namespace boost::mpl::placeholders;
  
#endif //!defined(BOOST_NO_VARIADIC_MACROS)

  return boost::report_errors();

  }
