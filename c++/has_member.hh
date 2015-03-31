#ifndef HAS_MEMBER_HH
#define HAS_MEMBER_HH

#define DECLARE_HAS_MEMBER(type, name)                                  \
  template<typename T>                                                  \
  class has_ ## name                                                    \
  {                                                                     \
    typedef type member_type;                                           \
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
  };

#endif
