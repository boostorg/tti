#include "test_mf_has_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Too many 'typename' parameters
  
  BOOST_MPL_ASSERT((tti::mf_has_template
                      <
                      tti::has_template_SomeMemberTemplate<_>,
                      boost::mpl::identity<AnotherType>
                      >
                  ));
  
  return 0;
  
  }
