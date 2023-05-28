#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

/*
            Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

            Each number in candidates may only be used once in the combination.

            Note: The solution set must not contain duplicate combinations.


            Example 1:
                    Input: candidates = [10,1,2,7,6,1,5], target = 8
                    Output:
                    [
                            [1,1,6],
                            [1,2,5],
                            [1,7],
                            [2,6]
                    ]

            Example 2:
                    Input: candidates = [2,5,2,1,2], target = 5
                    Output:
                    [
                            [1,2,2],
                            [5]
                    ]


            Constraints:
                    1 <= candidates.length <= 100
                    1 <= candidates[i] <= 50
                    1 <= target <= 30
*/

class Solution {
public:
    void impl(int idx, const vector<int> & candidates, vector<int> & variants, int target, vector<vector<int>> & result) {
        /* if we got valid sequence then target will be 0, if its true we can push current variants to result */
        if(target == 0) {
            result.push_back(variants);
        }

        /* if target < 0 or current index out of range candidates then return */
        if(target < 0 || idx > candidates.size()) {
            return;
        }


        /* go forward from current element to next candidates */
        for(int i = idx; i < candidates.size(); ++i) {

            /* if current candidate and previous is equial then skip current candidate couse we already got variants using with value candidate[i] */
            if(i != idx && candidates[i] == candidates[i-1]) {
                continue;
            }

            /* try find more candidates */
            variants.push_back(candidates[i]);
            impl(i+1, candidates, variants, target - candidates[i], result);
            variants.pop_back();
        }
    }


    vector<vector<int>> combinationSum2(vector<int> candidates, int target) {
        vector<vector<int>> result;
        vector<int> variants;

        /* sorted candidates is invariant */
        sort(candidates.begin(), candidates.end());

        /* start recursion searching */
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

    print(sol.combinationSum2({2,3,6,7,9}, 7));
    print(sol.combinationSum2({2,3,5}, 8));
    print(sol.combinationSum2({2,3,5}, 9));
    print(sol.combinationSum2({2,2,3,5}, 9));
    print(sol.combinationSum2({10,1,2,7,6,1,5}, 8));
    print(sol.combinationSum2({2,5,2,1,2}, 5));

    print(sol.combinationSum2({1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 30));

    return 0;

}
