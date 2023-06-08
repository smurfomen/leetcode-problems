#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
        Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.


        Example 1:
                Input: n = 3
                Output: [[1,2,3],[8,9,4],[7,6,5]]

        Example 2:
                Input: n = 1
                Output: [[1]]


        Constraints:
                1 <= n <= 20
*/



class Solution {
public:
    /*

      Time Complexity: O(n)

      Space Complexity: O(n) -> O(1)

    */
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result (n , vector<int>(n, 0));
        int r0 = 0, r1 = n-1;
        int c0 = 0, c1 = n-1;

        int v = 1;

        /* go by spiral */
        while(r0 <= r1 && c0 <= c1) {
            /* left to right */
            for(int c = c0; c <= c1; ++c) {
                result[r0][c] = v++;
            }

            /* top to bottom, starts from current row + 1, cause r0 already filled when walked from left to right */
            for(int r = r0+1; r <= r1; ++r) {
                result[r][c1] = v++;
            }

            /* if current element is not last item in center */
            if(c0 < c1 && r0 < r1) {

                /* right to left starts from c1 - 1 cause c1 already filled when walked from top to bottom  */
                for(int c = c1 - 1; c >= c0; --c) {
                    result[r1][c] = v++;
                }

                /* bottom to top, starts from r1 - 1 cause r1 already filled when walked from right to left */
                for(int r = r1 - 1; r > r0; --r) {
                    result[r][c0] = v++;
                }
            }

            c0++;
            r0++;
            c1--;
            r1--;
        }

        return result;
    }
};


int main() {
    Solution sol;

    auto print = [](vector<vector<int>> v) {
        for(auto r : v) {
            for(auto c : r)
                cout << c << (c < 100 ? c < 10 ? "   " : "  " : " ");
            cout << endl;
        }
        cout << endl;
    };

    print(sol.generateMatrix(3));
    print(sol.generateMatrix(15));

    return 0;
}
