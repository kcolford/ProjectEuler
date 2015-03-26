#!/usr/bin/python3

import doctest
from util import is_bouncy

def number_at(p):
    """Return the number at which the percentage of bouncy numbers is
    exactly p.

    p - the percentage at which to stop calculating

    >>> number_at(50)
    538
    >>> number_at(90)
    21780
    """

    b, i = 0.0, 1
    while b / i * 100 != p:
        assert b / i * 100 < p
        i += 1
        if is_bouncy(i):
            b += 1
    return i

if __name__ == '__main__':
    doctest.testmod()
    print(number_at(99))

