#!/usr/bin/env python3
import sys

a = int(sys.argv[1])
b = int(sys.argv[2])
limit = int(sys.argv[3])
sum = 0

for n in range(limit):
    if ((n % a) == 0) or ((n % b) == 0):
        sum += n

print(sum)
