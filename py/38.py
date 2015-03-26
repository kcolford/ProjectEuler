#!/usr/bin/python3

from util import *

def check(n):
    """Return a pandigital formed by this number or zero.

    >>> check(192)
    192384576
    """

    out, curr = 0, 0
    for i in range(10):
        curr *= 10**len(str(n*i))
        curr += n*i
        if ispandigital(curr):
            out = curr
    return out

import doctest; doctest.testmod()

big = 0
for i in range(100000):
    c = check(i)
    if c > big:
        big = c
        print(big)
