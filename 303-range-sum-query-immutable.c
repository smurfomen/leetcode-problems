#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
        Given an integer array nums, handle multiple queries of the following type:

        Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
        Implement the NumArray class:

        NumArray(int[] nums) Initializes the object with the integer array nums.
        int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).


        Example 1:
                Input
                ["NumArray", "sumRange", "sumRange", "sumRange"]
                [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
                Output
                [null, 1, -1, -3]

        Explanation
                NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
                numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
                numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
                numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3


        Constraints:

                1 <= nums.length <= 104
                -105 <= nums[i] <= 105
                0 <= left <= right < nums.length
                At most 104 calls will be made to sumRange.



       Your NumArray object will be instantiated and called as such:
       NumArray* obj = new NumArray(nums);
       int param_1 = obj->sumRange(left,right);

*/




/*

  Time Complexity: Constructor O(n) couse caching	and	  sumRange O(1)

  Space Complexity: O(n)

*/
class NumArray {
    /* cache will contain sum all elements from nums starts 0 to current element inclusive */
    vector<int> cache;
public:
    NumArray(vector<int>& nums) {
        int current_sum = 0;

        /* just summarize all elements lefter then current inclusive current and push this sum to cache  */
        for(auto num : nums) {
            current_sum += num;
            cache.push_back(current_sum);
        }
    }

    /* f.e: [1,3,4] (left=1, right=2) (cached: [1,4,8]) -> return cache[2]-cache[1-1] -> 8-1=7  */
    int sumRange(int left, int right) {
        /* if left == 0 then we can return cahce[right] element, couse it element already contains needed sum all elements before inclusive cache[right] */
        if(left == 0)
            return cache[right];

        /* otherwise return difference between summ on right index and left index */
        return cache[right] - cache[left-1];
    }
};



int main() {
    vector<int> nums {1,4,2,7,8};
    NumArray *obj = new NumArray(nums);
    int left = 1, right = 4;
    int param_1 = obj->sumRange(left, right);
    cout << param_1 << endl;
    return 0;
}
