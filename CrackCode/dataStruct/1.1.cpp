/*
 * Implement an Algo to determine if a string has all unique chars
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isUnique(string S){

  if (S.length() > 128)
		{
			return false;
		}
  std::vector<bool> char_set(128);
  for (int i = 0; i < S.length(); i++)
		{
			int val = S[i];
			if (char_set[val])
        {
          return false;
        }
			char_set[val] = true;
		}
  return true;

}

int main()
{
  vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
  for (auto word : words)
		{
			cout << word << string(": ") << isUnique(word) << endl;
		}
}
/*iterate through string with a counting var.  If the counting var > 1 then there is a duplicate char.

  for(string size S)

  count

  but you could also use a hash?  Each char will have a unique value unless its a duplicate. */

