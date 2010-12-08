#include "DiscoveryTest.hpp"
#include <boost/mpl/assert.hpp>
// #include <boost/type_traits/is_same.hpp>

short AType::DSMember(5622);

int main()
  {
  
  BOOST_MPL_ASSERT(( tti::has_type_AnIntType<AType> ));
  BOOST_MPL_ASSERT(( tti::has_type_AStructType<AType> ));
  BOOST_MPL_ASSERT(( tti::has_type_check_typedef_AnIntType<AType,int> ));
  BOOST_MPL_ASSERT(( tti::has_type_check_typedef_AStructType<AType,AType::AStructType> ));
  BOOST_MPL_ASSERT(( tti::has_type_check_typedef_AnIntTypeReference<AType,int &> ));
  BOOST_MPL_ASSERT(( tti::has_template_ATPMemberTemplate<AType> ));
  BOOST_MPL_ASSERT(( tti::has_template_check_AMemberTemplate<AType> ));
  BOOST_MPL_ASSERT(( tti::has_template_check_AnotherMemberTemplate<AType> ));
  BOOST_MPL_ASSERT(( tti::has_template_check_CLMemberTemplate<AType> ));
  BOOST_MPL_ASSERT(( tti::has_member_VoidFunction<void (AType::*)()> ));
  BOOST_MPL_ASSERT(( tti::has_member_aMember<bool AnotherType::*> ));
  BOOST_MPL_ASSERT(( tti::has_member_aFunction<AType (AnotherType::*)(int)> ));
  BOOST_MPL_ASSERT(( tti::mf_has_member_function<tti::has_member_aFunction,boost::mpl::identity<AnotherType>,boost::mpl::identity<AType>,boost::mpl::identity<int> > ));
  BOOST_MPL_ASSERT(( tti::mf_has_member_function<tti::has_member_sFunction,boost::mpl::identity<AnotherType>,tti::member_type_AnIntType<AType>,boost::mpl::identity<int>,boost::mpl::identity<long>,boost::mpl::identity<double> > ));
  BOOST_MPL_ASSERT(( tti::mf_has_member_data<tti::has_member_aMember,boost::mpl::identity<AnotherType>,boost::mpl::identity<bool> > ));
  BOOST_MPL_ASSERT(( tti::has_static_member_SIntFunction<AType,int (long,double)> ));
  BOOST_MPL_ASSERT(( tti::has_static_member_TIntFunction<AnotherType,AType (long,double)> ));
  BOOST_MPL_ASSERT(( tti::has_static_member_DSMember<AType,short> ));
  BOOST_MPL_ASSERT(( tti::mf_has_static_data<tti::has_static_member_DSMember,boost::mpl::identity<AType>,boost::mpl::identity<short> > ));
  BOOST_MPL_ASSERT(( tti::mf_has_static_function<tti::has_static_member_TSFunction,boost::mpl::identity<AnotherType>,tti::member_type_AStructType<AType>,tti::member_type_AnIntType<AType>,boost::mpl::identity<double> > ));
  BOOST_MPL_ASSERT(( tti::mf_has_type_check_typedef<tti::has_type_check_typedef_someOtherType,boost::mpl::identity<AnotherType>,tti::member_type_AnIntType<AType> > ));
  BOOST_MPL_ASSERT(( tti::mf_has_type<tti::has_type_AnIntType,boost::mpl::identity<AType> > ));
  BOOST_MPL_ASSERT(( tti::mf_has_type<tti::has_type_AnIntegerType,tti::member_type_BType<AType> > ));
  BOOST_MPL_ASSERT(( tti::mf_has_type
                       <
                       tti::has_type_AnotherIntegerType,
                       tti::mf_member_type
                         <
                         tti::member_type_CType,
                         tti::mf_member_type
                           <
                           tti::member_type_BType,
                           boost::mpl::identity<AType>
                           >
                         >
                       > 
                  ));
  
//  tti::has_type_check_typedef_NothingType<AnotherType,int> ctnt;

  return 0;

  }
