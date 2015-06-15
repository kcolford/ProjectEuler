// Test the factoring module.

#include "factoring.hh"
#include "primes.hh"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(prime_test) {
  BOOST_CHECK(!is_prime(4));
  BOOST_CHECK(is_prime(1000003));
}

BOOST_AUTO_TEST_CASE(factoring_test) {
  ;
}

