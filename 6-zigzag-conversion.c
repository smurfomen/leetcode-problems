#include <string>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

/*
    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

    P   A   H   N
    A P L S I I G
    Y   I   R
    And then read line by line: "PAHNAPLSIIGYIR"

    Write the code that will take a string and make this conversion given a number of rows:

    string convert(string s, int numRows);


    Example 1:
    Input: s = "PAYPALISHIRING", numRows = 3
    Output: "PAHNAPLSIIGYIR"

    Example 2:
    Input: s = "PAYPALISHIRING", numRows = 4
    Output: "PINALSIGYAHRPI"
    Explanation:
    P     I    N
    A   L S  I G
    Y A   H R
    P     I

    Example 3:
    Input: s = "A", numRows = 1
    Output: "A"

    Constraints:

    1 <= s.length <= 1000
    s consists of English letters (lower-case and upper-case), ',' and '.'.
    1 <= numRows <= 1000
*/
class Solution {
public:
    string convert(string s, int num) {
        if(num > 1)
        {
            string rows[num];
            {
                /* walking down by rows array or walking up*/
                /* For example:
                    PAYPALISHIRING

                    A.e.:
                       0 | P   A   H   N
                       1 | A P L S I I G
                       2 | Y   I   R

                    A.e. 3 rows:
                        PAHN
                        APLSIIG
                        YIR

                   Rows Index will be changed 0->1->2->1->0->1->2....
                   Rows Index need for sort current character to target row, for make result row from this rows late
                */
                bool goDown = true;
                int rowIndex = 0;
                int size = s.size();

                for(int i = 0; i < size; ++i)
                {
                    rows[rowIndex].push_back(s[i]);

                    if(rowIndex == 0)
                        goDown = true;
                    else if(rowIndex == num - 1)
                        goDown = false;

                    (goDown ? ++rowIndex : --rowIndex);
                }
            }

            {
                s.clear();
                for(int r = 0; r < num; ++r)
                {
                    s += rows[r];
                }
            }
        }

        return s;
    }
};


int main(int argc, char * argv[]) {
    Solution sol;

    assert(sol.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    assert(sol.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    assert(sol.convert("A", 1) == "A");

    cout << "tests is passed!" << endl;

    return 0;
}
