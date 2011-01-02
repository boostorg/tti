#include "TestVMMFHasTemplateCheckParams.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
#if !defined(BOOST_NO_VARIADIC_MACROS)

  // Wrong template types
  
  BOOST_MPL_ASSERT((tti::mf_has_template_check_params
                      <
                      tti::WrongParametersForMP,
                      boost::mpl::identity<AnotherType>
                      >
                  ));
  
#endif //!defined(BOOST_NO_VARIADIC_MACROS)

  return 0;
  
  }
