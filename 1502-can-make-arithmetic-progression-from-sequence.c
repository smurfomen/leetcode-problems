#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
        A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

        Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.


        Example 1:
                Input: arr = [3,5,1]
                Output: true
                Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.

        Example 2:
                Input: arr = [1,2,4]
                Output: false
                Explanation: There is no way to reorder the elements to obtain an arithmetic progression.


        Constraints:
                2 <= arr.length <= 1000
                -10^6 <= arr[i] <= 10^6
*/



class Solution {
public:

    /*

      Time Complexity: O(n log n + n - 2) -> O(n log n)

      Space Complexity: O(1)

    */
    bool canMakeArithmeticProgression(vector<int> arr) {
        sort(arr.begin(), arr.end());

        int d = arr[1] - arr[0];

        for(int i = 2; i < arr.size(); ++i) {
            if(arr[i] - arr[i-1] != d)
                return false;
        }

        return true;
    }
};


int main() {
    Solution sol;
    assert(sol.canMakeArithmeticProgression({3,5,1}) == true);
    assert(sol.canMakeArithmeticProgression({1,2,4}) == false);


    return 0;
}
