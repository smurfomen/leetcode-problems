#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
        Given a triangle array, return the minimum path sum from top to bottom.

        For each step, you may move to an adjacent number of the row below.
        More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.



        Example 1:
                Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
                Output: 11
                Explanation: The triangle looks like:
                   2
                  3 4
                 6 5 7
                4 1 8 3
                The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

        Example 2:
                Input: triangle = [[-10]]
                Output: -10


        Constraints:
                1 <= triangle.length <= 200
                triangle[0].length == 1
                triangle[i].length == triangle[i - 1].length + 1
                -10^4 <= triangle[i][j] <= 10^4
*/




class Solution_Easy {
public:

    /*

      Time Complexity: O(n)
      Space Complexity: O(1)

    */
    int minimumTotal(vector<vector<int>> triangle) {
        int result = 0;

        for(auto &row : triangle) {
            result += *min_element(row.begin(), row.end());
        }

        return result;
    }
};




class Solution {
public:

    /*

      Time Complexity: O(n)
      Space Complexity: O(1)

    */
    int minimumTotal(vector<vector<int>> triangle) {
        int n = triangle.size();
        /* go from penultimate row to first row and calculate all elements behind ith element in current row */
        for(int r = n-2; r >= 0; --r) {

            /* go forward by all elements in current row and find minimum between ith element and ith + 1 on the next row,
             * next summarize this with current ith element on current row */
            for(int c = 0; c < triangle[r].size(); ++c) {
                triangle[r][c] += min(triangle[r+1][c], triangle[r+1][c+1]);
            }
        }


        /* at the end in first element in first row will be sum of minimum path from top to bottom */
        return triangle[0][0];
    }
};



int main() {
    Solution sol;
    assert(sol.minimumTotal({{2}, {3,4}, {6,5,7}, {4,1,8,3}}) == 11);
    assert(sol.minimumTotal({{-10}}) == -10);

    return 0;
}
