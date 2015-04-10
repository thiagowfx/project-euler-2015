#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
from math import sqrt

number = int(sys.argv[1])

def sieve(N):
  primes = []
  myin = (N + 1) * [True]

  i = 2
  while(i * i <= N):
    if myin[i]:
      j = i * i
      while(j <= N):
        myin[j] = False
        j += i
    i += 1

  for i in range(2, N + 1):
    if myin[i]:
      primes.append(i)

  print(primes)
  return primes


def solve(N):
  primes = sieve(int(sqrt(N)))
  for i in range(len(primes) - 1, -1, -1):
    if (N % primes[i]) == 0:
      return primes[i]
  return None #error


print(solve(number))
