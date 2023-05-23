#include <string>
#include <cassert>
#include <algorithm>
#include <stack>
using namespace std;

/*
        Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses
        substring

        Example 1:
                Input: s = "(()"
                Output: 2
                Explanation: The longest valid parentheses substring is "()".

        Example 2:
                Input: s = ")()())"
                Output: 4
                Explanation: The longest valid parentheses substring is "()()".

        Example 3:
                Input: s = ""
                Output: 0

        Constraints:
                0 <= s.length <= 3 * 104
                s[i] is '(', or ')'.
*/


/* time O(N) space O(N) */
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;

        /* top stask element - last index invalid paren */
        st.push(-1);

        int result = 0;
        int size = s.size();
        /* go forward begins valid open paren */
        for(int i = 0; i < size; ++i) {
            if(s[i] == '(') st.push(i);

            else
            {
                /* we can pop safety, couse before begin push(-1) to stack. -1 just will be replaced to i, couse current i invalid if stack contains only 1 element */
                st.pop();

                if(st.empty())
                    st.push(i);

                else
                {
                    /* if stack contain any elements after pop - just calc current valid len after last invalid paren. */
                    /* last invalid paren index - top stack element. if its -1 it will be i - (-1), like i+1 */
                    int l = i - st.top();
                    result = std::max(result, l);
                }
            }
        }

        return result;
    }
};


int main() {
    Solution sol;

    assert(sol.longestValidParentheses("(()()") == 4);
    assert(sol.longestValidParentheses("((((()()()") == 6);
    assert(sol.longestValidParentheses("((((()()())") == 8);
    assert(sol.longestValidParentheses(")))((((()()())") == 8);

    assert(sol.longestValidParentheses("()))") == 2);

    assert(sol.longestValidParentheses(")()())") == 4);


    return 0;
}
