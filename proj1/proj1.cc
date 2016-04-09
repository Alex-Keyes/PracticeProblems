/**********************************************************************
*
* CISC 4080/5825: Computer Algorithms</br>
* Recursive Fibonacci Algo Comparisons<br/>
*
* <p>Computes Fibonacci numbers by the following algorithms:</p>
* <ol>
*  <li>Naive recursion.</li>
*  <li>Recursion using memoization.</li>
*  <li>The exact solution, via fast computation of a matrix power.</li>
* </ol>
* <p>It also gives the timing of these algorithms.</p>
*
* @author Alex Keyes
* @date April 4th 2016
* @file proj1.cc
*
**********************************************************************/

#include <chrono>
#include <cstring>
#include <cstdlib>
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#define ll long long 

using namespace std;
using namespace chrono;

using Fib_alg = long int(*)(unsigned int);

// function prototypes

/**
 * Print a usage msg
 */
void usage(string progname);

/**
 * Test a Fibonacci algorithm, by computing the Fibonacci numbers 
 *
 * More precisely, it uses a specific algorithm to compute these
 * Fibonacci numbers, as well as time how long it took to do so.
 *
 * @param fib a Fibonacci algorithm
 * @param n maximum Fibonacci index 
 */
void test_alg(string name, Fib_alg fib, unsigned int n);

/**
 * Naive implementation of recursive Fibonacci algorithm.
 *
 * @param n index of Fibonacci number <i>F<sub>n</sub></i>
 * @param ops number of arithmetic operations needed to compute
 * <i>F<sub>n</sub></i>
 *
 * @return <i>F<sub>n</sub></i>
 * @pre n >= 0
 */
long int naive(unsigned int n);

/**
 * Recursive Fibonacci algorithm, using memoization.
 *
 * @param n index of Fibonacci number <i>F<sub>n</sub></i>
 * @param ops number of arithmetic operations needed to compute
 * <i>F<sub>n</sub></i> 
 *
 * @return <i>F<sub>n</sub></i>
 * @pre n >= 0
 */
long int memoizing(unsigned int n);

/**
 * Recursively computes a Fibonacci number, maintaining its results in
 * a vector.
 *
 * @param n index of Fibonacci number.
 * @param fib_vec vector of <code>Fib_entry</code> items.
 * @pre fib_vec holds the <code>Fib_entry</code> records for all
 * Fibonacci numbers computed so far.
 * @post fib_vec holds the <code>Fib_entry</code> records for the
 * Fibonacci numbers 
 * <i>F</i><sub>0</sub>, <i>F</i><sub>1</sub>, ...
 * <i>F<sub>n</sub></i>.
 */
void memoize_helper(unsigned int n, vector<int>& fib_vec);

/**
 * Fibonacci algorithm, using fast computation of matrix power
 *
 * @param n index of Fibonacci number <i>F<sub>n</sub></i>
 * @param ops number of arithmetic operations needed to compute
 * <i>F<sub>n</sub></i> 
 * @return <i>F<sub>n</sub></i>
 * @pre n >= 0
 */
long int fast(unsigned int n);

/**
 * The usual main function
 *
 * Takes a non-negative integer <em>n</em> from the command line.
 * It then uses the aforementioned algorithms to compute (and print) the
 * Fibonacci numbers 
 * <em>F</em><sub>0</sub>, <em>F</em><sub>1</sub>, ...
 * <em>F</em><sub>n</sub>.
 * In addition, it displays the amount of time each algorithm took to
 * compute these Fibonacci numbers.
 */
int main(int argc, char* argv[])
{
   /// program name, for error msgs
   string progname {argv[0]};

   try {
      // check command line arguments
      if (argc != 2) {
         usage(progname);
         return 1;
      }

      /// order of highest Fibonacci number
      unsigned int n = stoul(argv[1]);

      // test them out
      test_alg("naive", naive, n);
      cout << endl;
      test_alg("memoizing", memoizing, n);
      cout << endl;
      test_alg("fast", fast, n);

      return 0;

   } // try

   catch (exception) {
      usage(progname);
      return 2;
   }
}

// function definitions

void usage(string progname)
{
   cerr << "usage:\n   " << progname << " n\n"
        << "where  n  is a non-negative integer\n";
}

void test_alg(string name, Fib_alg fib, unsigned int n)
{
   auto start = system_clock::now();
   cout << "Using " << name << " algorithm:\n";
   for (unsigned int i = 0; i <= n; i++) {
      long int result = fib(i);
      cout << "Fib[" << i << "] = " << result << endl;
   }
   auto end = system_clock::now();
   duration<double> elapsed_seconds = end - start;
   cout << "Elapsed time: " << setprecision(3)
        << elapsed_seconds.count() << " seconds\n";
}

//recursive
long int naive(unsigned int n)
{
  return (n == 0 || n == 1) ? n : naive(n-1) + naive(n-2);
}

//fib using vectors
long int memoizing(unsigned int n)
{
   static vector<int> fib_vec;
   memoize_helper(n, fib_vec);
   long next = fib_vec.at(n);
   return next;
}

//helper func for memoize
void memoize_helper(unsigned int n, vector<int>& fib_vec)
{
  //if the vector is zero, push back the first two fib nums
  if (fib_vec.size() == 0)
  {
    fib_vec.push_back(0);
    fib_vec.push_back(1);
  }

  //for every other case push back the fib nums into a vector
  for (unsigned int i = fib_vec.size(); i <= n; i++)
    fib_vec.push_back(fib_vec[i-1] + fib_vec[i-2]);

}

/*
 * function to multiply two matrices
 */
void multiply(ll F[2][2], ll M[2][2])
{
  ll x =  F[0][0] * M[0][0] + F[0][1] * M[1][0];
  ll y =  F[0][0] * M[0][1] + F[0][1] * M[1][1];
  ll z =  F[1][0] * M[0][0] + F[1][1] * M[1][0];
  ll w =  F[1][0] * M[0][1] + F[1][1] * M[1][1];
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

/*
 *function to calculate power of a matrix
 */
void power(ll F[2][2], int n)
{
  if (n == 0 || n == 1)
    return;
  ll M[2][2] = {{1,1},{1,0}};
  power(F, n / 2);
  multiply(F, F);
  if (n % 2 != 0)
    multiply(F, M);
}

/*
 * fast fib using matrix multiplication
 */
long int fast(unsigned int n)
{
  ll F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n - 1);
  return F[0][0];
}
