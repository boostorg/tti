#if !defined(TTI_DETAIL_TFUNCTION_HPP)
#define TTI_DETAIL_TFUNCTION_HPP

#include <boost/config.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/function_types/function_type.hpp>

namespace boost
  {
  namespace tti
    {
    namespace detail
      {
      template
        <
        class R,
        class FS,
        class TAG
        >
      struct tfunction_seq
        {
        typedef typename boost::mpl::push_front<FS,R>::type ftseq;
        typedef typename boost::function_types::function_type<ftseq,TAG>::type type;
        };
      }
    }
  }
  
#endif // TTI_DETAIL_TFUNCTION_HPP
