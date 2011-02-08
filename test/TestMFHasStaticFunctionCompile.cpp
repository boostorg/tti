#include "TestMFHasStaticFunction.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // You can always instantiate without compiler errors
  
  tti::mf_has_static_member_function
    <
    tti::HaveTheSIntFunction<_,_,_>,
    boost::mpl::identity<AType>,
    boost::mpl::identity<int>,
    boost::mpl::vector
      <
      boost::mpl::identity<long>,
      boost::mpl::identity<short>
      >
    > aVar;
  
  tti::mf_has_static_member_function
    <
    tti::MTFCPickedname,
    boost::mpl::identity<AType>,
    boost::mpl::identity<double>,
    boost::mpl::vector<boost::mpl::identity<float> >
    > aVar2;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((tti::mf_has_static_member_function
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
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_static_member_function
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
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_static_member_function
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
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_static_member_function
                      <
                      tti::MFHaveTheSIntFunction,
                      boost::mpl::identity<AType>,
                      boost::mpl::identity<int>,
                      boost::mpl::vector
                        <
                        boost::mpl::identity<long>,
                        boost::mpl::identity<double>
                        >
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_static_member_function
                      <
                      tti::MFCTheTIntFunction,
                      boost::mpl::identity<AnotherType>,
                      boost::mpl::identity<AType>,
                      boost::mpl::vector
                        <
                        boost::mpl::identity<long>,
                        boost::mpl::identity<double>
                        >
                      >
                  ));
  
  BOOST_MPL_ASSERT((tti::mf_has_static_member_function
                      <
                      tti::mtfc_has_static_member_function_TSFunction,
                      boost::mpl::identity<AnotherType>,
                      tti::member_type_AStructType<AType>,
                      boost::mpl::vector
                        <
                        tti::NameIntType<AType>,
                        boost::mpl::identity<double>
                        >
                      >
            ));
  
  return 0;

  }
