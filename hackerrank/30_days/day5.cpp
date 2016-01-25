#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  // read T from STDIN and execute algo
  int T, a, b, N,product, sum = 0;
  cin >> T;
  //first loop for number of testcases
  while(T != 0){
    cin >> a >> b >> N;
    //run the actual algo
    for(int j = 0; j < N; j++){
      product = (pow(2,j) * b);
      sum += product;
      cout << sum + a << ' ';
    }
    cout << '\n';
    sum = 0;
    T--;
  }
  return 0;
}
