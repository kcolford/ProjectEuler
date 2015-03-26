#!/usr/bin/python3

import doctest
from bisect import bisect

landings = list(range(1, 21)) + [25]

def scores(l, s):
    """Return a list of multiplier-score pairs that one dart can
    acquire when it can only land on the values less than or equal to
    l and the score must be less than or equal to s.

    The list is also returned in reverse sorted order.
    """

    global landings

    out, land = [], landings[:bisect(landings, l)]
    for i in [3, 2, 1]:
        out += [(i, land[j]) for j in reversed(range(bisect(land, s/i)))]
    return out

def checkouts(s):
    """Return the number of checkouts for a score less than or equal to s.

    >>> checkouts(6)
    11
    """

    global landings

    out = 0
    for i in landings:
        for (a, b) in scores(25, s - 2*i):
            out += len(scores(b, s - 2*i - a*b))
    return out

if __name__ == '__main__':
    doctest.testmod()
    print(checkouts(100))

