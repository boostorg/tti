#include "test_mf_has_static_fun.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // Wrong enclosing type
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_static_member_function
                      <
                      BOOST_TTI_TRAIT_GEN(HaveTheSIntFunction)<_,_,_>,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<int>,
                      boost::mpl::vector
                        <
                        boost::mpl::identity<long>,
                        boost::mpl::identity<double>
                        >
                      >
                  ));
  
  return 0;

  }
