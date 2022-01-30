#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Given an array, rotate the array to the right by k steps, where k is non-negative.

    Example 1:
    Input: nums = [1,2,3,4,5,6,7], k = 3
    Output: [5,6,7,1,2,3,4]
    Explanation:
    rotate 1 steps to the right: [7,1,2,3,4,5,6]
    rotate 2 steps to the right: [6,7,1,2,3,4,5]
    rotate 3 steps to the right: [5,6,7,1,2,3,4]

    Example 2:
    Input: nums = [-1,-100,3,99], k = 2
    Output: [3,99,-1,-100]
    Explanation:
    rotate 1 steps to the right: [99,-1,-100,3]
    rotate 2 steps to the right: [3,99,-1,-100]


    Constraints:
    1 <= nums.length <= 105
    -231 <= nums[i] <= 231 - 1
    0 <= k <= 105


    Follow up:
    Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
    Could you do it in-place with O(1) extra space?
*/
class Solution {
public:
        void rotate(vector<int>& nums, int k) {
            // cut k to k < nums.size()
            k = k%nums.size();

            // reverse all collection
            reverse(nums.begin(), nums.end());

            // unreverse before
            reverse(nums.begin(), nums.begin() + k);

            // unreverse other numbers after k
            reverse(nums.begin() + k, nums.end());
        }
};


int main(int argc, char * argv[]) {
    Solution sol;

    auto isEquial = [](const vector<int> & a, const vector<int> & b){
        return a == b;
    };

    {
        vector<int> v{1,2,3,4,5,6,7};
        sol.rotate(v, 3);
        assert(isEquial(v, vector<int>{5,6,7,1,2,3,4}));
    }

    {
        vector<int> v{-1, -100, 3, 99};
        sol.rotate(v, 2);
        assert(isEquial(v, vector<int>{3, 99, -1, -100}));
    }

    {
        vector<int> v{-1};
        sol.rotate(v, 2);
        assert(isEquial(v, vector<int>{-1}));
    }

    {
        vector<int> v{1,2};
        sol.rotate(v, 3);
        assert(isEquial(v, vector<int>{2,1}));
    }

    cout << "tests is passed!" << endl;

    return 0;
}
