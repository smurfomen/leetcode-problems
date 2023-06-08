#include <cassert>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


/*
        Given two strings s and t, determine if they are isomorphic.

        Two strings s and t are isomorphic if the characters in s can be replaced to get t.

        All occurrences of a character must be replaced with another character while preserving the order of characters.
        No two characters may map to the same character, but a character may map to itself.



        Example 1:
                Input: s = "egg", t = "add"
                Output: true

        Example 2:
                Input: s = "foo", t = "bar"
                Output: false

        Example 3:
                Input: s = "paper", t = "title"
                Output: true


        Constraints:
                1 <= s.length <= 5 * 10^4
                t.length == s.length
                s and t consist of any valid ascii character.
*/



class Solution {
public:

    /*

      Time Complexity: O(n)

      Space Complexity: O(2n) -> O(n)

    */
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;

        for(int i = 0; i < s.size(); ++i) {
            char c1 = s[i];
            char c2 = t[i];
            if(!m1.count(c1) && !m2.count(c2)) {
                m1.insert({c1, c2});
                m2.insert({c2, c1});
            }

            else if (m1[c1] != c2 || m2[c2] != c1)
                return false;
        }

        return true;
    }
};



int main() {
    Solution sol;

    assert(sol.isIsomorphic("egg", "add") == true);
    assert(sol.isIsomorphic("foo", "bar") == false);
    assert(sol.isIsomorphic("paper", "title") == true);
    assert(sol.isIsomorphic("badc", "baba") == false);

    return 0;
}
