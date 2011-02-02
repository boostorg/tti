#include "TestMFHasStaticFunction.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  BOOST_TEST((tti::mf_has_static_member_function
                <
                tti::HaveTheSIntFunction,
                boost::mpl::identity<AType>,
                boost::mpl::identity<int>,
                boost::mpl::vector
                  <
                  boost::mpl::identity<long>,
                  boost::mpl::identity<double>
                  >
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_static_member_function
                <
                tti::TheTIntFunction,
                boost::mpl::identity<AnotherType>,
                boost::mpl::identity<AType>,
                boost::mpl::vector
                  <
                  boost::mpl::identity<long>,
                  boost::mpl::identity<double>
                  >
                >
              ::value
            ));
  
  BOOST_TEST((tti::mf_has_static_member_function
                <
                tti::has_static_member_function_TSFunction,
                boost::mpl::identity<AnotherType>,
                tti::member_type_AStructType<AType>,
                boost::mpl::vector
                  <
                  tti::NameIntType<AType>,
                  boost::mpl::identity<double>
                  >
                >
              ::value
            ));
  
  return boost::report_errors();

  }
