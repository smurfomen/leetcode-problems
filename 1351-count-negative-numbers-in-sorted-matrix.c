#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
        Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.


        Example 1:
                Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
                Output: 8
                Explanation: There are 8 negatives number in the matrix.

        Example 2:
                Input: grid = [[3,2],[1,0]]
                Output: 0


        Constraints:
                m == grid.length
                n == grid[i].length
                1 <= m, n <= 100
                -100 <= grid[i][j] <= 100
*/



class Solution {
public:

    /*

      Time Complexity: O(m * n)

      Space Complexity: O(1)

    */
    int countNegativesLinear(vector<vector<int>> grid) {
        int result = 0;
        for(auto & r : grid) {
            auto it = r.rbegin();
            auto end = r.rend();
            for(;it != end;++it) {
                if(*it > 0) {
                    break;
                }
                result++;
            }
        }

        return result;
    }


    /*

      Time Complexity: O(m * log n)

      Space Complexity: O(1)

    */
    int countNegatives(vector<vector<int>> grid) {
        int result = 0;
        for(auto & row : grid) {
            int l = 0;
            int r = row.size() - 1;

            /* find index first negative element using binary search cause we know that in constraints rows are sorted by decrease order */
            while(l <= r) {
                int mid = (l+r)/2;

                if(row[mid] < 0)
                    r = mid - 1;

                else
                    l = mid + 1;
            }

            result += row.size() - l;
        }

        return result;
    }
};



int main() {
    Solution sol;
    assert(sol.countNegatives({{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}}) == 8);
    assert(sol.countNegatives({{3,2},{1,0}}) == 0);
    assert(sol.countNegatives({{3,-1},{0,-2}}) == 2);

    return 0;
}
