#!/usr/bin/python3

from util import *

def check(lst):
    """Return true if the number in lst is curious."""

    return all(isprime(num(i)) for i in rotations(lst))

numbers = list(map(int, '0123456789'))
out = set()
for i in range(500000):
    lst = digits(i)
    if check(lst):
        print(i)
        for r in rotations(lst):
            out.add(num(r))

for i in sorted(out):
    print(i)
print(len(out))
