#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
            Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.


            Example 1:
                    Input: nums = [4,3,2,7,8,2,3,1]
                    Output: [5,6]

            Example 2:
                    Input: nums = [1,1]
                    Output: [2]


            Constraints:
                    n == nums.length
                    1 <= n <= 105
                    1 <= nums[i] <= n


            Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
*/



/*

  Time Complexity: O(2n)

  Space Complexity: O(n)

*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> nums) {
        vector<int> result;

        /* go forward and swap elements if it place are out of self places (nums[i] != i + 1), f.e: 4 must be placed on index 3 */
        for(int i = 0; i < nums.size();) {
            if(nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i]-1]);

            /* increment if swap no needed */
            else
                ++i;
        }


        /* go forward one more time and check elements which not placed on self places */
        for(int i = 0; i < nums.size(); ++i) {
            if(i + 1 != nums[i])
                result.push_back(i + 1);
        }

        return result;
    }
};


int main() {
    Solution sol;

    auto print = [](vector<int> v){
        for(auto i : v)
            cout << i << " ";
        cout << endl;
    };

    print(sol.findDisappearedNumbers({4,3,2,7,8,2,3,1}));
    print(sol.findDisappearedNumbers({1,1}));


    return 0;
}
