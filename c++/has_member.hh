#ifndef HAS_MEMBER_HH
#define HAS_MEMBER_HH

#include <boost/type_traits.hpp>
using boost::true_type;
using boost::false_type;

#define __HAS_MEMBER_TEMPLATE(tdef, name)                               \
  template<typename T>                                                  \
  class has_ ## name                                                    \
  {                                                                     \
    typedef tdef;                                                       \
                                                                        \
    template<typename U, member_type U::*>                              \
      struct SFINAE {};                                                 \
                                                                        \
    template<typename U>                                                \
      static char Test(SFINAE<U, &U::name> *);                          \
                                                                        \
    template<typename U>                                                \
      static int Test(...);                                             \
                                                                        \
  public:                                                               \
                                                                        \
    static const bool value = sizeof(Test<T>(0)) == sizeof(char);       \
                                                                        \
    typedef                                                             \
    boost::integral_constant<bool, sizeof(Test<T>(0)) == sizeof(char)>  \
    type;                                                               \
                                                                        \
  }

#define DECLARE_HAS_MEMBER(type, name)          \
  __HAS_MEMBER_TEMPLATE(type member_type, name)

#define DECLARE_HAS_MEMBER_FUNC(return_type, name, argslist)            \
  __HAS_MEMBER_TEMPLATE(return_type (*member_type) argslist,            \
                        name ## _func)

#endif
