// test the perfect-square routines

#include "perfect_square.hh"
#include <boost/test/unit_test.hpp>

#include "sequence_tester.hh"

TEST_SEQUENCE_FUNC(int_sqrt,
                   0, 1, 0, 0, 2, 0, 0, 0, 0, 3,
                   0, 0, 0, 0, 0, 0, 4, 0, 0, 0,
                   0, 0, 0, 0, 0, 5, 0, 0, 0, 0)

BOOST_AUTO_TEST_CASE(basic_tests) {
  BOOST_CHECK_EQUAL(int_sqrt(0), 0);
  BOOST_CHECK(is_perfect_square(0));
}

