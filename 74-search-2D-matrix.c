#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
        You are given an m x n integer matrix matrix with the following two properties:

        Each row is sorted in non-decreasing order.
        The first integer of each row is greater than the last integer of the previous row.
        Given an integer target, return true if target is in matrix or false otherwise.

        You must write a solution in O(log(m * n)) time complexity.



        Example 1:
                Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
                Output: true

        Example 2:
                Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
                Output: false


        Constraints:
                m == matrix.length
                n == matrix[i].length
                1 <= m, n <= 100
                -10^4 <= matrix[i][j], target <= 10^4
*/



class Solution {
public:


    /*

      Time Complexity: O(m + log n)

      Space Complexity: O(1)

    */
    bool searchMatrixS(vector<vector<int>> matrix, int target) {
        int n = matrix[0].size();
        int m = matrix.size();

        /* find containing target row */
        for(int i = 0; i < m; ++i) {

            /*
                Couse we know that every first element in every row greater then last element in previous row and all row is sorted
                We can find row where last element will greater or equial then target, and that means this row can include target, and next row not include target 100%
                And if we find such row then we can run binary search couse every row is sorted
            */
            if(target <= matrix[i][n-1]) {
                vector<int> & row = matrix[i];

                int l = 0;
                int r = n-1;

                while(l <= r) {
                    int mid = (l+r)/2;

                    if(row[mid] == target)
                        return true;
                    else if(row[mid] > target)
                        r = mid - 1;
                    else
                        l = mid + 1;
                }

                break;
            }
        }

        return false;
    }

    /*

      Time Complexity: O(log (m*n))

      Space Complexity: O(1)

    */
    bool searchMatrix(vector<vector<int>> matrix, int target) {
        int colCount = matrix[0].size();
        int rowCount = matrix.size();

        /*
            Couse we know that all rows is sorted and every first element in row greater than last element in previous row.

            It means we can run binary search using transform index to 2D coordinate
        */

        int l = 0;
        int r = rowCount*colCount - 1;

        while(l <= r) {
            int mid = (l+r) / 2;

            /* convert index middle element to 2D coordinate */

            /* i is index row middle element */
            int i = mid / colCount;

            /* j is index column middle element */
            int j = mid % colCount;

            int& middle = matrix[i][j];

            /* if we found target then return true */
            if(middle == target)
                return true;

            else if(middle > target) {
                r = mid -1;
            }
            else
                l = mid + 1;
        }

        /* if l > r then target not found */
        return false;
    }
};


int main() {
    Solution sol;

    assert(sol.searchMatrix({{1,3,5,7},{10,11,16,20},{23,30,34,60}}, 3));
    assert(!sol.searchMatrix({{1,3,5,7},{10,11,16,20},{23,30,34,60}}, 13));
    assert(!sol.searchMatrix({{1,1}}, 2));
    assert(!sol.searchMatrix({{1}}, 2));
    assert(sol.searchMatrix({{1,3}}, 3));


    return 0;
}
