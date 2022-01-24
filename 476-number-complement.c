#include <string>
#include <cassert>
#include <iostream>
#include <numbers>
using namespace std;

/*
    The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

    For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
    Given an integer num, return its complement.

    Example 1:
    Input: num = 5
    Output: 2
    Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

    Example 2:
    Input: num = 1
    Output: 0
    Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

    Constraints:
    1 <= num < 231
*/
class Solution {
public:
    int findComplement(int num) {
        for(int i = 31; i >= 0; --i)
        {
            if(num & (1 << i))
            {
                for(; i >= 0; --i)
                {
                    if(num & (1 << i))
                        num &= ~(1 << i);
                    else
                        num |= (1<<i);
                }
            }
        }

        return num;
    }
};


int main(int argc, char * argv[]) {
    Solution sol;

    assert(sol.findComplement(5) == 2);
    assert(sol.findComplement(1) == 0);
    assert(sol.findComplement(105) == 22);

    cout << "tests is passed!" << endl;

    return 0;
}
