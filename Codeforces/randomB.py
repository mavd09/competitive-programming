#!/usr/bin/python2

import random
import sys

random.seed(sys.argv[1])
n = 10
m = 10
k = min(n*m, random.randint(1, 20))

print '%d %d %d' % (n, m, k)

pieces = set([])
for _ in xrange(k):
  while True:
    t = random.randint(1, 3)
    r = random.randint(1, n)
    c = random.randint(1, m)
    if (r, c) not in pieces:
      pieces.add((r, c))
      print '%d %d %d' % (t, r, c)
      break