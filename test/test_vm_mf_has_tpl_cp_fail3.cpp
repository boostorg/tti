#include "test_vm_mf_has_template_cp.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
#if !defined(BOOST_NO_VARIADIC_MACROS)

  using namespace boost::mpl::placeholders;
  
  // Wrong template types
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template_check_params
                      <
                      boost::tti::WrongParametersForMP<_>,
                      boost::mpl::identity<AnotherType>
                      >
                  ));
  
#endif //!defined(BOOST_NO_VARIADIC_MACROS)

  return 0;
  
  }
