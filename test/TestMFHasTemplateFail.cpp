#include "TestMFHasTemplate.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  // TemplateNotExist does not exist at all
  
  BOOST_MPL_ASSERT((tti::mf_has_template
                      <
                      tti::has_template_TemplateNotExist,
                      tti::MT_BType<AType>
                      >
                  ));
  
  return 0;
  
  }
