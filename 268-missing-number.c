#include <cassert>
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

/*
            Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.


            Example 1:
                    Input: nums = [3,0,1]
                    Output: 2
                    Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

            Example 2:
                    Input: nums = [0,1]
                    Output: 2
                    Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

            Example 3:
                    Input: nums = [9,6,4,2,3,5,7,0,1]
                    Output: 8
                    Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.


            Constraints:
                    n == nums.length
                    1 <= n <= 104
                    0 <= nums[i] <= n
                    All the numbers of nums are unique.
*/



/*

  Time Complexity: O(n)

  Space Complexity: O(1)

*/
class Solution {
public:
        int missingNumber(vector<int> nums) {
                /*
                   couse we know that 0 <= nums[i] <= nums.length and all numbers unique
                   nums.length * (nums.length + 1) / 2 + sum(nums) its missing number
                   Ex: 3,0,1 -> 3 * 4 / 2 - (3 + 0 + 1) = 12 / 2 - 4 = 2
                */
                return nums.size() * (nums.size() + 1) / 2 - std::accumulate(nums.begin(), nums.end(), 0);
        }
};


int main() {
        Solution sol;

        assert(sol.missingNumber({3,0,1}) == 2);
        assert(sol.missingNumber({0,1}) == 2);
        assert(sol.missingNumber({9,6,4,2,3,5,7,0,1}) == 8);

        return 0;
}
