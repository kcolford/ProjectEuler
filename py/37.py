#!/usr/bin/python3

import util

def checkleft(n):
    s = str(n)
    while s:
        if not util.isprime(int(s)):
            return False
        s = s[1:]
    return True

def checkright(n):
    s = str(n)
    while s:
        if not util.isprime(int(s)):
            return False
        s = s[:-1]
    return True

ret, i = [], 10
while len(ret) < 11:
    if checkleft(i) and checkright(i):
        ret.append(i)
        #print(i)
    i += 1
print(sum(ret))
