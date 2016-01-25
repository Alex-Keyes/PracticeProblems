/* You are given an array (which will have a length of at least 3, but could be very large)
   containing integers.
   The integers in the array are either entirely odd or entirely
   even except for a single integer N.
   Write a method that takes the array as an argument and returns N.
   For example:

   [2, 4, 0, 100, 4, 11, 2602, 36]

   Should return: 11

   [160, 3, 1719, 19, 11, 13, -21]

   Should return: 160
*/

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{

  //init array of integers to calc the parity (should be 11)
  int even, odd = 0;
  int a[] = {2, 4, 0, 100, 4, 11, 2602, 36};

  // iterate through loop to figure out if the parity is odd or even
  for (int i = 0; i < 8; i++){
    if(a[i] % 2 == 0)
      even++;
    else
      odd++;
  }

  // if parity is odd, then display even number
    if(even == 1)
      for (int i = 0; i < 8; i++){
        if(a[i] % 2 == 0)
          cout << a[i];
  }
    //if parity is even, then display odd number
   else
     for (int i = 0; i < 8; i++){
       if(a[i] % 2 == 1)
         cout << a[i];
     }

}
