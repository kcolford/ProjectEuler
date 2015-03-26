#!/usr/bin/python3

import bisect
import doctest
import functools

class myset(frozenset):
    def __lt__(self, other):
        return len(self) < len(other)

@functools.lru_cache(None)
def _m(k: int) -> list:
    if k < 2:
        return [myset()]
    out = {myset(f | l | {k}) for i in range(1, k) for f in _m(i) for l in _m(k - i)}
    out = sorted(out)
    out = out[:bisect.bisect_right(out, out[0])]
    return out

@functools.lru_cache(None)
def m(k: int) -> int:
    """
    >>> m(15)
    5
    """
    return len(_m(k)[0])

if __name__ == '__main__':
    doctest.testmod()
    print(sum(m(i + 1) for i in range(200)))

