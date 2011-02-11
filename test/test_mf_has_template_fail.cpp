#include "test_mf_has_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // TemplateNotExist does not exist at all
  
  BOOST_MPL_ASSERT((tti::mf_has_template
                      <
                      tti::has_template_TemplateNotExist<_>,
                      tti::MT_BType<AType>
                      >
                  ));
  
  return 0;
  
  }
