#!/usr/bin/python3

from fractions import gcd
from functools import reduce
import operator as op

def frac(a, b):
    g = gcd(a, b)
    a //= g
    b //= g
    return (a, b)

def check(a, b):
    """Check if the fraction a/b is curious.

    >>> check(49, 98)
    True
    >>> check(30, 50)
    False
    
    """

    if a == b:
        return False

    c, d = divmod(a, 10)
    e, f = divmod(b, 10)
    
    if d == e:
        a, b = frac(a, b)
        c, f = frac(c, f)
        
        return (c, f) == (a, b)
    
    return False

import doctest; doctest.testmod()

out = []
for i in range(10, 100):
    for j in range(10, 100):
        if not check(i, j):
            continue
        out.append((i, j))
a, b = zip(*out)
a = reduce(op.mul, a)
b = reduce(op.mul, b)

a, b = frac(a, b)

print(b)
