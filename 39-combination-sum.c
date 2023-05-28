#include <cassert>
#include <vector>
#include <iostream>

using namespace std;

/*
            Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target.
            You may return the combinations in any order.

            The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the
            frequency of at least one of the chosen numbers is different.

            The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.



            Example 1:
                    Input: candidates = [2,3,6,7], target = 7
                    Output: [[2,2,3],[7]]
                    Explanation:
                    2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
                    7 is a candidate, and 7 = 7.
                    These are the only two combinations.

            Example 2:
                    Input: candidates = [2,3,5], target = 8
                    Output: [[2,2,2,2],[2,3,3],[3,5]]

            Example 3:
                    Input: candidates = [2], target = 1
                    Output: []


            Constraints:
                    1 <= candidates.length <= 30
                    2 <= candidates[i] <= 40
                    All elements of candidates are distinct.
                    1 <= target <= 40
*/


class Solution {
public:

    void impl(int idx, vector<int> & candidates, vector<int> & variants, int target, vector<vector<int>> & result) {
        /* if target is completed - push current variants set to result and return */
        if(target == 0) {
            result.push_back(variants);
            return;
        }

        /* if idx outer range - return */
        if(idx == candidates.size()) {
            return ;
        }

        /* if current candidate less or equial than needed target - we watch on it */
        /* otherwise (target - candidate) < 0 and we can go to next candidate */
        if(candidates[idx] <= target) {

            /* only if (target - current candidate) greater or equial than 0 we can continue search */
            variants.push_back(candidates[idx]);

            /* decrease target for next frame */
            impl(idx, candidates, variants, target - candidates[idx], result);
            variants.pop_back();
        }

        /* right now variants not including current idx element, and we go to next variations without current element */

        /* go to next candidate, couse we need all variants with all candidates */
        impl(idx + 1, candidates, variants, target, result);
    }


    vector<vector<int>> combinationSum(vector<int> candidates, int target) {
        vector<int> variants;
        vector<vector<int>> result;

        /* cut all candidates which greater than target couse we now that all candidates is positive */
        {
            int i = candidates.size() - 1;
            for(; i >= 0; --i) {
                if(candidates[i] <= target)
                    break;
            }
            candidates.erase(candidates.begin() + i + 1, candidates.end());
        }

        impl(0, candidates, variants, target, result);

        return result;
    }
};


int main() {
    Solution sol;

    auto print = [](vector<vector<int>> r0) {
        for(auto i : r0) {
            cout << " { ";
            for(auto j : i) {
                cout << j << " ";
            }
            cout << "} ";
        }
        cout << endl;
    };

    print(sol.combinationSum({2,3,6,7,9}, 7));

    print(sol.combinationSum({2,3,5}, 8));

    print(sol.combinationSum({2,3,5}, 9));

    print(sol.combinationSum({2,2,3,5}, 9));

    return 0;
}
