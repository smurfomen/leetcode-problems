#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
            Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.


            Example 1:
                    Input: nums = [1,2,3]
                    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

            Example 2:
                    Input: nums = [0,1]
                    Output: [[0,1],[1,0]]

            Example 3:
                    Input: nums = [1]
                    Output: [[1]]

            Constraints:
                    1 <= nums.length <= 6
                    -10 <= nums[i] <= 10
                    All the integers of nums are unique.
*/



class Solution {
public:

    void impl(int idx, vector<int> & nums, vector<vector<int>> & result) {

        /* if idx out of range nums it seems like we can push current nums sequence into result */
        if(idx == nums.size()) {
            result.push_back(nums);
            return;
        }


        /* go forward from idx and swap elements*/
        for(int i = idx; i < nums.size(); ++i) {

            /* swap ith and idx element for take all variations candidate with idx element */
            /* on first iteration swap do nothing couse i == idx */
            swap(nums[idx], nums[i]);

            /* go recursion for current sequence from current idx+1 (idx can be swapped with ith)  */
            impl(idx + 1, nums, result);

            /* swap back elements for next steps */
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int> nums) {
        vector<vector<int>> result;

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

    print(sol.permute({1,2,3}));
    print(sol.permute({0,1}));
    print(sol.permute({1}));


    return 0;
}
