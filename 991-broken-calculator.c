#include <string>
#include <cassert>
#include <iostream>

using namespace std;

/*
    There is a broken calculator that has the integer startValue on its display initially. In one operation, you can:

    multiply the number on display by 2, or
    subtract 1 from the number on display.
    Given two integers startValue and target, return the minimum number of operations needed to display target on the calculator.


    Example 1:
        Input: startValue = 2, target = 3
        Output: 2
        Explanation: Use double operation and then decrement operation {2 -> 4 -> 3}.

    Example 2:
        Input: startValue = 5, target = 8
        Output: 2
        Explanation: Use decrement and then double {5 -> 4 -> 8}.

    Example 3:
        Input: startValue = 3, target = 10
        Output: 3
        Explanation: Use double, decrement and double {3 -> 6 -> 5 -> 10}.


    Constraints:
        1 <= x, y <= 10^9
*/
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        return brokenCalcLoop(startValue, target);
    }

    int brokenCalcRecursive(int startValue, int target) {
        /* if startValue less then target - one way is decrement */
        if(startValue >= target)
            return startValue - target;

        /* if target is even */
        if(target & 1)
            return 1 + brokenCalc(startValue, target + 1);

        return 1 + brokenCalc(startValue, target / 2);
    }

    int brokenCalcLoop(int startValue, int target) {
        int steps = 0;

        while(target > startValue)
        {
            if(target & 1)
                target++;
            else
                target /= 2;

            steps++;
        }

        return steps + startValue - target;
    }
};


int main(int argc, char * argv[]) {
    Solution sol;

    assert(sol.brokenCalc(2,3) == 2);
    assert(sol.brokenCalc(5,8) == 2);
    assert(sol.brokenCalc(3, 10) == 3);
    cout << "tests is passed!" << endl;

    return 0;
}
