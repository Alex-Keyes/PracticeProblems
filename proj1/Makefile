######################################################################
#
# Project 1: Recursive Fibonacci Numbers
#
# Author: A. G. Werschulz
# Date:   14 Mar 2016
#
######################################################################

CXXFLAGS=-Wall -std=c++14 -g

proj1: proj1.o Matrix.o
	$(CXX) $(CXXFLAGS) -o proj1 proj1.o 

Matrix.o: Matrix.cc Matrix.h
	$(CXX) $(CXXFLAGS) -c Matrix.cc

clean:
	@/bin/rm -f *~ \#*\# core* proj1 *.o


