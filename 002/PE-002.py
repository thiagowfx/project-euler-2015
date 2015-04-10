#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys

limit = int(sys.argv[1])

def solve(limit):
  sum = 0

  fprev = 1
  fcurr = 2
  fnext = 3

  while fcurr < limit:
    sum += fcurr

    fprev = fcurr + fnext
    fcurr = fprev + fnext
    fnext = fprev + fcurr

  return sum

print(solve(limit))
