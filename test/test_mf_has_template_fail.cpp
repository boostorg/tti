#include "test_mf_has_template.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // TemplateNotExist does not exist at all
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_template
                      <
                      boost::tti::has_template_TemplateNotExist<_>,
                      boost::tti::MT_BType<AType>
                      >
                  ));
  
  return 0;
  
  }
