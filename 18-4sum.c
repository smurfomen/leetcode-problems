#include <string>
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
        Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
                0 <= a, b, c, d < n
                a, b, c, and d are distinct.
                nums[a] + nums[b] + nums[c] + nums[d] == target
        You may return the answer in any order.


        Example 1:
                Input: nums = [1,0,-1,0,-2,2], target = 0
                Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

        Example 2:
                Input: nums = [2,2,2,2,2], target = 8
                Output: [[2,2,2,2]]


        Constraints:
                1 <= nums.length <= 200
                -109 <= nums[i] <= 109
                -109 <= target <= 109
*/

class Solution1 {
public:
    vector<vector<int>> impl(vector<int> candidates, vector<int> & nums, const int idx, const int target) {
        if(candidates.size() == 4 && std::accumulate(candidates.begin(), candidates.end(), 0) == target)
            return vector<vector<int>> { { candidates } };

        vector<vector<int>> result;

        for(int i = idx; i < nums.size(); ++i) {
            vector<int> candidates_with = candidates;
            candidates_with.push_back(nums[i]);

            auto r = impl(candidates_with, nums, i + 1, target);

            for(auto it : r) {
                result.push_back(it);
            }
        }

        return result;
    }

    vector<vector<int>> fourSum(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());
        auto vec = impl({}, nums, 0, target);

        sort( vec.begin(), vec.end() );
        vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
        return vec;
    }
};













class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int> nums, int target) {
        if(nums.size() < 4)
            return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        int ns = nums.size();
        for(int i = 0; i < ns; ++i) {
            for(int j = i + 1; j < ns; ++j) {
                int left = j + 1;
                int right = ns - 1;

                long long sum = 0;

                while(left < right) {
                    sum = static_cast<long long>(nums[i]) + static_cast<long long>(nums[j]) + static_cast<long long>(nums[left]) + static_cast<long long>(nums[right]);

                    if(sum == target)
                    {
                        result.push_back({nums[i], nums[j], nums[left++], nums[right--]});
                    }

                    else if(sum < target) {
                        ++left;
                    }
                    else
                        --right;
                }
            }
        }

        sort(result.begin(), result.end());
        result.erase( unique( result.begin(), result.end() ), result.end() );


        return result;
    }
};








class Solution {
public:

    /* skip before unique when increment index */
    void inc(const vector<int> & nums, int& n){
        int ns = nums.size();
        while(++n < ns && nums[n] == nums[n - 1]);
    }


    /* skip before unique when decrement index */
    void dec(const vector<int> & nums, int& n){
        while(--n >= 0 && nums[n] == nums[n + 1]);
    }

    vector<vector<int>> fourSum(vector<int> nums, int target) {
        if(nums.size() < 4)
            return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        int ns = nums.size();
        for(int i = 0; i < ns; inc(nums, i)) {
            for(int j = i + 1; j < ns; inc(nums, j)) {
                int left = j + 1; // left after j
                int right = ns - 1; // right last index

                while(left < right) {
                    long long sum = static_cast<long long>(nums[i]) + static_cast<long long>(nums[j]) + static_cast<long long>(nums[left]) + static_cast<long long>(nums[right]);

                    if(sum == target)
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        inc(nums, left);
                        dec(nums, right);
                    }

                    /* if sum > target then decrement right index couse nums is sorted */
                    else if(sum > target) {
                        dec(nums, right);
                    }

                    /* if sum < target then increment left index couse nums is sorted */
                    else
                        inc(nums, left);
                }
            }
        }

        return result;
    }
};





int main(int argc, char * argv[]) {
    Solution sol;

    auto to_str = [](vector<vector<int>> vv){
        string s;
        s.append("{ ");
        for(int k = 0; k < vv.size(); ++k) {
            if(k != 0)
                s.append(", ");

            s.append("{ ");

            auto & v = vv[k];
            for(int i = 0; i < v.size(); ++i) {
                if(i != 0)
                    s.append(", ");

                s.append(to_string(v[i]));
            }
            s.append(" }");
        }
        s.append(" }");

        return s;
    };


    cout << to_str(sol.fourSum({1,1,2,0, -2, 4}, 4)) << endl;

    cout << to_str(sol.fourSum({1,0,-1,0,-2,2}, 0)) << endl;
    cout << to_str(sol.fourSum({1000000000,1000000000,-1000000000,-1000000000}, 0)) << endl;

    return 0;
}
