#include <string>
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
        Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
        The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

        You must write an algorithm that runs in O(n) time and without using the division operation.

        Example 1:
                Input: nums = [1,2,3,4]
                Output: [24,12,8,6]

        Example 2:
                Input: nums = [-1,1,0,-3,3]
                Output: [0,0,9,0,0]

        Constraints:
                2 <= nums.length <= 105
                -30 <= nums[i] <= 30
                The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.


        Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
*/


/* Brute Force time O(N^2) space O(N) */
class SolutionBruteForce {
public:
    vector<int> productExceptSelf(vector<int> nums) {
        int nCount = nums.size();

        vector<int> result(nCount, 1);

        for(int i = 0; i < nCount; ++i) {
            for(int j = 0; j < nCount; ++j) {
                if(i != j)
                    result[i] *= nums[j];
            }

        }

        return result;
    }
};


/* time O(N*3) space O(N*3) */
class SolutionNonOptimal {
public:
    vector<int> productExceptSelf(vector<int> nums) {
        int nCount = nums.size();

        vector<int> leftToRight(nCount, 1);
        for(int i = 1; i < nCount; ++i)
            leftToRight[i] = leftToRight[i-1] * nums[i-1];

        vector<int> rightToLeft(nCount, 1);
        for(int i = nCount-2; i >= 0; --i)
            rightToLeft[i] = rightToLeft[i+1] * nums[i+1];

        vector<int> result(nCount, 0);

        for(int i = 0; i < nCount; ++i)
            result[i] = leftToRight[i] * rightToLeft[i];

        return result;
    }
};

/* optimal time O(N*2) space O(1) */
class Solution {
public:
    vector<int> productExceptSelf(vector<int> nums) {
        int nCount = nums.size();
        vector<int> result(nCount, 1);

        /* left to right - calc product of every left then ith elements to ith element array */
        for(int i = 1; i < nCount; ++i)
            result[i] = result[i-1] * nums[i-1];


        /* accumulator for calc right to left */
        int rightaccum = 1;

        /* right to left - calc product of accumulator and ith element, couse in ith element already placed product of all left elements */
        for(int i = nCount - 1; i >= 0; --i) {
            result[i] *= rightaccum;

            /* update accum for next iteration to right - multiply on ith element from nums */
            rightaccum *= nums[i];
        }

        return result;
    }
};



int main() {
    Solution sol;

    assert((sol.productExceptSelf({1,2,3,4}) == vector<int>{24, 12, 8, 6}));
    assert((sol.productExceptSelf({-1,1,0,-3,3}) == vector<int>{0,0,9,0,0}));

    return 0;
}














