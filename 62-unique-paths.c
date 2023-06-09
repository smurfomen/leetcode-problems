#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


/*
        There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
        The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

        Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

        The test cases are generated so that the answer will be less than or equal to 2 * 109.



        Example 1:
                Input: m = 3, n = 7
                Output: 28

        Example 2:
                Input: m = 3, n = 2
                Output: 3
                Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
                1. Right -> Down -> Down
                2. Down -> Down -> Right
                3. Down -> Right -> Down


        Constraints:
                1 <= m, n <= 100
*/



class Solution {
public:

    /*

      Time Complexity: O(m*n)

      Space Complexity: O(m*n)

    */
    int impl(int m, int n, int r, int c, vector<vector<int>> & dp) {
        /* if row or column index out of range grid then return 0 */
        if(r > m-1 || c > n-1)
            return 0;

        /* else if row and col index represent coordinate bottom right cell then return 1 */
        if(r == m-1 && c == n-1)
            return 1;

        /* else if current coordinate already calculated then return cached */
        if(dp[r][c] != -1)
            return dp[r][c];


        /* calculate left path and right path */
        int left = impl(m,n,r,c+1,dp);
        int right = impl(m,n,r+1,c,dp);

        /* cache result for future frames */
        dp[r][c] = left+right;

        return dp[r][c];
    }


    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        return impl(m, n, 0, 0, dp);
    }
};



int main() {
    Solution sol;

    assert(sol.uniquePaths(3,7) == 28);
    assert(sol.uniquePaths(3,2) == 3);
    assert(sol.uniquePaths(1,1) == 1);
    assert(sol.uniquePaths(0,0) == 0);

    return 0;
}
