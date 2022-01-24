#include <string>
#include <cassert>
#include <iostream>
#include <unordered_set>
using namespace std;

/*
    Given a string s, find the length of the longest substring without repeating characters.


    Example 1:
    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.

    Example 2:
    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.

    Example 3:
    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


    Constraints:
    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          int start = 0, end = 0, n = s.size(), flen = 0;
          unordered_set<char> chars;

          while(start < n && end < n)
          {
              if(chars.count(s[end]))
              {
                  chars.erase(s[start]);
                  start++;
              }
              else
              {
                  chars.insert(s[end]);
                  end++;
                  flen = std::max(flen, end - start);
              }
          }

          return flen;

    }
};


int main(int argc, char * argv[]) {
    Solution sol;

    assert(sol.lengthOfLongestSubstring("abcabcbb") == 3);
    assert(sol.lengthOfLongestSubstring("bbbbb") == 1);
    assert(sol.lengthOfLongestSubstring("pwwkew") == 3);
    assert(sol.lengthOfLongestSubstring("cuccarcuccucr") == 4);

    cout << "tests is passed!" << endl;

    return 0;
}
