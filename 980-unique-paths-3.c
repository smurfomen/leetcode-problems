#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


/*
        You are given an m x n integer array grid where grid[i][j] could be:

        1 representing the starting square. There is exactly one starting square.
        2 representing the ending square. There is exactly one ending square.
        0 representing empty squares we can walk over.
        -1 representing obstacles that we cannot walk over.
        Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.



        Example 1:
                Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
                Output: 2
                Explanation: We have the following two paths:
                1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
                2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

        Example 2:
                Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
                Output: 4
                Explanation: We have the following four paths:
                1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
                2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
                3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
                4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

        Example 3:
                Input: grid = [[0,1],[2,0]]
                Output: 0
                Explanation: There is no path that walks over every empty square exactly once.
                Note that the starting and ending square can be anywhere in the grid.


        Constraints:
                m == grid.length
                n == grid[i].length
                1 <= m, n <= 20
                1 <= m * n <= 20
                -1 <= grid[i][j] <= 2
                There is exactly one starting cell and one ending cell.




                !!! YOU NEED WALK THROUGH ALL CELLS FOR VALID UNIQUE PATH !!!



*/



/*

      Time Complexity: O(n^2)
      Space Complexity: O(1)

*/
class Solution {
public:
    int impl(int r, int c, int rc, int cc, pair<int,int> dest, int emptyCells, vector<vector<int>>& grid) {
        /* if current cell is out of range or current cell is obstacle then return 0 */
        if(r >= rc || c >= cc || r < 0 || c < 0 || grid[r][c] == -1)
            return 0;

        /* if empty cells ended and current cell is destination then return 1 */
        if(emptyCells == -1 && dest == pair<int,int>{r,c})
            return 1;

        /* mark this cell like obstacle */
        grid[r][c] = -1;

        /* decrease empty cells */
        emptyCells--;

        /* accumulate sum unique paths from cells around */
        int sum = 0;
        sum += impl(r, c-1, rc, cc, dest, emptyCells, grid);
        sum += impl(r, c+1, rc, cc, dest, emptyCells, grid);
        sum += impl(r+1, c, rc, cc, dest, emptyCells, grid);
        sum += impl(r-1, c, rc, cc, dest, emptyCells, grid);

        /* restore current cell value */
        grid[r][c] = 0;

        return sum;
    }

    int uniquePathsIII(vector<vector<int>> grid) {
        int m = grid.size();
        int n = grid[0].size();

        /* find source cell, dest cell and total empty cells on the grid */
        pair<int,int> src, dest;
        int emptyCells = 0;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                switch (grid[i][j]) {
                    case 0: emptyCells++; break;
                    case 1: src = {i, j}; break;
                    case 2: dest = {i, j}; break;
                }
            }
        }

        return impl(src.first, src.second, m, n, dest, emptyCells, grid);
    }
};



int main() {
    Solution sol;

    assert(sol.uniquePathsIII({{1,0,0,0},{0,0,0,0},{0,0,2,-1}}) == 2);
    assert(sol.uniquePathsIII({{1,0,0,0},{0,0,0,0},{0,0,0,2}}) == 4);
    assert(sol.uniquePathsIII({{0,1},{2,0}}) == 0); // not contain valid path cause any path in this case not cover all empty cells

    return 0;
}
