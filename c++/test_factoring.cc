// Test the factoring module.

#include "factoring.hh"
#include "primes.hh"
#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(prime_test) {
  BOOST_CHECK(!is_prime(4));
  BOOST_CHECK(is_prime(1000003));
}

BOOST_AUTO_TEST_CASE(factoring_test) {
#define C(x) do {                               \
    vector<int> p = prime_factors(x);           \
    for (int i = 1; i < p.size(); i++)          \
      BOOST_CHECK_LE(p[i-1], p[i]);             \
  } while (0)
  C(2389472389);
  C(394739);
#undef C
}

BOOST_AUTO_TEST_CASE(factor_counting) {
#define C(x) BOOST_CHECK_EQUAL(factors(x).size(), count_factors(x))
  C(22);
  C(38497);
  C(384);
  C(2349083049);
  C(23943);
#undef C
}
