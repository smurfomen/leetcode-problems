#include <string>
#include <cassert>
#include <iostream>
#include <limits>
using namespace std;

/*
    Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

    The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

    Return the quotient after dividing dividend by divisor.

    Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31, 2^31 − 1].
    For this problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, and if the quotient is strictly less than -2^31, then return -2^31.

    Example 1:
        Input: dividend = 10, divisor = 3
        Output: 3
        Explanation: 10/3 = 3.33333.. which is truncated to 3.

    Example 2:
        Input: dividend = 7, divisor = -3
        Output: -2
        Explanation: 7/-3 = -2.33333.. which is truncated to -2.


    Constraints:
        -2^31 <= dividend, divisor <= 2^31 - 1
        divisor != 0
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool negative = (dividend > 0) ^ (divisor > 0);

        int result = 0;

        if(divisor == 1)
        {
            if(dividend == std::numeric_limits<int>::min())
               return dividend;

            result = std::llabs(dividend);
        }

        else if(dividend == std::numeric_limits<int>::min() && divisor == -1) {
            return std::numeric_limits<int>::max();
        }

        else {
            long long d1 = std::llabs(dividend);

            long long d2 = std::llabs(divisor);

            long long tmp = d2;

            int cnt = d2 <= d1? 1 : 0;

            while(d1 >= tmp)
            {
                tmp = tmp << 1;
                if(d1 >= tmp)
                    cnt = cnt*2;
                else {
                    tmp = tmp >> 1;
                    break;
                }
            }

            d1 -= tmp;

            while(d1 >= d2)
            {
                d1 -= d2;
                cnt++;
            }

            result = cnt;
        }

        if(negative) {
            result = -result;
        }

        return result;
    }
};

int main(int argc, char * argv[]) {
    Solution sol;
    assert(sol.divide(10, 3) == 3);
    assert(sol.divide(-1, 1) == -1);
    assert(sol.divide(1, -1) == -1);
    assert(sol.divide(10, 5) == 2);
    assert(sol.divide(0, 5) == 0);
    assert(sol.divide(7, -3) == -2);
    assert(sol.divide(-2147483648, 1) == -2147483648);
    assert(sol.divide(-2147483648, -1) == 2147483647);
    assert(sol.divide(-2147483648, 2) == -1073741824);
    assert(sol.divide(-2147483648, 4) == -536870912);

    cout << "tests is passed!" << endl;

    return 0;
}
