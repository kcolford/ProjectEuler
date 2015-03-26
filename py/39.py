#!/usr/bin/python3 -O

"""Test Me

>>> dp[120]
3

"""

from util import *

dp = Counter()

for m in range(1000):
    for n in range(1, m):
        # Only select primitive pythagorean triples.  Therefore m and
        # n have to be coprime and one of them has to be even (while
        # the other is odd, but they both can't be even since they are
        # coprime).
        if (m + n)%2 != 1 or gcd(m, n) != 1:
            continue

        # Add in all the perimeters less than or equal to 1000 to the
        # counter.
        lst = list(range(0, 1001, 2*m*(m + n)))
        if __debug__ and 120 in lst:
            f = lst.index(120)
            print(f*(m**2 - n**2), f*2*m*n, f*(m**2 + n**2))
        dp.update(lst)

import doctest; doctest.testmod()
#print(dp)

print(dp.most_common(2)[1][0])
