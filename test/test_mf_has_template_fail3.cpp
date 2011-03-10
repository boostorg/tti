#include "test_mf_has_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Too many 'typename' parameters
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template
                      <
                      BOOST_TTI_HAS_TEMPLATE_GEN(SomeMemberTemplate)<_>,
                      boost::mpl::identity<AnotherType>
                      >
                  ));
  
  return 0;
  
  }
