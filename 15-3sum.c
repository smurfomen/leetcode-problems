#include <string>
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
    Notice that the solution set must not contain duplicate triplets.

    Example 1:
        Input: nums = [-1,0,1,2,-1,-4]
        Output: [[-1,-1,2],[-1,0,1]]

    Example 2:
        Input: nums = []
        Output: []

    Example 3:
        Input: nums = [0]
        Output: []

    Constraints:
        0 <= nums.length <= 3000
        -10^5 <= nums[i] <= 10^5
*/
#include <set>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> nums) {
        int n = nums.size();

        set<vector<int>> result;
        vector<int> marks(nums.size(), 0);
        if(n >= 3)
        {
            sort(nums.begin(), nums.end());

            for(int i = 0; i < n; ++i) {
                int lo = i + 1;

                int hi = n - 1;

                while(lo < hi) {
                    int sum = nums[i] + nums[lo] + nums[hi];

                    if(sum == 0)
                    {
                        vector<int> triplet = {nums[i], nums[lo], nums[hi]};
                        result.insert(triplet);

                        int clo = nums[lo];
                        while(lo < hi && nums[lo] == clo) lo++;
                    }
                    else if(sum < 0)
                        lo++;
                    else
                        hi--;
                }
            }
        }

        vector<vector<int>> r;

        for(auto it : result) {
            r.push_back(it);
        }

        return r;
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


    cout << to_str(sol.threeSum({-1,0,1,2,-1,-4})) << endl;

    cout << to_str(sol.threeSum({0,0,0})) << endl;


    cout << "tests is passed!" << endl;

    return 0;
}
