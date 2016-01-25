#include <iostream>
#include <vector>
using namespace std;

int main()
{

  int a[] = {1,2,3,4,5,6,7,12,4,51,65,34,645,27};
  int x = 5;

  for(int i = 0; i < 14; i++){
    if(x == a[i])
      cout << "Item found at position: [" << i << "]" << endl;
  }
}
