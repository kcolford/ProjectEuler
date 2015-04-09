#ifndef TEST_SEQUENCE_HH
#define TEST_SEQUENCE_HH

#include <algorithm>
#include <boost/preprocessor.hpp>
#include <boost/test/unit_test.hpp>
#include "len.h"

#define TEST_SEQUENCE_APPLY(z, n, f) f(n)

#define TEST_SEQUENCE_FUNC(func, ...)                           \
  BOOST_AUTO_TEST_CASE(test_function_ ## func)                  \
  {                                                             \
    static int right_data[] = {                                 \
      __VA_ARGS__                                               \
    };                                                          \
    int test_data[] = {                                         \
      BOOST_PP_ENUM(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__),        \
                    TEST_SEQUENCE_APPLY, func)                  \
    };                                                          \
    int l = std::min(len(test_data), len(right_data));          \
    BOOST_CHECK_EQUAL_COLLECTIONS(test_data, test_data + l,     \
                                  right_data, right_data + l);  \
  }

#endif
