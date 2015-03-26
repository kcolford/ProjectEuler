#!/usr/bin/python3

def check(n):
    b = [i for i in bin(n)[2:]]
    t = [i for i in str(n)]
    #print(b, list(reversed(b)))
    return b == list(reversed(b)) and t == list(reversed(t))

print(sum(i for i in range(1000000) if check(i)))
