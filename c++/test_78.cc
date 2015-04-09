#include <boost/test/unit_test.hpp>

#include "78.cc"
#include "test_sequence.hh"

#define generalized_pentagonal(n)               \
  pentagonal(n % 2 == 0 ? -n / 2 : n / 2 + 1)

TEST_SEQUENCE_FUNC(generalized_pentagonal, 
                   0, 1, 2, 5, 7, 12, 15, 22, 26, 35, 40, 51, 57,
                   70, 77, 92, 100, 117, 126, 145, 155, 176, 187,
                   210, 222, 247, 260, 287, 301, 330, 345, 376,
                   392, 425, 442, 477, 495, 532, 551, 590, 610,
                   651, 672, 715, 737, 782, 805, 852, 876, 925,
                   950, 1001, 1027, 1080, 1107, 1162, 1190, 1247,
                   1276)

TEST_SEQUENCE_FUNC(p,
                   1, 1, 2, 3, 5, 7, 11, 15, 22, 30, 42, 56, 77,
                   101, 135, 176, 231, 297, 385, 490, 627, 792,
                   1002, 1255, 1575, 1958, 2436, 3010, 3718, 4565,
                   5604)

BOOST_AUTO_TEST_CASE(spot_check)
{
  
