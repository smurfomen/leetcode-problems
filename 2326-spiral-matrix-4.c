#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
        You are given two integers m and n, which represent the dimensions of a matrix.

        You are also given the head of a linked list of integers.

        Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix.
        If there are remaining empty spaces, fill them with -1.

        Return the generated matrix.



        Example 1:
                Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
                Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
                Explanation: The diagram above shows how the values are printed in the matrix.
                Note that the remaining spaces in the matrix are filled with -1.

        Example 2:
                Input: m = 1, n = 4, head = [0,1,2]
                Output: [[0,1,2,-1]]
                Explanation: The diagram above shows how the values are printed from left to right in the matrix.
                The last space in the matrix is set to -1.


        Constraints:

                1 <= m, n <= 10^5
                1 <= m * n <= 10^5
                The number of nodes in the list is in the range [1, m * n].
                0 <= Node.val <= 1000
*/



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:

    /* return current element list and go forward head if head is non null, otherwise return -1 */
    inline int next(ListNode *& head) {
        int i = -1;
        if(head) {
            i = head->val;
            head = head->next;
        }
        return i;
    }
    /*

      Time Complexity: O(n)

      Space Complexity: O(n) -> O(1)

    */
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> result(m, vector<int>(n, -1));

        int r0 = 0, r1 = m-1, c0 = 0, c1 = n-1;

        /* go spiral */
        while(r0 <= r1 && c0 <= c1 && head) {

            /* left to right starts from c0 */
            for(int c = c0; c <= c1; ++c) {
                result[r0][c] = next(head);
            }

            /* top to bottom starts from r0 + 1, cause [r0][c1] already filled when walked left to right */
            for(int r = r0+1; r <= r1; ++r) {
                result[r][c1] = next(head);
            }

            /* if we can walk right and top */
            if(c0 < c1 && r0 < r1) {
                /* right to left starts from c1-1 cause [r1][c1] already filled when walked top to bottom */
                for(int c = c1-1; c >= c0; --c) {
                    result[r1][c] = next(head);
                }

                /* bottom to top starts from r1-1 cause [r1][c0] already filled when walked right to left */
                for(int r = r1-1; r > r0; --r) {
                    result[r][c0] = next(head);
                }
            }


            /* narrow ranges */
            c0++;
            r0++;
            c1--;
            r1--;
        }

        return result;
    }
};



int main() {
    Solution sol;

    auto print = [](vector<vector<int>> v) {
        for(auto r : v) {
            for(auto c : r)
                cout << c << (c < 100 ? c < 10 ? c < 0 ? "  " : "   " : "  " : " ");
            cout << endl;
        }
        cout << endl;
    };


    auto gen = [](vector<int> v) {
        ListNode * head = nullptr;
        ListNode * tail = nullptr;
        for(auto i : v) {
            if(!head) {
                head = tail = new ListNode(i);
            }
            else {
                tail->next = new ListNode(i);
                tail = tail->next;
            }
        }

        return head;
    };

    print(sol.spiralMatrix(3,5, gen({3,0,2,6,8,1,7,9,4,2,5,5,0})));
    print(sol.spiralMatrix(1,4, gen({0,1,2})));

    return 0;
}
