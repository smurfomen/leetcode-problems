#include <string>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/*
    You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

    Find two lines that together with the x-axis form a container, such that the container contains the most water.
    Return the maximum amount of water a container can store.
    Notice that you may not slant the container.

    Example 1:
        Input: height = [1,8,6,2,5,4,8,3,7]
      8 |
      7 |     |_ _ _ _ _ _ _ | _ _ _ _ _ _ _ _ _ _ _
      6 |     |++++++++++++++|+++++|                ▲
      5 |     |++|+++++++++++|+++++|                |
      4 |     |++|+++++|+++++|+++++|                |
      3 |     |++|+++++|++|++|+++++|                | 7 * (9 - 2) = 49
      2 |     |++|+++++|++|++|++|++|                |
      1 |     |++|++|++|++|++|++|++|                |
      0 |__|__|++|++|++|++|++|++|++|_ _ _ _ _ _ _ _ ▼
        0  1  2  3  4  5  6  7  8  9
        Output: 49
        Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

    Example 2:
        Input: height = [1,1]
        Output: 1

    Constraints:
        n == height.length
        2 <= n <= 10^5
        0 <= height[i] <= 10^4
*/
class Solution {
public:
    int maxArea(const vector<int> & height) {
        int right = height.size() - 1;
        int left = 0;
        int maxArea = 0;
        while(left < right)
        {
            int h = min(height[left], height[right]);
            int distance =  right - left;
            maxArea = max(maxArea, h * distance);

            (height[left] < height[right] ? ++left : --right);
        }

        return maxArea;
    }
};


int main(int argc, char * argv[]) {
    Solution sol;

    cout << sol.maxArea({1,8,6,2,5,4,8,3,7}) << endl;
    cout << sol.maxArea({1,1}) << endl;

    cout << sol.maxArea({2,3,4,5,18,17,6}) << endl;
    cout << sol.maxArea({76,155,15,188,180,154,84,34,187,142,22,5,27,183,111,128,50,58,2,112,179,2,
                         100,111,115,76,134,120,118,103,31,146,58,198,134,38,104,170,25,92,112,199,
                         49,140,135,160,20,185,171,23,98,150,177,198,61,92,26,147,164,144,51,196,42,
                         109,194,177,100,99,99,125,143,12,76,192,152,11,152,124,197,123,147,95,73,124,
                         45,86,168,24,34,133,120,85,81,163,146,75,92,198,126,191}) << endl;

    cout << "tests is passed!" << endl;

    return 0;
}
