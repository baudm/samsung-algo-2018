#!/usr/bin/env python3

import random

N = 10000
m = 10**9

print(N)
for i in range(N):
    x = random.randint(1, 10**9)
    print(x, end=' ')

print('')

for i in range(10**5):
    s = e = random.randint(0, N - 1)
    while e < s + 2:
        e = random.randint(0, N - 1)
    print('0 ' + str(s) + ' ' + str(e))
