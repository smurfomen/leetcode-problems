#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


/*
        Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

        There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
        Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed).
        It is -1 if there is no cycle. Note that pos is not passed as a parameter.

        Do not modify the linked list.



        Example 1:
                Input: head = [3,2,0,-4], pos = 1
                Output: tail connects to node index 1
                Explanation: There is a cycle in the linked list, where tail connects to the second node.

        Example 2:
                Input: head = [1,2], pos = 0
                Output: tail connects to node index 0
                Explanation: There is a cycle in the linked list, where tail connects to the first node.

        Example 3:
                Input: head = [1], pos = -1
                Output: no cycle
                Explanation: There is no cycle in the linked list.


        Constraints:
                The number of the nodes in the list is in the range [0, 104].
                -10^5 <= Node.val <= 10^5
                pos is -1 or a valid index in the linked-list.

        Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /*

      Time Complexity: O(n)
      Space Complexity: O(1)

    */
    ListNode *detectCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;

        /* go forward and move slow by one step per iter and fast by two steps per iter */
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            /* if in one moment slow == fast by addreses then list contains loop */
            if(slow == fast) {

                ListNode * tmp = head;

                /* go forward from head and from slow slowly by one step per iter while tmp != slow */
                while(tmp != slow) {
                    slow = slow->next;
                    tmp = tmp->next;
                }

                /* at the end tmp points to begin loop into list */
                return tmp;
            }

        }

        return nullptr;
    }
};



int main() {
    Solution sol;


    auto gen = [](vector<int> v, int loopidx = -1) -> ListNode* {
        if(v.empty())
            return nullptr;

        ListNode * head = nullptr;
        ListNode * tail = nullptr;

        for(auto i : v) {
            if(!head) {
                head = tail = new ListNode(i);
            }
            else
            {
                tail->next = new ListNode(i);
                tail = tail->next;
            }
        }


        if(loopidx > -1) {
            ListNode *tmp = head;
            for(int i = 0; i < loopidx; ++i) {
                tmp = tmp->next;
            }

            tail->next = tmp;
        }

        return head;
    };


    assert(sol.detectCycle(gen({3,2,0,-4}, 1))->val == 2);
    assert(sol.detectCycle(gen({1,2}, 0))->val == 1);
    assert(sol.detectCycle(gen({1})) == nullptr);

    return 0;
}
