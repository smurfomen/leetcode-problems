#include <string>
#include <cassert>
#include <iostream>

using namespace std;

/*
    We define the usage of capitals in a word to be right when one of the following cases holds:

    All letters in this word are capitals, like "USA".
    All letters in this word are not capitals, like "leetcode".
    Only the first letter in this word is capital, like "Google".
    Given a string word, return true if the usage of capitals in it is right.

    Example 1:
    Input: word = "USA"
    Output: true

    Example 2:
    Input: word = "FlaG"
    Output: false

    Constraints:
    1 <= word.length <= 100

    word consists of lowercase and uppercase English letters.
*/
class Solution {
public:
    bool detectCapitalUse(string word) {
        for(int i = 1; i < word.size(); ++i)
        {
            char ch = word[i];
            if(!(isupper(word[i-1]) == isupper(ch) || (!isupper(ch) && i-1 == 0)))
               return false;
        }

        return true;
    }
};


int main(int argc, char * argv[]) {
    Solution sol;

    assert(sol.detectCapitalUse("USA"));
    assert(!sol.detectCapitalUse("FlaG"));
    assert(sol.detectCapitalUse("g"));
    assert(sol.detectCapitalUse("ggg"));
    assert(sol.detectCapitalUse("Leetcode"));

    cout << "tests is passed!" << endl;

    return 0;
}
