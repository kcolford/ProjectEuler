#!/usr/bin/python3

from util import fac, digits

def foo(n):
    return sum(map(fac, digits(n)))

def check(n):
    """Return True if n is a curious number.

    >>> check(145)
    True

    """

    return n == foo(n)

for i in range(10, 100000):
    if check(i):
        print(i)
print(sum([i for i in range(10, 100000) if check(i)]))
