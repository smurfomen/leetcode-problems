#include <string>
#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

    Example 1:
        Input: nums = [0,1]
        Output: 2
        Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

    Example 2:
        Input: nums = [0,1,0]
        Output: 2
        Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.


    Constraints:
        1 <= nums.length <= 105
        nums[i] is either 0 or 1.
*/


class Solution {
public:
    int findMaxLength(const vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int maxl = 0; int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i] ? 1 : -1;

            // equial 0 and 1 without holes
            if(sum == 0)
                maxl = max(maxl, i+1);

            // POV: that sum already exist. Difference of current i and prev index of that sum is new length
            else if(mp.count(sum))
                maxl = max(maxl, i - mp[sum]);

            // fix new index presum
            else
                mp[sum] = i;
        }

        return maxl;
    }
};


int main(int argc, char * argv[]) {
    Solution sol;

    assert(sol.findMaxLength({0,1}) == 2);
    assert(sol.findMaxLength({0,1,0}) == 2);
    assert(sol.findMaxLength({0,1,0,1}) == 4);
    assert(sol.findMaxLength({0,0,1,1}) == 4);
    assert(sol.findMaxLength({0,0,1,0,0,0,1,1}) == 6);

    cout << "tests is passed!" << endl;

    return 0;
}
