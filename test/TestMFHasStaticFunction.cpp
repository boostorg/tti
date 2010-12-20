#include "TestMFHasStaticFunction.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST((tti::mf_has_static_function
                <
                tti::HaveTheSIntFunction,
                boost::mpl::identity<AType>,
                boost::mpl::identity<int>,
                boost::mpl::identity<long>,
                boost::mpl::identity<double>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_static_function
                <
                tti::TheTIntFunction,
                boost::mpl::identity<AnotherType>,
                boost::mpl::identity<AType>,
                boost::mpl::identity<long>,
                boost::mpl::identity<double>
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_static_function
                <
                tti::has_static_member_TSFunction,
                boost::mpl::identity<AnotherType>,
                tti::member_type_AStructType<AType>,
                tti::NameIntType<AType>,
                boost::mpl::identity<double>
                >
              ::value
            ));
  
  return boost::report_errors();

  }
