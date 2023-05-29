#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
        Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

        Example 1:
                Input: nums = [1,1,2]
                Output: [[1,1,2], [1,2,1], [2,1,1]]

        Example 2:
                Input: nums = [1,2,3]
                Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

        Constraints:
                1 <= nums.length <= 8
                -10 <= nums[i] <= 10
*/


class Solution {
public:

    /* for use this nums must be sorted, nums is NOT reference - IS A COPY */
    /* at end nums will be reversed for ex: 1,2,3 -> 3,2,1 couse at every iteration we swaps current index element with every next */

    void impl(int idx, vector<int> nums, vector<vector<int>> & result) {
        /* if idx out of range nums it seems like we can push current nums sequence into result */
        if(idx == nums.size()) {
            result.push_back(nums);
            return;
        }

        /* go forward from idx and swap elements*/
        for(int i = idx; i < nums.size(); ++i) {
            /* skip ith element if it is not first iteration and ith and idx equial couse we need only unique sequences */
            if(i != idx && nums[i] == nums[idx])
                continue;

            /* swap ith and idx element for take all variations candidate with idx element */
            /* on first iteration swap do nothing couse i == idx */
            swap(nums[idx], nums[i]);

            /* go recursion for current sequence from current idx+1 (idx can be swapped with ith)  */
            impl(idx + 1, nums, result);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        impl(0, nums, result);

        return result;
    }
};

int main() {
    Solution sol;

    auto print = [](vector<vector<int>> r) {
        for(auto i : r) {
            cout << "[ ";
            for(auto j : i) {
                cout << j << " ";
            }
            cout << "] " ;
        }
        cout << endl;
    };



    print(sol.permuteUnique({1,1,2}));
    print(sol.permuteUnique({1,2,3}));
    print(sol.permuteUnique({0,1}));
    print(sol.permuteUnique({1}));
    print(sol.permuteUnique({3,3,0,3}));

    return 0;
}
