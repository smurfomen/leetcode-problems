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


/* time O(N) space O(N*2) */
class Solution_NonOptimized {
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



/* time O(N) space O(1)*/
class Solution {
public:
    int next_idx(const string & s, int i) {
        int skip = 0;
        while(i >= 0) {
            /* if current # - add to skip */
            if(s[i] == '#')
                skip++;

            /* if valid but skip > 0 - skip symbol*/
            else if(skip > 0)
                skip--;

            /* if skip < 1 - break */
            else
                break;

            i--;
        }

        return i;
    }

    /* time O(N) space O(1)*/
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;

        /* go from last idx to begin idx */
        for(;i >= 0 || j >= 0; --i, --j) {
            i = next_idx(s, i);
            j = next_idx(t, j);

            /* if i and j < 0 - they begins 0 in one time - strings ended */
            if(i < 0 && j < 0)
                return true;

            /* if i or j begins 0  - one of them ends first*/
            if(i < 0 || j < 0)
                return false;

            /* if symbols not equial - strings not equials, not reasons to continue */
            if(s[i] != t[j])
                return false;
        }

        return true;
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
