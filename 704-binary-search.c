#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
        Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums.
        If target exists, then return its index. Otherwise, return -1.

        You must write an algorithm with O(log n) runtime complexity.



        Example 1:
                Input: nums = [-1,0,3,5,9,12], target = 9
                Output: 4
                Explanation: 9 exists in nums and its index is 4

        Example 2:
                Input: nums = [-1,0,3,5,9,12], target = 2
                Output: -1
                Explanation: 2 does not exist in nums so return -1


        Constraints:
                1 <= nums.length <= 10^4
                -10^4 < nums[i], target < 10^4
                All the integers in nums are unique.
                nums is sorted in ascending order.
*/



class Solution {
public:

    /*

      Time Complexity: O(log n)

      Space Complexity: O(1)

    */
    int search(vector<int> nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r) {
            int mid = (l + r)/2;
            int num = nums[mid];
            if(num == target)
                return mid;
            else if(num < target) {
                l = mid + 1;
            }
            else if (num > target) {
                r = mid - 1;
            }
        }

        return -1;
    }
};


int main() {
    Solution sol;

    assert(sol.search({-1,0,3,5,9,12}, 9) == 4);
    assert(sol.search({-1,0,3,5,9,12}, 12) == 5);
    assert(sol.search({-1,0,3,5,9,12}, 3) == 2);


    return 0;
}
