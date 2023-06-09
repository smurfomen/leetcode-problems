#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


/*
        Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

        You must do it in place.



        Example 1:
                Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
                Output: [[1,0,1],[0,0,0],[1,0,1]]

        Example 2:
                Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
                Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


        Constraints:
                m == matrix.length
                n == matrix[0].length
                1 <= m, n <= 200
                -231 <= matrix[i][j] <= 231 - 1


        Follow up:
                A straightforward solution using O(mn) space is probably a bad idea.
                A simple improvement uses O(m + n) space, but still not the best solution.
                Could you devise a constant space solution?
*/



class Solution {
public:
    using row = vector<int>;
    using mtx = vector<row>;


    void zerofyColumn(mtx& matrix, int col) {
        for(int i = 0; i < matrix.size(); ++i) {
            matrix[i][col] = 0;
        }
    }

    void zerofyRow(mtx& matrix, int row) {
        fill(matrix[row].begin(), matrix[row].end(), 0);
    }


    /*

      Time Complexity: O(m*n + n + m) -> O(mn)

      Space Complexity: O(1)

    */
    void setZeroes(mtx& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        /* remember that first row contains or not zeroes, cause zeroes can spawned in first row in future */
        bool row0 = false;
        for(int& i : matrix[0])
            if(i == 0) { row0 = true; break; }


        /* mark 0 in first row and in first column if we found zero */
        for(int i = 1; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(matrix[i][j] == 0) {
                    /* mark rows in first column */
                    matrix[i][0] = 0;

                    /* mark columns in first row */
                    matrix[0][j] = 0;
                }
            }
        }

        /* zerofy rows by all marked columns */
        for(int i = 1; i < r; ++i) {
            if(matrix[i][0] == 0) {
                zerofyRow(matrix, i);
            }
        }

        /* zerofy columns by all marked rows */
        for(int j = 0; j < c; ++j) {
            if(matrix[0][j] == 0) {
                zerofyColumn(matrix, j);
            }
        }

        /* don't forget zerofy first row if it was contained zeroes before mark process */
        if(row0) {
            zerofyRow(matrix, 0);
        }
    }
};



int main() {
    Solution sol;

    {
        vector<vector<int>> mtx = {{1,1,1},{1,0,1},{1,1,1}};
        sol.setZeroes(mtx);
        assert((mtx == vector<vector<int>>{{1,0,1},{0,0,0},{1,0,1}}));
    }

    {
        vector<vector<int>> mtx = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
        sol.setZeroes(mtx);
        assert((mtx == vector<vector<int>>{{0,0,0,0},{0,4,5,0},{0,3,1,0}}));
    }

    {
        vector<vector<int>> mtx = {{1},{0}};
        sol.setZeroes(mtx);
        assert((mtx == vector<vector<int>>{{0},{0}}));
    }
    return 0;
}
