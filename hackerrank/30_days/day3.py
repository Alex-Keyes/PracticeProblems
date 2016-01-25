#!/bin/python

import sys


N = int(raw_input().strip())

if(N % 2 == 1):
    print "Weird"
elif(6 <= N & N <= 20):
    print "Weird"
else:
    print "Not Weird"
    
