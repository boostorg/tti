#include "test_mf_has_static_fun.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong function parameter type
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_static_member_function
                      <
                      BOOST_TTI_HAS_STATIC_MEMBER_FUNCTION_GEN(TSFunction)<_,_,_>,
                      boost::mpl::identity<AnotherType>,
                      BOOST_TTI_MEMBER_TYPE_GEN(AStructType)<AType>,
                      boost::mpl::vector
                        <
                        BOOST_TTI_TRAIT_GEN(NameIntType)<AnotherType>,
                        boost::mpl::identity<double>
                        >
                      >
                  ));
  
  return 0;

  }
