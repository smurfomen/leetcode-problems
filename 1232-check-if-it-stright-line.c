#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
        You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point.
        Check if these points make a straight line in the XY plane.

        Example 1:
                Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
                Output: true

        Example 2:
                Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
                Output: false


        Constraints:
                2 <= coordinates.length <= 1000
                coordinates[i].length == 2
                -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
                coordinates contains no duplicate point.
*/



class Solution {
public:

    /*

      Time Complexity: O(n)

      Space Complexity: O(1)

    */
    bool checkStraightLine(vector<vector<int>> v) {
        /* delta by Y coordinate between v[0] and v[1] */
        int deltaY = v[0][1] - v[1][1];

        /* delta by X coordinate between v[0] and v[1] */
        int deltaX = v[0][0] - v[1][0];

        /* starts from third point */
        for(int i = 2; i < v.size(); ++i) {

            /* delta by Y coordinate multiplied delta by X coord between current point and first point */
            int p0 = deltaY * (v[i][0] - v[0][0]);

            /* delta by X coordinate multiplied delta by Y coord between current point and first point */
            int p1 = deltaX * (v[i][1] - v[0][1]);

            /* if p0 not equial p1 then this point not placed one line where with first and second point */
            if(p0 != p1)
                return false;
        }

        return true;
    }
};


int main() {
    Solution sol;
    assert(sol.checkStraightLine({{2,1},{4,2},{6,3}}));

    assert(sol.checkStraightLine({{0,0},{0,1},{0,-1}}));

    assert(sol.checkStraightLine({{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}}));
    assert(!sol.checkStraightLine({{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}}));

    return 0;
}
