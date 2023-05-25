#include <string>
#include <cassert>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

/*
            You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
            You can only see the k numbers in the window. Each time the sliding window moves right by one position.

            Return the max sliding window.


            Example 1:
                    Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
                    Output: [3,3,5,5,6,7]
                    Explanation:
                    Window position                Max
                    ---------------               -----
                    [1  3  -1] -3  5  3  6  7       3
                     1 [3  -1  -3] 5  3  6  7       3
                     1  3 [-1  -3  5] 3  6  7       5
                     1  3  -1 [-3  5  3] 6  7       5
                     1  3  -1  -3 [5  3  6] 7       6
                     1  3  -1  -3  5 [3  6  7]      7


            Example 2:
                    Input: nums = [1], k = 1
                    Output: [1]

            Constraints:
                    1 <= nums.length <= 105
                    -104 <= nums[i] <= 104
                    1 <= k <= nums.length
*/


/* Time Limit Exceeded time O(N^2) space O(N) -> O(1) couse we need one vector for result with size nums.size() - k */
class SolutionBruteForce {
public:
    int fmax(int l, int r, int* n) {
        if(l > r)
            return -1;

        if(l == r)
            return l;

        int m = r;

        for(int i = r-1; i >= l; --i) {
            if(n[i] > n[m])
                m = i;
        }

        return m;
    }

    vector<int> maxSlidingWindow(vector<int> nums, int k) {
        int nCount = nums.size();

        if(nCount < k)
            return {nums[fmax(0, nCount-1, nums.data())]};

        vector<int> result;

        int l = 0;
        int r = k-1;
        int imax = fmax(l,r,nums.data());
        result.push_back(nums[imax]);

        for(int i = 0; i < nCount - k; ++i) {
            if(r++ - l >= k-1)
            {
                ++l;

                if(l-1 == imax)
                    imax = fmax(l,r,nums.data());

                else if(nums[r] > nums[imax])
                    imax = r;


                result.push_back(nums[imax]);
            }
        }

        return result;
    }
};


/* time O(N) and space O(N + k)	but in this case we have many memory ops */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> nums, int k) {
        int nCount = nums.size();
        vector<int> result;
        deque<int> win;

        for(int i = 0; i < nCount; ++i) {
            /* pop back elements which not included in current frame */
            if(!win.empty() && win.back() == i-k)
                win.pop_back();

            /* here win include only indexes from current frame (i-(k-1)...i) */

            /* pop front elements current frame which less than current ith element */
            while(!win.empty() && nums[win.front()] < nums[i])
                win.pop_front();

            /* here win have size 0 >= win.size() < k */

            /* if we pop front all elements from win then push front is equial push back */
            /* if we pop front not all elements then back element greater then current ith element*/
            win.push_front(i);


            /* push back to result if we walked minimum k elements from begin nums */
            if(i + 1 >= k)
                result.push_back(nums[win.back()]);
        }

        return result;
    }
};



int main() {
    Solution sol;

    assert((sol.maxSlidingWindow({1,3,-1,-3,5,3,6,7}, 3) == vector<int>{3,3,5,5,6,7}));
    assert((sol.maxSlidingWindow({1}, 1) == vector<int>{1}));
    assert((sol.maxSlidingWindow({-7,-8,7,5,7,1,6,0}, 4) == vector<int>{7,7,7,7,7})); // 7,7,7,6,6

    return 0;
}
