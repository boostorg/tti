#include "TestMFHasStaticData.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST((tti::mf_has_static_data
                <
                tti::has_static_member_DSMember,
                boost::mpl::identity<AType>,
                boost::mpl::identity<short>
                >
              ::value
            ));
  
  return boost::report_errors();

  }
