/**
 * Header file for 2x2 matrix operations.
 *
 * @author Arthur G. Werschulz
 * @date 15 Mar 2016
 * @file Matrix.h
 */

#pragma once

struct Vector;

/**
 * Some operations on 2x2 matrices, needed for the fast Fibonacci
 * algorithm.  
 */
struct Matrix
{
/**
 * Constructor.
 *
 * Default constructor gives the zero matrix.
 * Four-parameter constructor initializes the four matrix entries from
 * the four parameters.
 */
   Matrix(int a = 0, int b = 0, int c = 0, int d = 0);

/**
 * Multiply the current matrix by another matrix.
 *
 * @param rhs the multplier
 * @return the product
 */
   Matrix multiply(const Matrix& rhs);

/**
 * Compute power of a matrix
 *
 * @param n the power
 * @return matrix raised to the power <em>n</em>
 */
  Matrix power(unsigned int n);

/**
 * Multiply the current matrix by a vector.
 *
 * @param b the vector
 * @return the resulting vector that gives this product
 */
   Vector mat_vec(const Vector& b);
   /// private data for the Matrix
   long data[2][2];
};

/**
 * A two-component vector, needed for the fast Fibonacci algorithm. 
 */
struct Vector
{
/**
 * Constructor.
 * 
 * Default constructor gives the zero vector.
 * Two-parameter constructor initializes the two vector entries from
 * the two parameters.
 */
   Vector (int x = 0, int y = 0);

   /// private data for the Vector
   long data[2];
};
