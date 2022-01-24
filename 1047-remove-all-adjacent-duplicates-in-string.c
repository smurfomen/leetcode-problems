#include <string>
#include <cassert>
#include <iostream>

using namespace std;

/*
    You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
    We repeatedly make duplicate removals on s until we no longer can.
    Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

    Example 1:
    Input: s = "abbaca"
    Output: "ca"
    Explanation:
    For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

    Example 2:
    Input: s = "azxxzy"
    Output: "ay"

    Constraints:
    1 <= s.length <= 105
    s consists of lowercase English letters.
*/
class Solution {
public:
    string removeDuplicates(string s) {
        for(int i = 0; i < s.size();)
        {
            if(i > 0)
            {
                char cur = s[i];
                char prev = s[i-1];
                if(cur == prev)
                {
                    s.erase(i-1, 2);
                    i--;
                    continue;
                }
            }
            i++;
        }

        return s;
    }
};


int main(int argc, char * argv[]) {
    Solution sol;

    assert(sol.removeDuplicates("abbaca") == "ca");
    assert(sol.removeDuplicates("azxxzy") == "ay");
    assert(sol.removeDuplicates("abccabc") == "ababc");


    cout << "tests is passed!" << endl;

    return 0;
}
