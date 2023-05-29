#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
        You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
        You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.


        1   2   3       7   4   1
        4   5   6   ->  8   5   2
        7   8   9       9   6   3


        Example 1:
                Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
                Output: [[7,4,1],[8,5,2],[9,6,3]]

        Example 2:
                Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
                Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

        Constraints:
                n == matrix.length == matrix[i].length
                1 <= n <= 20
                -1000 <= matrix[i][j] <= 1000
*/

class Solution {
public:
    /* for example:
     * begin:	1 2 3
     *          4 5 6
     *          7 8 9
     *
     * begin swaps from top left element:
     * 1. (i=0, j=0) -> skip
     * 2. (i=1, j=0) -> swap [1,0] and [0,1], e.g 4 and 2
     * 3. (i=1, j=1) -> skip
     * 4. (i=2, j=0) -> swap [2,0] and [0,2], e.g 7 and 3
     * 5. (i=2, j=1) -> swap [2,1] and [1,2], e.g 8 and 6
     * 6. (i=2, j=2) -> skip
     *
     * result:	1 4 7
     *          2 5 8
     *          3 6 9
     *
     * reverse rows:	7 4 1
     *                  8 5 2
     *                  9 6 3
     *
     * if we need rotate to other side then we must begin from top right element
     */
    void rotate(vector<vector<int>>& matrix) {
        /* X == Y, see for constraints */
        int n = matrix.size();

        /* go forward for rows */
        for(int i = 0; i < n; ++i) {

            /* go forward for cols, but only after current row index */
            for(int j = 0; j < i; ++j) {
                /* swap [row][col] and [col][row] */
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        /* reverse rows */
        for(auto & row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};

int main() {
    Solution sol;

    using mat = vector<vector<int>>;
    auto print = [](mat r) {
        for(auto i : r) {
            for(auto j : i) {
                cout << j << " ";
            }
            cout << "\n" ;
        }
        cout << "\n\n";
    };

    {
        mat m = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };

        print(m);

        sol.rotate(m);

        print(m);
    }

    return 0;
}
