#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
        Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

        Example 1:
                Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
                Output: [[1,6],[8,10],[15,18]]
                Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

        Example 2:
                Input: intervals = [[1,4],[4,5]]
                Output: [[1,5]]
                Explanation: Intervals [1,4] and [4,5] are considered overlapping.


        Constraints:
                1 <= intervals.length <= 10^4
                intervals[i].length == 2
                0 <= start i <= end i <= 10^4
*/



class Solution {
public:

    /*

      Time Complexity: O(n) + O(n log n)

      Space Complexity: O(1) exclude result couse result will be allocated any way

    */
    vector<vector<int>> merge(vector<vector<int>> intervals) {

        /* sort intervals by first indexes */
        sort(intervals.begin(), intervals.end(),[](vector<int> & a, vector<int> & b) { return a[0] < b[0]; });

        /* couse intervals minimum size is 1 then push first interval to result */
        vector<vector<int>> result = { intervals.front() };

        for(int i = 1; i < intervals.size(); ++i) {
            /* if last digit in last appended interval greater or equial then first digit current interval then need merge this intervals */
            if(result.back()[1] >= intervals[i][0]) {

                /* if intervals[i] is not subinterval last appended interval then merge */
                if(intervals[i][1] > result.back()[1])
                    result.back()[1] = intervals[i][1];
            }
            else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    auto print = [](vector<vector<int>> v) {
        for(auto i : v) {
            cout << "[ ";
            for(auto j : i) {
                cout << j << " ";
            }

            cout << "] ";
        }

        cout << endl;
    };

    print(sol.merge({{1,3},{2,6},{8,10},{15,18}}));

    print(sol.merge({{1,4},{4,5}}));


    return 0;
}
