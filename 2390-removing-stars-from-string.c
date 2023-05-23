#include <string>
#include <cassert>
#include <stack>

using namespace std;

/*
        Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

        Note that after backspacing an empty text, the text will continue empty.


        Example 1:
                Input: s = "ab#c", t = "ad#c"
                Output: true
                Explanation: Both s and t become "ac".

        Example 2:
                Input: s = "ab##", t = "c#d#"
                Output: true
                Explanation: Both s and t become "".

        Example 3:
                Input: s = "a#c", t = "b"
                Output: false
                Explanation: s becomes "c" while t becomes "b".


        Constraints:
                1 <= s.length, t.length <= 200
                s and t only contain lowercase letters and '#' characters.
*/


class Solution {
public:
        string handleBacks(string s) {
                string res;
                stack<char> st;

                for(auto ch : s) {
                        if(ch != '#')
                                st.push(ch);
                        else if(!st.empty())
                                st.pop();
                }

                while(!st.empty()) { res += st.top(); st.pop(); };

                return res;
        }


        bool backspaceCompare(string s, string t) {
                return handleBacks(s) == handleBacks(t);
        }
};



int main() {
        Solution sol;

        assert(sol.backspaceCompare("ab#c", "ad#c"));
        assert(sol.backspaceCompare("ab##", "c#d#"));
        assert(!sol.backspaceCompare("a#c", "b"));
        assert(!sol.backspaceCompare("bxj##tw", "bxo#j##tw"));

        return 0;
}
