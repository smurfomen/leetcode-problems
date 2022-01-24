#include <cassert>
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

    Example 1:
    Input: n = 3
    Output: ["((()))","(()())","(())()","()(())","()()()"]

    Example 2:
    Input: n = 1
    Output: ["()"]

    Constraints:
    1 <= n <= 8
*/

class Solution {
public:
    void gen(string temp, int open, int close, vector<string> & res) {
        if(open == 0 && close == 0)
        {
            res.push_back(temp);
            return;
        }
        // 1. ((()))
        // 2. (()())
        // 3. ()(())
        if(open > 0)
        {
            gen(temp + "(", open-1, close, res);
        }

        // 4. (())()
        // 5. ()()()
        if(close > open)
        {
            gen(temp + ")", open, close - 1, res);
        }
    }


    vector<string> generateParenthesis(int n) {
        vector<string> result;
        gen("", n, n, result);

        return result;
    }
};

int main(int argc, char * argv[]) {
    Solution sol;

    auto contains = [](vector<string> v, vector<string> tests) -> bool
    {
        for(auto t : tests)
        {
            if(find(v.begin(), v.end(), t) == v.end())
                return false;
        }

        return true;
    };

    assert(contains(sol.generateParenthesis(3), {"((()))","(()())","(())()","()(())","()()()"}));
    assert(contains(sol.generateParenthesis(1), {"()"}));

    cout << "tests is passed!" << endl;
    return 0;
}
