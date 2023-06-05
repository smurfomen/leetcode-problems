#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
        Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.

        This matrix has the following properties:
                - Integers in each row are sorted in ascending from left to right.
                - Integers in each column are sorted in ascending from top to bottom.


        Example 1:
                Input:	matrix = [	[1 , 4, 7,11,15],
                                                        [2 , 5, 8,12,19],
                                                        [3 , 6, 9,16,22],
                                                        [10,13,14,17,24],
                                                        [18,21,23,26,30]],
                                target = 5
                Output: true

        Example 2:
                Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
                Output: false


        Constraints:
                m == matrix.length
                n == matrix[i].length
                1 <= n, m <= 300
                -10^9 <= matrix[i][j] <= 10^9
                All the integers in each row are sorted in ascending order.
                All the integers in each column are sorted in ascending order.
                -10^9 <= target <= 10^9
*/



class Solution {
public:

    /*

      Time Complexity: O(n)

      Space Complexity: O(1)

    */
    bool searchMatrix(vector<vector<int>> matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        int j = n-1;

        /* we move diagonally from the upper right corner of the matrix, because all rows and all columns are sorted in increasing order,
         * i.e. the top left element will be most smallest and bottom right element will be most greater */
        while(j >= 0 && i < m) {
            int& element = matrix[i][j];
            if(element == target)
                return true;

            /* if current element greater than target then go right - all rows was sorted from constraints */
            if(element > target)
                j--;

            /* or if current element less than target then go down - all columns was sorted from constraints */
            else
                i++;
        }

        return false;
    }
};


int main() {
    Solution sol;

    assert(sol.searchMatrix({{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}}, 5));

    assert(!sol.searchMatrix({{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}}, 20));


    return 0;
}
