#!/usr/bin/python3

from collections import *
from fractions import *
from functools import *
from itertools import *
from math import *

from builtins import pow

import operator as op

def ispandigital(*nums, frm=1, to=9):
    """Return True if the numbers concatenated by nums are pandigital.

    >>> ispandigital(123456789)
    True
    >>> ispandigital(123, 456, 789)
    True
    >>> ispandigital(1)
    False

    """

    dl = list(chain.from_iterable(map(digits, nums)))
    if len(dl) != to - frm + 1:
        return False
    for i in range(frm, to+1):
        if i not in dl:
            return False
    return True

def digits(n, base=10):
    """Return the the digits of n as a list."""

    if not n:
        return [0]

    out = []
    while n:
        n, m = divmod(n, base)
        out.append(m)
    out.reverse()
    return out

def num(lst):
    """Return the number whose digits are those of lst."""

    return reduce(lambda x, y: x*10+y, lst)

@lru_cache(None)
def _isprime(p):
    """Backend function for the isprime method.
    """

    for i in primes():
        d, m = divmod(p, i)
        if m == 0:
            return False
        if d < i:
            return True
    raise RuntimeError("this should not have been reached")

def isprime(p):
    """Return True if the number p is prime.

    p - The number to test for primality.

    >>> isprime(3)
    True
    >>> isprime(4)
    False
    >>> isprime(1000003)
    True
    """

    if p < 2:
        return False
    if p == 2:
        return True
    if p & 1 == 0: 
        return False
    return _isprime(p)

def primes():
    """Generator that produces primes.
    """
    
    for i in [2, 3, 5, 7]:
        yield i
    c = 11
    while True:
        if _isprime(c):
            yield c
        c += 2

BOUNCY = 0
INCREASING = 1
DECREASING = 2
NOTBOUNCY = 3

@lru_cache(None)
def _is_bouncy(num, *, prev=None, b=None):
    if num == 0:
        return NOTBOUNCY
    if prev is None and b is None:
        prev, b = divmod(num, 10)
    if prev == 0:
        return NOTBOUNCY
    helper, a = divmod(prev, 10)
    p = _is_bouncy(prev, prev=helper, b=a)
    if a < b:
        return p & INCREASING
    elif a > b:
        return p & DECREASING
    else:
        return p

def is_bouncy(num):
    """Return whether or not the number num is a bouncy number.
    
    num - the number to test

    >>> is_bouncy(0)
    False
    >>> is_bouncy(5)
    False
    >>> is_bouncy(54)
    False
    >>> is_bouncy(101)
    True
    >>> is_bouncy(110)
    False
    """

    return _is_bouncy(num) == BOUNCY

def combination(n, t):
    """Return the size of the combination of n things taken t at a
    time.

    This is also called "n choose t" and can be represented by the
    equasion:

         n! / (t! * (n - t)!)

    n - the size of the set to take from
    t - the number of elements taken at a time
    """

    return fac(n) // (fac(t) * fac(n - t))

def rotations(lst):
    """Return a list of tuples of all the rotations of lst."""

    lst = deque(lst)
    out = []
    for i in range(len(lst)):
        out.append(tuple(lst))
        lst.rotate()
    return out

def xgcd(a, b):
    r1 = (a, 1, 0)
    r2 = (b, 0, 1)

    def bool_(b):
        try:
            return bool(b)
        except ValueError:
            return b.all()
    
    while bool_(r2[0] != 0):
        div = r1[0] // r2[0]
        r3 = tuple(x - y*div for x, y in zip(r1, r2))
        r1, r2 = r2, r3
        
    return r1

fac = factorial
multicomb = combinations_with_replacement

if __name__ == '__main__':
    import doctest; doctest.testmod()
