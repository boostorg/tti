#include "test_vm_mf_has_template_cp.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
#if !defined(BOOST_NO_VARIADIC_MACROS)

  using namespace boost::mpl::placeholders;
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template_check_params
                      <
                      boost::tti::has_template_check_params_CTManyParameters<_>,
                      boost::tti::mf_member_type
                        <
                        boost::tti::member_type_CType<_>,
                        boost::mpl::identity<AType>
                        >
                      >
                  ));
  
#else
  
  BOOST_MPL_ASSERT((boost::mpl::false_));
  
#endif //!defined(BOOST_NO_VARIADIC_MACROS)

  return 0;
  
  }
