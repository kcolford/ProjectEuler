// testing program for the util library

#define BOOST_TEST_MODULE util_test
#include <boost/test/unit_test.hpp>

#include "factoring.hh"

BOOST_AUTO_TEST_CASE(freetest) {
  BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(basic_factoring) {
  BOOST_CHECK(prime_factors(32948) == std::vector<int>({2, 2, 8237}));
}
