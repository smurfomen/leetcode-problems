#include <string>
#include <cassert>
#include <iostream>
#include <unordered_set>
using namespace std;

/*
    Given a string s, return the longest palindromic substring in s.

    Example 1:
        Input: s = "babad"
        Output: "bab"
        Explanation: "aba" is also a valid answer.

    Example 2:
        Input: s = "cbbd"
        Output: "bb"

    Constraints:
        1 <= s.length <= 1000
        s consist of only digits and English letters.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int left = 0, right = 0;
        int n = s.length();
        string result;

        for(int i = 0; i < n; i++)
        {
            for(int k = 0; k < 2; ++k)
            {
                left = i; right = i + k;
                while(left >= 0 && right < n && s[left] == s[right])
                {
                    int strlen = right - left + 1;
                    if(result.length() < strlen)
                        result = s.substr(left, strlen);

                    left--;
                    right++;
                }
            }
        }

        return result;
    }
};


int main(int argc, char * argv[]) {
    Solution sol;

    assert(sol.longestPalindrome("babad") == "bab");
    assert(sol.longestPalindrome("cbbd") == "bb");

    cout << "tests is passed!" << endl;

    return 0;
}
