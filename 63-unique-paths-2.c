#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


/*
        You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]).
        The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
        The robot can only move either down or right at any point in time.

        An obstacle and space are marked as 1 or 0 respectively in grid.
        A path that the robot takes cannot include any square that is an obstacle.

        Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

        The testcases are generated so that the answer will be less than or equal to 2 * 109.



        Example 1:
                Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
                Output: 2
                Explanation: There is one obstacle in the middle of the 3x3 grid above.
                There are two ways to reach the bottom-right corner:
                1. Right -> Right -> Down -> Down
                2. Down -> Down -> Right -> Right

        Example 2:
                Input: obstacleGrid = [[0,1],[0,0]]
                Output: 1


        Constraints:
                m == obstacleGrid.length
                n == obstacleGrid[i].length
                1 <= m, n <= 100
                obstacleGrid[i][j] is 0 or 1.
*/





/*

  Time Complexity: O(n)
  Space Complexity: O(n)

*/
class Solution_Space_On {
public:

    int impl(int r, int c, int rc, int cc, vector<vector<int>> & dp, vector<vector<int>> & obstacleGrid) {
        if(r > rc - 1 || c > cc - 1)
            return 0;

        if(obstacleGrid[r][c] == 1)
            return 0;

        if(r == rc - 1 && c == cc - 1)
            return 1;

        if(dp[r][c] != -1)
            return dp[r][c];

        int right = impl(r, c+1, rc, cc, dp, obstacleGrid);
        int down = impl(r+1, c, rc, cc, dp, obstacleGrid);

        dp[r][c] = right + down;

        return dp[r][c];
    }

    int uniquePathsWithObstacles(vector<vector<int>> obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1])
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return impl(0,0,m,n,dp,obstacleGrid);
    }
};



/*

  Time Complexity: O(n)
  Space Complexity: O(1)

*/
class Solution {
public:

    int impl(int r, int c, int rc, int cc, vector<vector<int>> & og) {
        /* if row or column out of range then return 0 */
        if(r > rc - 1 || c > cc - 1)
            return 0;

        /* if current cell contain obstacle then return 0 also */
        if(og[r][c] == 1)
            return 0;

        /* if current cell is bottom right cell then return 1 */
        if(r == rc - 1 && c == cc - 1)
            return -1;

        /* if current sum paths through this cell already cached in og then return cached */
        if(og[r][c] < 0)
            return og[r][c];

        /* right sum unique paths - negative number */
        int right = impl(r, c+1, rc, cc, og);

        /* left sum unique paths - negative number */
        int down = impl(r+1, c, rc, cc, og);

        /* cache result for this cell using negative integers couse og also contains obstacles marked positive 1 */
        return og[r][c] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>> obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return abs(impl(0,0,m,n,obstacleGrid));
    }
};



int main() {
    Solution sol;

    assert(sol.uniquePathsWithObstacles({{0,0,0,0},{0,1,0,0},{0,0,0,0},{0,0,1,0},{0,0,0,0}}) == 7);

    assert(sol.uniquePathsWithObstacles({{0,0,0},{0,1,0},{0,0,0}}) == 2);
    assert(sol.uniquePathsWithObstacles({{0,1},{0,0}}) == 1);
    assert(sol.uniquePathsWithObstacles({{0,0},{0,1}}) == 0);

    return 0;
}
