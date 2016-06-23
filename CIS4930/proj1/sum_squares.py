""" This module prints the difference between
the square of sums and sum of squares"""
from __future__ import print_function

N = 101
def do_it():
    """ This function does it """
    sum_of_sqrs = 0
    sqr_of_sums = 0
    for i in range(1, N):
        sum_of_sqrs = sum_of_sqrs + (i*i)
    for i in range(1, N):
        sqr_of_sums = sqr_of_sums + i
    sqr_of_sums = sqr_of_sums * sqr_of_sums
    print (sqr_of_sums - sum_of_sqrs)
do_it()
