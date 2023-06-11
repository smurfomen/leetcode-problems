#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
        Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent,
        with the colors in the order red, white, and blue.

        We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

        You must solve this problem without using the library's sort function.



        Example 1:
                Input: nums = [2,0,2,1,1,0]
                Output: [0,0,1,1,2,2]

        Example 2:
                Input: nums = [2,0,1]
                Output: [0,1,2]


        Constraints:
                n == nums.length
                1 <= n <= 300
                nums[i] is either 0, 1, or 2.


        Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/



class Solution_SelectionSort {
public:

    /*

      Time Complexity: O(n^2)
      Space Complexity: O(1)

    */
    void sortColors(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            int min = i;
            for(int j = i + 1; j < nums.size(); ++j) {
                if(nums[min] > nums[j]) {
                    min = j;
                }
            }

            swap(nums[i], nums[min]);
        }
    }
};




class Solution {
public:

    /*

      Time Complexity: O(n)
      Space Complexity: O(1)

    */
    void sortColors(vector<int>& nums) {
        /* idx for next insert for 0 and 2 */
        int i0 = 0, i2 = nums.size() - 1;

        int i = 0;
        while(i <= i2) {
            /* swap current element with actual insertion point zeroes */
            if(nums[i] == 0)
                swap(nums[i++], nums[i0++]);

            /* skip swap if current item is 1, cause 1 is middle value */
            else if(nums[i] == 1)
                i++;

            /* swap current element with actual insertion point for twoes */
            else if(nums[i] == 2)
                swap(nums[i], nums[i2--]);
        }
    }
};


int main() {
    Solution sol;

    {
        vector<int> c = {2,0,2,1,1,0};
        sol.sortColors(c);
        assert((c == vector<int>{0,0,1,1,2,2}));
    }

    {
        vector<int> c = {2,0,1};
        sol.sortColors(c);
        assert((c == vector<int>{0,1,2}));
    }

    return 0;
}
