#if !defined(TTI_DETAIL_TSELF_HPP)
#define TTI_DETAIL_TSELF_HPP

namespace boost
  {
  namespace tti
    {
    namespace detail
      {
      template <class T>
      struct tself : T
        {
        };
      }
    }
  }
  
#endif // TTI_DETAIL_TSELF_HPP
