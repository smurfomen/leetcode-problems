#include <string>
#include <cassert>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

/*
            Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

            A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

            Example 1:
                    Input: digits = "23"
                    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

            Example 2:
                    Input: digits = ""
                    Output: []

            Example 3:
                    Input: digits = "2"
                    Output: ["a","b","c"]


            Constraints:
                    0 <= digits.length <= 4
                    digits[i] is a digit in the range ['2', '9'].
*/


/* unoptimal recursion solution using concatenation strings and vectors */
class SolutionNonOptimal {
public:

    inline int variants(char c) {
        int d = c - '0';
        if(d > 1 && d < 10)
            return (d == 9 || d == 7 ? 4 : 3);

        return 0;
    }

    vector<string> letterCombinations(const string & digits) {
        if(digits.empty())
            return {};

        vector<string> res;

        for(int i = 0; i < variants(digits[0]); ++i) {
            int d = digits[0] - '0';
            int offset = (d == 9 ? 22 : d == 8 ? 19 : d == 7 ? 15 : (d - 2) * 3);
            char c = 'a' + offset + i;

            vector<string> letters = letterCombinations(digits.substr(1, digits.size() - 1));
            if(letters.empty())
                res.push_back(string{c});

            for(auto & l : letters) {

                res.push_back(string{c} + l);
            }
        }

        return res;
    }
};


/* more optimal recursion solution using temporary string without concatenation vectors and other strings */
class Solution {
public:
    void gen(int idx, string & digits, string & temp, vector<string> & res) {
        /* if idx already equial total digits size - exit */
        if(idx == static_cast<int>(digits.size()))
        {
            /* but if temp string is not empty dont forget push it to result */
            if(!temp.empty())
                res.push_back(temp);
        }

        /* current button number */
        int d = digits[idx] - '0';

        /* letters on current button */
        int variants = (d < 2 || d > 9) ? 0 : (d == 9 || d == 7 ) ? 4 : 3;

        /* offset from begin alphabet ('a' is 0 index) to first letter on current button */
        int offset = (d == 9 ? 22 : d == 8 ? 19 : d == 7 ? 15 : (d - 2) * 3);

        /* walk for all variants on button */
        for(int i = 0; i < variants; ++i) {

            /* real current letter value */
            char c = 'a' + offset + i;

            /* make candidate */
            temp.push_back(c);

            /* generate variants using candidate */
            gen(idx+1, digits, temp, res);

            /* remove last pushed char c from candidate for next iteration */
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string temp;
        vector<string> res;
        gen(0, digits, temp, res);
        return res;
    }
};


int main() {
    Solution sol;
    auto r0 = sol.letterCombinations("8");
    auto r1 = sol.letterCombinations("23");
    auto r2 = sol.letterCombinations("2");
    auto r3 = sol.letterCombinations("");
    auto r4 = sol.letterCombinations("239");

    return 0;
}
