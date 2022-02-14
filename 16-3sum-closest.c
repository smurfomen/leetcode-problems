#include <string>
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

    Return the sum of the three integers.

    You may assume that each input would have exactly one solution.

    Example 1:
        Input: nums = [-1,2,1,-4], target = 1
        Output: 2
        Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

    Example 2:
        Input: nums = [0,0,0], target = 1
        Output: 0

    Constraints:
        3 <= nums.length <= 1000
        -1000 <= nums[i] <= 1000
        -10^4 <= target <= 10^4
*/
#include <set>

class Solution {
public:
    int threeSumClosest(vector<int> nums, int target) {
        int n = nums.size();

        int result = 0;
        vector<int> marks(nums.size(), 0);
        if(n >= 3)
        {
            sort(nums.begin(), nums.end());
            result = nums[0] + nums[1] + nums[2];

            for(int i = 0; i < n; ++i) {
                int lo = i + 1;

                int hi = n - 1;

                while(lo < hi) {
                    int sum = nums[i] + nums[lo] + nums[hi];

                    result = abs(sum - target) < abs(result - target) ? sum : result;

                    if(sum >= target)
                        hi--;
                    else
                        lo++;
                }
            }
        }

        return result;
    }
};


int main(int argc, char * argv[]) {
    Solution sol;

    assert(sol.threeSumClosest({-1,2,1,4}, 1) == 2);

    assert(sol.threeSumClosest({0,0,0}, 1) == 0);

    assert(sol.threeSumClosest({-3,0,1,2}, 1) == 0);

    cout << sol.threeSumClosest({-3,1,1,3,4,5}, 1) << endl;

    cout << "tests is passed!" << endl;

    return 0;
}
