#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
        Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.



        Example 1:
                Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
                Output: 6
                Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
                In this case, 6 units of rain water (blue section) are being trapped.

        Example 2:
                Input: height = [4,2,0,3,2,5]
                Output: 9


        Constraints:
                n == height.length
                1 <= n <= 2 * 10^4
                0 <= height[i] <= 10^5
*/


class Solution {
public:
    /*

      Time Complexity: O(n^2)
      Space Complexity: O(1)

    */
    int trap_BruteForce(vector<int> height) {
        int sum = 0;

        for(int i = 0; i < height.size()-1; ++i) {
            int l = *max_element(height.begin(), height.begin() + i + 1);
            int r = *max_element(height.begin() + i, height.end());

            sum += min(l, r) - height[i];
        }

        return sum;
    }


    /*

      Time Complexity: O(n)
      Space Complexity: O(1)

    */
    int trap(vector<int> height) {
        int sum = 0;
        int l = 0;
        int r = height.size() - 1;
        int lmax = 0;
        int rmax = 0;

        /* narrow range between l and r pointers */
        while(l <= r) {

            /* if current left height less then current right height */
            if(height[l] <= height[r]) {

                /* then update greater meeted left maximum value */
                if(height[l] > lmax)
                    lmax = height[l];

                /* or increase sum by current left maximum value - current left height */
                else
                    sum += lmax - height[l];

                /* move left pointer to right */
                l++;
            }

            /* otherwise if current left height greater than right then we need calc right side */
            else {

                /* update right maximum meeted value*/
                if(height[r] > rmax)
                    rmax = height[r];

                /* of increase sum by current right maximum value - current right height */
                else
                    sum += rmax - height[r];

                /* move right pointer to left */
                r--;
            }
        }

        return sum;
    }
};



int main() {
    Solution sol;

    cout << sol.trap({0,1,0,2,1,0,1,3,2,1,2,1}) << endl;
    cout << sol.trap({4,2,0,3,2,5}) << endl;

    return 0;
}
