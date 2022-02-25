#include <string>
#include <cassert>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*

*/
const double EPS = 1E-9;

struct Point {
    Point(double ax, double ay)
        : x(ax), y(ay)
    { }

    double x, y;
};


struct Line {
    Line(const Point & a, const Point & b)
        : a(a), b(b)
    { }

    bool intersect_1(double a, double b, double c, double d) const {
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return max(a,c) <= min(b,d);
    }

    double det(double a, double b, double c, double d) const {
        return a * d - b * c;
    }

    bool between(double a, double b, double c) const {
        return min(a, b) <= c + EPS && c <= max(a,b) + EPS;
    }

    bool intersect(const Line & rhs) const {
        int A1 = a.y - b.y, B1 = b.x - a.x, C1 = -A1*a.x - B1*a.y;
        int A2 = rhs.a.y - rhs.b.y, B2 = rhs.b.x - rhs.a.x, C2 = -A2 * rhs.a.x - B2*rhs.a.y;
        int zn = det(A1, B1, A2, B2);

        if(zn != 0)
        {
            double x = - det (C1, B1, C2, B2) * 1. / zn;
            double y = - det (A1, C1, A2, C2) * 1. / zn;
            return between (a.x, b.x, x) && between (a.y, b.y, y)
                    && between (rhs.a.x, rhs.b.x, x) && between (rhs.a.y, rhs.b.y, y);
        }

        else {
            return det (A1, C1, A2, C2) == 0 && det (B1, C1, B2, C2) == 0
                        && intersect_1 (a.x, b.x, rhs.a.x, rhs.b.x)
                        && intersect_1 (a.y, b.y, rhs.a.y, rhs.b.y);
        }
    }

    Point a, b;
};

struct Polygon {
    Polygon(const Line & ab, const Line & bc, const Line & ca)
        : ab(ab), bc(bc), ca(ca)
    { }

    Polygon(const Point & a, const Point & b, const Point & c)
        : ab(Line(a,b)), bc(Line(b, c)), ca(Line(a,c))
    { }

    bool intersect(const Polygon & rhs) const {
        auto l1 = lines();
        auto l2 = rhs.lines();

        for(auto it1 : l1) {
            for(auto it2 : l2) {
                if(it1.intersect(it2))
                    return true;
            }
        }

        return false;
    }

    vector<Line> lines() const
    { return vector<Line>{ab, bc, ca}; }

    Line ab, bc, ca;
};

class Solution {
public:
    int findIntersectedPolygons(vector<double> nums) {
        int n = nums.size()/6;
        vector<Polygon> p;
        for(int i = 0; i < nums.size(); i+=6) {
            p.push_back(Polygon(Point(nums[i+0], nums[i+1]), Point(nums[i+2], nums[i+3]), Point(nums[i+4], nums[i+5])));
        }

        vector<Polygon> result;
        for(auto && c : p)
        {
            for(auto && tmp : p)
            {
                Polygon * p1 = &c;
                Polygon * p2 = &tmp;

                if(p1 == p2)
                    continue;

                if(c.intersect(tmp))
                {
                    result.push_back(c);
                    break;
                }
            }
        }


        return result.size();
    }
};


int main(int argc, char * argv[]) {
    Solution sol;
    cout << sol.findIntersectedPolygons({3, 0, 0, 0, 1, 2,      3, 0, 1, 15, 0, 50                          }) << endl; // 2
    cout << sol.findIntersectedPolygons({3, 0, 0, 0, 0, 3,      3, 0, 0, 0, 3, 3,    33, 30, 30, 30, 30, 33 }) << endl; // 2

    cout << sol.findIntersectedPolygons({0, 0, 0, 5, 3, 0,      7, 8, 11, 11, 12, 10}) << endl; // 0

    bool a = Line(Point(0,0), Point(3,3)).intersect(Line(Point(3,0), Point(0,3)));

    if(a)
        cout << "intersected" << endl;

    cout << "tests is passed!" << endl;

    return 0;
}
