#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


/*
        Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

        If target is not found in the array, return [-1, -1].

        You must write an algorithm with O(log n) runtime complexity.



        Example 1:
                Input: nums = [5,7,7,8,8,10], target = 8
                Output: [3,4]

        Example 2:
                Input: nums = [5,7,7,8,8,10], target = 6
                Output: [-1,-1]

        Example 3:
                Input: nums = [], target = 0
                Output: [-1,-1]


        Constraints:
                0 <= nums.length <= 105
                -109 <= nums[i] <= 109
                nums is a non-decreasing array.
                -109 <= target <= 109

*/



class Solution {
public:

    /*

      Time Complexity: O(n + log n)

      Space Complexity: O(1)

    */
    vector<int> searchRange(vector<int> nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r) {

            int mid = (l+r)/2;

            if(nums[mid] == target) {

                /* find right ending sequence position */
                int ri = mid;
                for(;ri < nums.size() - 1; ++ri) {
                    if(nums[ri + 1] != target)
                        break;
                }

                /* find left starting sequence position */
                int li = mid;
                for(;li > 0; --li) {
                    if(nums[li - 1] != target)
                        break;
                }

                return {li,ri};
            }
            else if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return {-1,-1};
    }
};



int main() {
    Solution sol;

    assert((sol.searchRange({5,7,7,8,8,10}, 8) == vector<int>{3,4}));
    assert((sol.searchRange({5,7,7,8,8,10}, 6) == vector<int>{-1,-1}));
    assert((sol.searchRange({}, 0) == vector<int>{-1,-1}));


    return 0;
}
