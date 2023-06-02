#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
        Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.


        Example 1:
                Input: n = 2
                Output: [0,1,1]
                Explanation:
                0 --> 0
                1 --> 1
                2 --> 10

        Example 2:
                Input: n = 5
                Output: [0,1,1,2,1,2]
                Explanation:
                0 --> 000
                1 --> 001
                2 --> 010
                3 --> 011
                4 --> 100
                5 --> 101


        Constraints:
                0 <= n <= 10^5


        Follow up:
                It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
                Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?
*/


class Solution {
public:

    /*

      Time Complexity: O(n log n)

      Space Complexity: O(n+1)

    */
    vector<int> countBitsNonOpt(int n) {
        vector<int> result;
        for(int i = 0; i <= n; ++i) {
            int num = i;
            int count = 0;

            while(num != 0) {
                count += num & 1;
                num = num >> 1;
            }

            result.push_back(count);
        }

        return result;
    }


    /*

      Time Complexity: O(n)

      Space Complexity: O(n+1)

    */
    vector<int> countBits(int n) {
        vector<int> result (n+1, 0);
        /* fill result array zeroes */

        /* go forvard starts from 1 sequenced and push count 1's into result */
        for(int i = 1; i <= n; ++i) {
            /*
              1's count for ith element is  [i >> 1], e.g. i / 2 element + i % 2

              1) 1 >> 1 = [0] + 1%2 = 0 + 1 = 1
              2) 2 >> 1 = [1] + 2%2 = 1 + 0 = 1
              3) 3 >> 1 = [1] + 3%2 = 1 + 1 = 2
              4) 4 >> 1 = [2] + 4%2 = 1 + 0 = 1
              5) 5 >> 1 = [2] + 5%2 = 1 + 1 = 2
              6) 6 >> 1 = [3] + 6%2 = 2 + 0 = 2
              ...
            */
            result[i] = result[i >> 1] + i % 2;
        }

        return result;
    }
};

int main() {
    Solution sol;

    auto print = [](vector<int> r){
        for(auto i : r)
            cout << i << " ";
        cout << endl;
    };
    print(sol.countBits(2));
    print(sol.countBits(5));

    return 0;
}
