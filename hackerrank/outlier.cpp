#/* You are given an array (which will have a length of at least 3, but could be very large)
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
#include <vector>

using namespace std;

int main()
{

  int a[] = {160, 3, 1719, 19, 11, 13, -21};
  vector<int> even;
  char x;

  for(int i = 0; i < 7; i++){
    if(a[i] % 2 == 0)
      cin >> x;
      even[i] = a[i];
  }


  if(even[0] % 2 == 0){
    cout << even[0] << endl;
  }else{
    for(int i = 0; i < 7; i++){
      if(a[i] % 2 == 1)
        cout << a[i];
    }
    }


}
