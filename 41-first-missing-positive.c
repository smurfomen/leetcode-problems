#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

/*
            Given an unsorted integer array nums, return the smallest missing positive integer.

            You must implement an algorithm that runs in O(n) time and uses constant extra space.


            Example 1:
                    Input: nums = [1,2,0]
                    Output: 3
                    Explanation: The numbers in the range [1,2] are all in the array.

            Example 2:
                    Input: nums = [3,4,-1,1]
                    Output: 2
                    Explanation: 1 is in the array but 2 is missing.

            Example 3:
                    Input: nums = [7,8,9,11,12]
                    Output: 1
                    Explanation: The smallest positive integer 1 is missing.

            Constraints:
                    1 <= nums.length <= 105
                    -231 <= nums[i] <= 231 - 1
*/


/* 7,8,9,11,12 */
/* 3,4,-1,1  -> -1,4,3,1 -> -1,1,3,4*/

/* time O(2N) and space O(1) */
class SolutionOptimized {
public:
    /* 3,4,-1,1 */
    /* 8,11,12,7,9 */
    int firstMissingPositive(vector<int> nums) {
        int i = 0;
        int nCount = nums.size();

        /* go forward and sort elements */
        for(; i < nCount; ++i){
            /* skip element if it less or eq then 0 or greater then total count elements*/
            if(nums[i] <= 0 || nums[i] > nCount)
                continue;

            /* also skip element if it value and element from [value] is equials, for example it may be: 1 2 3 -> 1 for index 0, e.g 1 - 1, 2 for index 1 and 3 for index 2 */
            else if(nums[i]==nums[nums[i]-1])
                continue;

            /* else if element not placed on self place - swap elements and go bacward for one step */
            else if(i != nums[i]-1 ) {
                swap(nums[i], nums[nums[i] - 1]);
                i--;
            }
        }


        i = 0;

        for(; i < nCount;i++) {
            if(i+1 != nums[i])
                return i+1;
        }
        return i+1;
    }
};



/* 7,8,9,11,12 */
/* 3,4,-1,1 */


/* time O(N) + O(log set::size()), space O(2N) */
class Solution {
public:
    int firstMissingPositive(vector<int> nums) {
        set<int> s;

        for(auto i : nums)
            if(i > 0)
                s.insert(i);

        /* if first not 1 than return 1 */
        if(*s.begin() != 1)
            return 1;

        /* if last equial positive numbers size - return next num after last number sequently, couse in this case we have perfect sequence without missings */
        if(*s.crbegin() == static_cast<int>(s.size())) {
            return *s.crbegin() + 1;
        }

        /* ok, we know that first element is 1 and something into sequence has a missing element */
        auto it = s.cbegin();

        int result = *it; // result = 1

        auto end = s.cend();
        it++;

        /* start go forward from second element */
        for(int result = 1; it != end; ++it, ++result) {

            /* if current element not equial expected sequently - its place for missing element */
            if(*it != result + 1)
                return result + 1;
        }

        return result;
    }
};


int main() {
    Solution sol;

    cout << sol.firstMissingPositive({1,2,3,4,5,6,7,8,9,20}) << endl;

    cout << sol.firstMissingPositive({7,8,9,11,12}) << endl;

    cout << sol.firstMissingPositive({3,4,-1,1}) << endl;

    cout << sol.firstMissingPositive({1,2,0}) << endl;

    return 0;
}


















