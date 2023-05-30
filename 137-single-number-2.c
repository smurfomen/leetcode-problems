#include <cassert>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

/*
            Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

            You must implement a solution with a linear runtime complexity and use only constant extra space.


            Example 1:
                    Input: nums = [2,2,3,2]
                    Output: 3

            Example 2:
                    Input: nums = [0,1,0,1,0,1,99]
                    Output: 99


            Constraints:
                    1 <= nums.length <= 3 * 104
                    -231 <= nums[i] <= 231 - 1
                    Each element in nums appears exactly three times except for one element which appears once.
*/



/*

  Time Complexity: O(2n)

  Space Complexity: O(n)

*/
class SolutionMap {
public:

    int singleNumber(vector<int> nums) {
        unordered_map<int, int> s;

        for(auto i : nums)
            s[i]++;

        for(auto & p : s) {
            if(p.second == 1)
                return p.first;
        }

        return -1;
    }
};




/*

  Time Complexity: O(n)

  Space Complexity: O(1)

*/
class Solution {
public:

    /*
       Couse from constraints we know, that each element in the array appears twice except for one element which appears only once
       then we can use XOR

       f.e.:
       [ 0110, 0110, 1000, 0110 ]

       ones = (0000 ^ 0110) & 1111 = 0110
       twos = (0000 ^ 0110) & 1001 = 0000

       ones = (0110 ^ 0110) & 1111 = 0000
       twos = (0000 ^ 0110) & 1111 = 0110

       ones = (0000 ^ 1000) & 1001 = 1000
       twos = (0110 ^ 1000) & 0111 = 0110

       ones = (1000 ^ 0110) & 1001 = 1000
       twos = (0110 ^ 0110) & 0111 = 0000


       result: last ones = 1000
    */
    int singleNumber(vector<int> nums) {
        int ones = 0;
        int twos = 0;

        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }

        return ones;
    }
};



int main() {
    Solution sol;

    assert(sol.singleNumber({4,1,2,1,2}) == 4);
    assert(sol.singleNumber({2,2,1}) == 1);
    assert(sol.singleNumber({1}) == 1);


    return 0;
}
