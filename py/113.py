#!/usr/bin/python3

import doctest
import util


def multicombination(sp1, t):
    """Return the size of the multicombination of sp1 things taken t
    at a time.

    It is essentially the equivalent of a combination with repetitions
    allowed.

    See Knuth, section 7.2.1.3.
    
    sp1 - the size of the subset we are taking from
    t - the number of elements we are taking at a time
    """

    return util.combination(sp1 - 1 + t, t)

def _safe_notbouncy(n):
    """
    >>> _safe_notbouncy(1)
    9
    >>> _safe_notbouncy(2)
    99
    >>> _safe_notbouncy(3)
    474
    >>> _safe_notbouncy(6)
    12951
    """

    return len([i for i in range(1, 10**n) if not util.is_bouncy(i)])

def notbouncy(n):
    """Return the number of not bouncy numbers having n digits or
    less.

    n - the maximum number of digits to check for

    >>> notbouncy(1)
    9
    >>> notbouncy(2)
    99
    >>> notbouncy(3) - _safe_notbouncy(3)
    0
    >>> notbouncy(4) - _safe_notbouncy(4)
    0
    >>> notbouncy(5) - _safe_notbouncy(5)
    0
    >>> notbouncy(6)
    12951
    >>> notbouncy(10)
    277032
    """

    return sum((n - i + 2) * multicombination(9, i) - 9
               for i in range(1, n + 1))

if __name__ == '__main__':
    doctest.testmod()
    print(notbouncy(100))
