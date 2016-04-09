/*
 * Implementation file for Matrix and Vector classes
 * 
 * @author Harry Q. Bovik
 * @date 33 Octember 5776
 * @file Matrix.cc
 */ 

#include "Matrix.h"

Matrix::Matrix(int a, int b, int c, int d)
{
  data[0][0] = a;
  data[0][1] = b;
  data[1][0] = c;
  data[1][1] = d;
}

Matrix Matrix::power(unsigned int n)
{
  // stub version
  return *this;
}

Matrix Matrix::multiply(const Matrix& rhs)
{
  // stub version
  return *this;
}

Vector::Vector(int x, int y)
{
  data[0] = x;
  data[1] = y;
};

Vector Matrix::mat_vec(const Vector& b)
{
  // stub version
  return b;
}
