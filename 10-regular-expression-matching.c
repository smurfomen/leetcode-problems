#include <string>
#include <cassert>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/*
    Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

    '.' Matches any single character.​​​​
    '*' Matches zero or more of the preceding element.
    The matching should cover the entire input string (not partial).

    Example 1:
        Input: s = "aa", p = "a"
        Output: false
        Explanation: "a" does not match the entire string "aa".

    Example 2:
        Input: s = "aa", p = "a*"
        Output: true
        Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

    Example 3:
        Input: s = "ab", p = ".*"
        Output: true
        Explanation: ".*" means "zero or more (*) of any character (.)".


    Constraints:
        1 <= s.length <= 20
        1 <= p.length <= 30
        s contains only lowercase English letters.
        p contains only lowercase English letters, '.', and '*'.
        It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
*/
class Solution {
public:
    bool isMatch(string s, string p)
    {
        int slen = s.length(), plen = p.length();
        vector<vector<bool>> dp (slen + 1, vector<bool>(plen + 1, false));
        dp[slen][plen] = true;
        for (int i = slen; i >= 0; --i) {
            for (int j = plen - 1; j >= 0; --j) {
                bool matched = i < slen && (s[i] == p[j] || p[j] == '.');
                if (j + 1 < plen && p[j + 1] == '*')
                    dp[i][j] = matched && dp[i + 1][j] || (dp[i][j + 2]);
                else if (matched)
                    dp[i][j] = dp[i + 1][j + 1];
            }
        }
        return dp[0][0];
    }
};


int main(int argc, char * argv[]) {
    Solution sol;

    assert(!sol.isMatch("aa", "a"));
    assert(sol.isMatch("aa", "a*"));
    assert(sol.isMatch("ab", ".*"));
    assert(sol.isMatch("aab", "c*a*b"));
    assert(!sol.isMatch("ab", ".*c"));
    assert(sol.isMatch("aaa", "a*a"));

    cout << "tests is passed!" << endl;

    return 0;
}
