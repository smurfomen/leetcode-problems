#include <string>
#include <cassert>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

/*
    The numeric value of a lowercase character is defined as its position (1-indexed) in the alphabet, so the numeric value of a is 1, the numeric value of b is 2, the numeric value of c is 3, and so on.

    The numeric value of a string consisting of lowercase characters is defined as the sum of its characters' numeric values. For example, the numeric value of the string "abe" is equal to 1 + 2 + 5 = 8.
    You are given two integers n and k. Return the lexicographically smallest string with length equal to n and numeric value equal to k.

    Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.



    Example 1:
        Input: n = 3, k = 27
        Output: "aay"
        Explanation: The numeric value of the string is 1 + 1 + 25 = 27, and it is the smallest string with such a value and length equal to 3.

    Example 2:
        Input: n = 5, k = 73
        Output: "aaszz"


    Constraints:
        1 <= n <= 10^5
        n <= k <= 26 * n
*/

std::map<int, char> alpha = {
    { 1 , 'a' },
    { 2 , 'b' },
    { 3 , 'c' },
    { 4 , 'd' },
    { 5 , 'e' },
    { 6 , 'f' },
    { 7 , 'g' },
    { 8 , 'h' },
    { 9 , 'i' },
    { 10, 'j' },
    { 11, 'k' },
    { 12, 'l' },
    { 13, 'm' },
    { 14, 'n' },
    { 15, 'o' },
    { 16, 'p' },
    { 17, 'q' },
    { 18, 'r' },
    { 19, 's' },
    { 20, 't' },
    { 21, 'u' },
    { 22, 'v' },
    { 23, 'w' },
    { 24, 'x' },
    { 25, 'y' },
    { 26, 'z' }
};

class Solution {
public:
    string getSmallestString(int n, int k) {
        string result;
        while(k) {
            int weight = alpha.size();

            if(k == n) {
                weight = 1;
            }

            else if(k - (n - 1) < weight)
                weight = k - (n - 1);


            if(alpha.count(weight)) {
                result += alpha[weight];
                n--;
                k -= weight;
            }
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};


int main(int argc, char * argv[]) {
    Solution sol;

    assert(sol.getSmallestString(3, 27) == "aay");
    assert(sol.getSmallestString(5, 73) == "aaszz");
    assert(sol.getSmallestString(2,52) == "zz");
    assert(sol.getSmallestString(3,3) == "aaa");
    assert(sol.getSmallestString(2,25) == "ax");

    cout << "tests is passed!" << endl;

    return 0;
}
