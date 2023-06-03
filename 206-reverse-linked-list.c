#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
        Given the head of a singly linked list, reverse the list, and return the reversed list.


        Example 1:
                Input: head = [1,2,3,4,5]
                Output: [5,4,3,2,1]

        Example 2:
                Input: head = [1,2]
                Output: [2,1]

        Example 3:
                Input: head = []
                Output: []


        Constraints:
                The number of nodes in the list is the range [0, 5000].
                -5000 <= Node.val <= 5000


        Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
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

    /*

      Time Complexity: O(n)

      Space Complexity: O(1)

    */
    ListNode* reverseList(ListNode* head) {
        ListNode * cur = head;
        ListNode * prev = nullptr;

        while(cur) {
            /* remember current->next element */
            ListNode * nxt = cur->next;

            /* set pointer to next in current element to prev */
            cur->next = prev;

            /* after that set previous to current */
            prev = cur;

            /* and move current to truly next, which was remembered at begin iteration */
            cur = nxt;
        }

        return prev;
    }
};

int main() {
    Solution sol;

    auto l = sol.reverseList(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))));

    while(l) {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;


    return 0;
}
