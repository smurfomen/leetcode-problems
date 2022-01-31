#include <string>
#include <cassert>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
    Given a signed 32-bit integer x, return x with its digits reversed.
    If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

    Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

    Example 1:
        Input: x = 123
        Output: 321

    Example 2:
        Input: x = -123
        Output: -321

    Example 3:
        Input: x = 120
        Output: 21

    Constraints:
        -231 <= x <= 231 - 1
*/

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int ex = abs(x);

        while(ex > 0) {
            long int part = (long int)result * 10 + (ex % 10);
            if(part > numeric_limits<int>::max())
                return 0;

            result = part;
            ex /= 10;
        }
        return (x<0)? -result : result;
    }
};

int main(int argc, char * argv[]) {
    Solution sol;

    assert(sol.reverse(123) == 321);
    assert(sol.reverse(-123) == -321);
    assert(sol.reverse(120) == 21);
    assert(sol.reverse(1534236469) == 0);
    assert(sol.reverse(-2147483648) == 0);

    cout << "tests is passed!" << endl;

    return 0;
}
