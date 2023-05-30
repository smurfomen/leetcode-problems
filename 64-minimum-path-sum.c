#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>

#include <limits>
using namespace std;

/*
        Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

        Note: You can only move either down or right at any point in time.


        1	3	1
        1	5	1
        4	2	1

        Example 1:
                Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
                Output: 7
                Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

        Example 2:
                Input: grid = [[1,2,3],[4,5,6]]
                Output: 12


        Constraints:
                m == grid.length
                n == grid[i].length
                1 <= m, n <= 200
                0 <= grid[i][j] <= 200
*/


/*
    Time Complexity:   O(N^2)

    Space Complexity:  O(1)
*/
class SolutionWithoutCache {
public:
    int impl(int r, int c, int rc, int cc, vector<vector<int>>& grid) {
        /* if r or c out of range valid indexes then return maximum int value */
        if(r > rc - 1  || r < 0 || c < 0 || c > cc - 1)
            return numeric_limits<int>::max();

        /* if r and c is coordinate of bottom right cell then return this cell value from dp */
        if(r == rc - 1 && c == cc - 1)
            return grid[r][c];

        /* walk right and find minimum recursively */
        int right = impl(r, c+1, rc, cc, grid);

        /* walk down and find minimum recursively */
        int down = impl(r+1, c, rc, cc, grid);

        /* return current cell and minimum from right and down journeys */
        return grid[r][c] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        return impl(0, 0, grid.size(), grid[0].size(), grid);
    }
};



/*
    Time Complexity: O(N)

    Space Complexity: O(N)
*/
class Solution {
public:
    int impl(int r, int c, const int & rc, const int & cc, vector<vector<int>>& grid, vector<vector<int>>& cache) {
        /* if r and c is coordinate of bottom right cell then return this cell value from dp */
        if(r == rc - 1 && c == cc - 1)
            return cache[r][c] = grid[r][c];

        /* if this coordinate already was calculated and cached then return this coordinate */
        if(cache[r][c] != -1)
            return cache[r][c];

        int sum = numeric_limits<int>::max();

        /* walk right and find minimum recursively */
        if(c + 1 < cc)
            sum = impl(r, c+1, rc, cc, grid, cache);

        /* walk down and find minimum recursively */
        if(r + 1 < rc)
            sum = min(sum, impl(r + 1, c, rc, cc, grid, cache));

        /* return current cell and minimum from right and down journeys */
        return cache[r][c] = grid[r][c] + sum;
    }

    int minPathSum(vector<vector<int>>& grid) {
        /* cache for already calculated elements */
        vector<vector<int>> cache (grid.size(), vector<int>(grid[0].size(), -1));

        return impl(0, 0, grid.size(), grid[0].size(), grid, cache);
    }
};

int main() {
    Solution sol;

    {
        vector<vector<int>> m = {{1,3,1},{1,5,1},{4,2,1}};
        assert(sol.minPathSum(m) == 7);
    }

    {
        vector<vector<int>> m = {{1,2,3},{4,5,6}};
        assert(sol.minPathSum(m) == 12);
    }
    return 0;

}















