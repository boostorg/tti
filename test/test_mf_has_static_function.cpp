#include "test_mf_has_static_fun.hpp"
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  BOOST_TEST((boost::tti::mf_has_static_member_function
                <
                boost::tti::HaveTheSIntFunction<_,_,_>,
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
  
  BOOST_TEST((boost::tti::mf_has_static_member_function
                <
                boost::tti::TheTIntFunction<_,_,_>,
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
  
  BOOST_TEST((boost::tti::mf_has_static_member_function
                <
                boost::tti::has_static_member_function_TSFunction<_,_,_>,
                boost::mpl::identity<AnotherType>,
                boost::tti::member_type_AStructType<AType>,
                boost::mpl::vector
                  <
                  boost::tti::NameIntType<AType>,
                  boost::mpl::identity<double>
                  >
                >
              ::value
            ));
            
            
            
            
  
  BOOST_TEST((boost::tti::mf_has_static_member_function
                <
                boost::tti::MFHaveTheSIntFunction,
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
  
  BOOST_TEST((boost::tti::mf_has_static_member_function
                <
                boost::tti::MFCTheTIntFunction,
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
  
  BOOST_TEST((boost::tti::mf_has_static_member_function
                <
                boost::tti::mtfc_has_static_member_function_TSFunction,
                boost::mpl::identity<AnotherType>,
                boost::tti::member_type_AStructType<AType>,
                boost::mpl::vector
                  <
                  boost::tti::NameIntType<AType>,
                  boost::mpl::identity<double>
                  >
                >
              ::value
            ));
  
  return boost::report_errors();

  }
