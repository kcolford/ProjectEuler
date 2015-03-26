#!/usr/bin/python3

from util import *

d = lambda: map(int, chain.from_iterable(map(str, count())))
f = lambda x: next(islice(d(), x, x+1))

out = [f(10**i) for i in range(7)]
#print(*out, sep='\n')
print(reduce(op.mul, out))
