#ifndef SEQUENCE_TESTER_HH
#define SEQUENCE_TESTER_HH

#include <algorithm>
#include <boost/preprocessor.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/utility/result_of.hpp>
#include <cstddef>
#include "len.h"

typedef signed long long int test_data_type;

#define TEST_SEQUENCE_APPLY(z, n, f) f(n)

#define TEST_SEQUENCE_FUNC(func, ...)                           \
  BOOST_AUTO_TEST_CASE(test_function_ ## func)                  \
  {                                                             \
    static test_data_type right_data[] = {                      \
      __VA_ARGS__                                               \
    };                                                          \
    test_data_type test_data[] = {                              \
      BOOST_PP_ENUM(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__),        \
                    TEST_SEQUENCE_APPLY, func)                  \
    };                                                          \
    size_t l = std::min(len(test_data), len(right_data));       \
    BOOST_CHECK_EQUAL_COLLECTIONS(test_data, test_data + l,     \
                                  right_data, right_data + l);  \
  }

#endif
