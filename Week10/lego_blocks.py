#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'legoBlocks' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER m
#

def legoBlocks(n, m):
    mod = 10**9 + 7
    singleCombo = [1, 2, 4, 8]

    for i in range (4, m):
        singleCombo.append(sum(singleCombo[-4:]) % mod)
    
    totalCombo = [(row**n) % mod for row in singleCombo]

    validCombo = [1]

    for i in range(1, m):
        invalidCombo = sum([total * valid for total, valid in zip(totalCombo[:i], validCombo[::-1])]) 
        validCombo.append((totalCombo[i] - invalidCombo) % mod)
    
    return validCombo[-1]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        first_multiple_input = input().rstrip().split()

        n = int(first_multiple_input[0])

        m = int(first_multiple_input[1])

        result = legoBlocks(n, m)

        fptr.write(str(result) + '\n')

    fptr.close()
