#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
            Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

            There is only one repeated number in nums, return this repeated number.

            You must solve the problem without modifying the array nums and uses only constant extra space.



            Example 1:
                    Input: nums = [1,3,4,2,2]
                    Output: 2

            Example 2:
                    Input: nums = [3,1,3,4,2]
                    Output: 3


            Constraints:
                    1 <= n <= 105
                    nums.length == n + 1
                    1 <= nums[i] <= n
                    All the integers in nums appear only once except for precisely one integer which appears two or more times.


            Follow up:
                    How can we prove that at least one duplicate number must exist in nums?
                    Can you solve the problem in linear runtime complexity?
*/



/*

  Time Complexity: O(n)

  Space Complexity: O(1)

*/
class Solution {
public:
    int findDuplicate(vector<int> nums) {
        int & first = nums[0];

        /* every element links to other element couse 1 <= nums[i] <= n, where nums.length == n + 1 */
        /* we can swap elements sequently and elements will stands to correct places, when nums[i] == i + 1 */

        /* first element will contain duplicate */
        while(first != nums[first]) {
            swap(first, nums[first]);
        }

        return first;
    }
};
int main() {
    Solution sol;

    assert(sol.findDuplicate({1,3,4,2,2}) == 2);
    assert(sol.findDuplicate({3,1,3,4,2}) == 3);
    assert(sol.findDuplicate({8,7,1,10,17,15,18,11,16,9,19,12,5,14,3,4,2,13,18,18}) == 18);

    return 0;
}















