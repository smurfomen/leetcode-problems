#include <string>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/*
    Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
    The overall run time complexity should be O(log (m+n)).

    Example 1:
        Input: nums1 = [1,3], nums2 = [2]
        Output: 2.00000
        Explanation: merged array = [1,2,3] and median is 2.

    Example 2:
        Input: nums1 = [1,2], nums2 = [3,4]
        Output: 2.50000
        Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

    Constraints:
        nums1.length == m
        nums2.length == n
        0 <= m <= 1000
        0 <= n <= 1000
        1 <= m + n <= 2000
        -106 <= nums1[i], nums2[i] <= 106
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        int size = nums1.size() + nums2.size();
        vector<int> r(size, 0);

        auto it1 = nums1.begin();
        auto it2 = nums2.begin();

        {
            int i = 0;
            while(i < size)
            {
                auto & itc = it1 != nums1.end() ? it2 != nums2.end() ? *it1 < *it2  ? it1 : it2 : it1 : it2;

                r[i++] = *itc;
                itc++;
            }
        }

        if(r.size() % 2)
            return r[r.size()/2];
        else
            return ((double)r[r.size()/2-1] + (double)r[r.size()/2]) / 2.0;
    }
};


int main(int argc, char * argv[]) {
    Solution sol;

    assert(sol.findMedianSortedArrays(vector<int>{1, 3}, vector<int>{2}) == 2);
    assert(sol.findMedianSortedArrays(vector<int>{1, 2}, vector<int>{3, 4}) == 2.5);

    cout << "tests is passed!" << endl;

    return 0;
}
