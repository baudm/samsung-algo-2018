#!/usr/bin/env python3

import numpy as np

N = 50
M = 100000

buttons = np.random.randint(0, 2**N, (M,))
print(buttons)

print('1')
print('{} {}'.format(N, M))

for b in buttons:
    q = bin(b)
    s = [str(q.count('1'))]
    for i, c in enumerate(q[::-1]):
        if c == '1':
            s.append(str(i))
        elif c == 'b':
            break
    print(' '.join(s))
