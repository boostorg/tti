#include "test_mf_has_mem_fun.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong enclosing type for nested type
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_member_function
                      <
                      BOOST_TTI_HAS_MEMBER_FUNCTION_GEN(sFunction)<_,_,_>,
                      boost::mpl::identity<AnotherType>,
                      BOOST_TTI_MEMBER_TYPE_GEN(AnIntType)<AnotherType>,
                      boost::mpl::vector
                        <
                        boost::mpl::identity<int>,
                        boost::mpl::identity<long>,
                        boost::mpl::identity<double>
                        >
                      >
                  ));
  
  return 0;

  }
