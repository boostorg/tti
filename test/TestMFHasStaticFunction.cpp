#include "TestMFHasStaticFunction.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  BOOST_TEST((tti::mf_has_static_member_function
                <
                tti::HaveTheSIntFunction<_,_,_>,
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
                tti::TheTIntFunction<_,_,_>,
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
                tti::has_static_member_function_TSFunction<_,_,_>,
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
