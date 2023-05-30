#include <cassert>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

/*
            Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

            You must implement a solution with a linear runtime complexity and use only constant extra space.



            Example 1:
                    Input: nums = [2,2,1]
                    Output: 1

            Example 2:
                    Input: nums = [4,1,2,1,2]
                    Output: 4

            Example 3:
                    Input: nums = [1]
                    Output: 1


            Constraints:
                    1 <= nums.length <= 3 * 104
                    -3 * 104 <= nums[i] <= 3 * 104
                    Each element in the array appears twice except for one element which appears only once.
*/



/*

  Time Complexity: O(n)

  Space Complexity: O(2n)

*/
class SolutionUsingSet {
public:
    int singleNumber(vector<int> nums) {
        if(nums.size() % 2 == 0)
            return -1;

        set<int> s;
        for(auto i : nums) {
            if(s.count(i))
                s.erase(i);
            else
                s.insert(i);
        }

        return *s.begin();
    }
};


/*

  Time Complexity: O(n)

  Space Complexity: O(1)

*/
class Solution {
public:

    /*
       Couse from constraints we know, that each element in the array appears twice except for one element which appears only once
       then we can use XOR

       f.e.:
       [0110, 1000, 0110]

       0110 ^ 1000 = 1110

       1110 ^ 0110 = 1000

       result: 1000
    */
    int singleNumber(vector<int> nums) {
        int mask = 0;

        for(auto i : nums)
            mask = mask xor i;

        return mask;
    }
};

int main() {
    Solution sol;

    assert(sol.singleNumber({4,1,2,1,2}) == 4);
    assert(sol.singleNumber({2,2,1}) == 1);
    assert(sol.singleNumber({1}) == 1);


    return 0;
}
