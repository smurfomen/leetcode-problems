#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
            Given head, the head of a linked list, determine if the linked list has a cycle in it.

            There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
            Internally, pos is used to denote the index of the node that tail's next pointer is connected to.
            Note that pos is not passed as a parameter.

            Return true if there is a cycle in the linked list. Otherwise, return false.



            Example 1:
                    Input: head = [3,2,0,-4], pos = 1
                    Output: true
                    Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

            Example 2:
                    Input: head = [1,2], pos = 0
                    Output: true
                    Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

            Example 3:
                    Input: head = [1], pos = -1
                    Output: false
                    Explanation: There is no cycle in the linked list.


            Constraints:
                    The number of the nodes in the list is in the range [0, 10^4].
                    -10^5 <= Node.val <= 10^5
                    pos is -1 or a valid index in the linked-list.


            Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode * n) : val(x), next(n) { }
};


class Solution {
public:

    /*

      Using Floyd Algorithm for serach a loop in linked list:

      We have two pointers - fast and slow. Fast can make only two strides per iteration, slow can walk only one step per iteration.

      If linked list have a loop, fast and slow sooner or later will equial.

      Time Complexity: O(n)

      Space Complexity: O(1)

    */
    bool hasCycle(ListNode *head) {
        if(!head) return false;

        /* fast can do only two steps per iteration */
        ListNode * fast = head;

        /* slow can do only one step per iteration */
        ListNode * slow = head;


        /* while fast can do two steps - walk forward */
        while(fast->next && fast->next->next) {

            /* make two steps for fast */
            fast = fast->next->next;

            /* make one step for slow */
            slow = slow->next;

            /* if fast equial slow then linked list has a loop */
            if(fast == slow) return true;
        }

        /* if list is ended then return false couse list does not contain any loop */
        return false;
    }
};

int main() {
    Solution sol;

    {
        ListNode * n0 = new ListNode(3);
        ListNode * n1 = new ListNode(2);
        ListNode * n2 = new ListNode(0);
        ListNode * n3 = new ListNode(-4, n1);
        n0->next = n1;
        n1->next = n2;
        n2->next = n3;

        assert(sol.hasCycle(n0));
    }

    return 0;
}
