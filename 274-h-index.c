#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
            Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper,
            return the researcher's h-index.

            According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher
            has published at least h papers that have each been cited at least h times.



            Example 1:
                    Input: citations = [3,0,6,1,5]
                    Output: 3
                    Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
                    Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.

            Example 2:
                    Input: citations = [1,3,1]
                    Output: 1


            Constraints:
                    n == citations.length
                    1 <= n <= 5000
                    0 <= citations[i] <= 1000
*/




/* time O(N) + O(N * logN) and space O(1) */
class Solution {
public:
    /*
        Example: 3,0,6,1,5 -> 0,1,3,5,6

        6 -> +1
        5 -> +1
        3 -> +1
        1 -> break;

        result is 3
    */
    int hIndex(vector<int> citations) {
        /* need sort citations and walk from end citations to begin */
        sort(citations.begin(), citations.end());

        int result = 0;
        int nCount = citations.size();

        /* walk from right to left */
        for(int i = nCount - 1; i >= 0; --i) {

            /* if citations[i] greater or equial that count steps we walked - increment hindex */
            if(citations[i] >= nCount - i)
                result++;

            /* or if citations[i] less that count steps we walked - other elements will be less couse citations is sorted */
            else break;
        }

        return result;
    }
};



int main() {
    Solution sol;

    assert(sol.hIndex({3,0,6,1,5}) == 3);
    assert(sol.hIndex({3,0,6,3,3,1,5}) == 3);
    assert(sol.hIndex({1,3,1}) == 1);
    assert(sol.hIndex({6}) == 1);
    assert(sol.hIndex({1000, 990, 1, 1000,1000}) == 4);


    return 0;
}
