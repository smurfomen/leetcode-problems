#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
        Given an m x n matrix, return all elements of the matrix in spiral order.

        Example 1:
                Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
                Output: [1,2,3,6,9,8,7,4,5]

        Example 2:
                Input: matrix = [
                                    [1, 2, 3, 4],
                                    [5, 6, 7, 8],
                                    [9,10,11,12]
                                ]
                Output: [1,2,3,4,8,12,11,10,9,5,6,7]


        Constraints:
                m == matrix.length
                n == matrix[i].length
                1 <= m, n <= 10
                -100 <= matrix[i][j] <= 100
*/



class Solution {
public:
    /*

      Time Complexity: O(n)

      Space Complexity: O(n) -> O(1)

    */
    vector<int> spiralOrder(vector<vector<int>> matrix) {
        vector<int> result;
        int r1 = 0; int r2 = matrix.size()-1;
        int c1 = 0; int c2 = matrix[0].size()-1;

        while(c1 <= c2 && r1 <= r2) {

            /* left */
            for(int c = c1; c <= c2; ++c) {
                result.push_back(matrix[r1][c]);
            }


            /* down */
            for(int r = r1 + 1; r <= r2; ++r) {
                result.push_back(matrix[r][c2]);
            }


            /* if it is was not last element in center */
            if(c1 < c2 && r1 < r2) {
                /* right */
                for(int c = c2 - 1; c >= c1; --c) {
                    result.push_back(matrix[r2][c]);
                }

                /* up, before r1 not include r1, couse row [r1] already appended */
                for(int r = r2 - 1; r > r1; --r) {
                    result.push_back(matrix[r][c1]);
                }
            }

            /* increase start indexes row and column */
            c1++;
            r1++;

            /* decrease last indexes row and column */
            c2--;
            r2--;
        }

        return result;
    }
};


int main() {
    Solution sol;

    auto print = [](vector<int> v){
        for(auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    };

    print(sol.spiralOrder({{1,2,3,4}, {5,6,7,8}, {9,10,11,12}}));

    return 0;
}
