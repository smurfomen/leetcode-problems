#include <string>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

/*
        Given an array nums of size n, return the majority element.

        The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

        Example 1:
                        Input: nums = [3,2,3]
                        Output: 3

        Example 2:
                        Input: nums = [2,2,1,1,1,2,2]
                        Output: 2

        Constraints:
                        n == nums.length
                        1 <= n <= 5 * 104
                        -109 <= nums[i] <= 109
*/

/* complex time (sort)	complex space (sort) */
class Solution_Unoptimized {
public:
    int majorityElement(vector<int> & nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

/* linear time O(N) and space O(1)*/
class Solution {
public:
    int majorityElement(vector<int> & nums) {
        int result = 0;
        int vote = 0;

        for(int & num : nums) {

            /* if votes eq 0 then result should be num */
            if(vote == 0) {
                result = num;
                vote++;
            }

            /* or if result already equial current num then votes increase */
            else if(result == num)
                vote++;

            /* else if result is not equial current num then votes decrease */
            else
                vote--;
        }

        return result;
    }
};



int main() {
    Solution sol;

    {
        vector<int> v {3,2,3};
        assert(sol.majorityElement(v) == 3);
    }

    {
        vector<int> v {2,2,1,1,1,2,2};
        assert(sol.majorityElement(v) == 2);
    }

    {
        vector<int> v {3,3,4};
        assert(sol.majorityElement(v) == 3);
    }

    return 0;
}
