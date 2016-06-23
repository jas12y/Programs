""" This module prints the difference between
the square of sums and sum of squares"""
from __future__ import print_function

N = 101
SUM_OF_SQRS = 0
SQR_OF_SUMS = 0
for i in range(1, N):
    SUM_OF_SQRS = SUM_OF_SQRS + (i*i)
for i in range(1, N):
    SQR_OF_SUMS = SQR_OF_SUMS + i
SQR_OF_SUMS = SQR_OF_SUMS * SQR_OF_SUMS
ANS = SQR_OF_SUMS - SUM_OF_SQRS
print (ANS)
