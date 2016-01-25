// A small test suite for the recursive binary search implementation
#include <vector>
#include <cassert>
#include "binary_search.h"

using namespace std;

// A helper function for the binary search
int search(const vector<int>& vec, const int& key)
{
  return binary_search(vec, 0, vec.size()-1, key);
}

int main()
{
  // create + output an unsorted vector
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(5);
  vec.push_back(13);
  vec.push_back(72);
  vec.push_back(51);
  vec.push_back(58);
  vec.push_back(97);

  // use the binary search algo to find an element
  int search_vals[] = {1,5,19,21,92,43,103};
  int expected_vals[] = {0,1,-1,4,6,5,-1};

  for(int i = 0; i < 7; i++)
  {
    assert(expected_vals[i] == search(vec,search_vals[i]));
  }

  return 0;

}
