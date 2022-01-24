#include <string>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

/*
    Given a string s consisting of some words separated by some number of spaces, return the length of the last word in the string.
    A word is a maximal substring consisting of non-space characters only.

    Example 1:
    Input: s = "Hello World"
    Output: 5
    Explanation: The last word is "World" with length 5.

    Example 2:
    Input: s = "   fly me   to   the moon  "
    Output: 4
    Explanation: The last word is "moon" with length 4.

    Example 3:
    Input: s = "luffy is still joyboy"
    Output: 6
    Explanation: The last word is "joyboy" with length 6.

    Constraints:
    1 <= s.length <= 104

    s consists of only English letters and spaces ' '.
    There will be at least one word in s.
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        int l = 0;
        for(auto ch : s) {
            if(ch == ' ') {
                if(l)
                    break;
            }
            else
                l++;
        }

        return l;
    }
};


int main(int argc, char * argv[]) {
    Solution sol;

    assert(sol.lengthOfLastWord("Hello World") == 5);
    assert(sol.lengthOfLastWord("   fly me   to   the moon  ") == 4);
    assert(sol.lengthOfLastWord("luffy is still joyboy") == 6);
    assert(sol.lengthOfLastWord("qwerty qz qww z qwertyu qwer") == 4);

    cout << "tests is passed!" << endl;

    return 0;
}
