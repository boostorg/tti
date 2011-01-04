#include "TestMFHasTemplate.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // Too many 'typename' parameters
  
  BOOST_MPL_ASSERT((tti::mf_has_template
                      <
                      tti::has_template_SomeMemberTemplate,
                      boost::mpl::identity<AnotherType>
                      >
                  ));
  
  return 0;
  
  }
