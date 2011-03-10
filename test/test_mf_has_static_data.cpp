#include "test_mf_has_static_data.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  BOOST_TEST((boost::tti::mf_has_static_member_data
                <
                BOOST_TTI_HAS_STATIC_MEMBER_DATA_GEN(DSMember)<_,_>,
                boost::mpl::identity<AType>,
                boost::mpl::identity<short>
                >
              ::value
            ));
  
  BOOST_TEST((boost::tti::mf_has_static_member_data
                <
                BOOST_TTI_MTFC_HAS_STATIC_MEMBER_DATA_GEN(DSMember),
                boost::mpl::identity<AType>,
                boost::mpl::identity<short>
                >
              ::value
            ));
  
  return boost::report_errors();

  }
