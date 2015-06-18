// test the perfect-square routines

#include "perfect_square.hh"
#include <boost/test/unit_test.hpp>
#include "len.h"

BOOST_AUTO_TEST_CASE(basic_tests) {
  BOOST_CHECK_EQUAL(int_sqrt(0), 0);
  BOOST_CHECK(is_perfect_square(0));

  static uint64_t right[] = {
    0, 1, 0, 0, 2, 0, 0, 0, 0, 3,
    0, 0, 0, 0, 0, 0, 4, 0, 0, 0,
    0, 0, 0, 0, 0, 5, 0, 0, 0, 0,
  };
  for (int i = 0; i < len(right); i++)
    BOOST_CHECK_EQUAL(int_sqrt(i), right[i]);    
}

