#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'miniMaxSum' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def miniMaxSum(arr):
    # Write your code here
    arr.sort()
    maxsum, minsum = 0,0
    
    for i in range(0,len(arr)-1):
        maxsum = maxsum + arr[i]

    for j in range(1, len(arr)):
        minsum = minsum + arr[j]
        
    print(maxsum, minsum)

if __name__ == '__main__':

    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)
