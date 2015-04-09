// test the multiplicative order module

#include "multiplicative_order.hh"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(basic_order) {
  BOOST_CHECK_EQUAL(multiplicative_order(10, 7), 6);
}
