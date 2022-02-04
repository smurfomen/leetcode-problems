#include <string>
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
    A subarray is a contiguous part of an array.

    Example 1:
        Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
        Output: 6
        Explanation: [4,-1,2,1] has the largest sum = 6.

    Example 2:
        Input: nums = [1]
        Output: 1

    Example 3:
        Input: nums = [5,4,-1,7,8]
        Output: 23


    Constraints:
        1 <= nums.length <= 10^5
        -10^4 <= nums[i] <= 10^4
*/
class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
        int n = nums.size();
        int result = nums[0];
        int maxr = result;
        for(int i = 1; i < n; ++i) {
            result = max(nums[i], nums[i] + result);
            maxr = max(maxr, result);
        }

        return maxr;
    }
};


int main(int argc, char * argv[]) {
    Solution sol;

    assert(sol.maxSubArray({-2,1,-3,4,-1,2,1,-5,4}) == 6);
    assert(sol.maxSubArray({1}) == 1);
    assert(sol.maxSubArray({-1}) == -1);
    assert(sol.maxSubArray({5,4,-1,7,8}) == 23);

    cout << "tests is passed!" << endl;

    return 0;
}
