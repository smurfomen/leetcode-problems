#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
        Given the head of a singly linked list, return the middle node of the linked list.

        If there are two middle nodes, return the second middle node.


        Example 1:
                Input: head = [1,2,3,4,5]
                Output: [3,4,5]
                Explanation: The middle node of the list is node 3.

        Example 2:
                Input: head = [1,2,3,4,5,6]
                Output: [4,5,6]
                Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.


        Constraints:
                The number of nodes in the list is in the range [1, 100].
                1 <= Node.val <= 100
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

      Time Complexity: O(1.5n) -> O(n)

      Space Complexity: O(1)

    */
    ListNode* middleNodeNonOptimal(ListNode* head) {
        int count = 1;

        ListNode * tmp = head;

        /* counting elements */
        while(tmp->next) {
            count++;
            tmp = tmp->next;
        }

        int i = 0;
        tmp = head;

        /* go forward before [count/2] element */
        while(i < count/2) {
            tmp = tmp->next;
            i++;
        }

        /* return middle node */
        return tmp;
    }


    /*

      Time Complexity: O(n)

      Space Complexity: O(1)

    */
    ListNode* middleNode(ListNode* head) {
        int count = 1;

        /* make pair {index node, node} */
        pair<int, ListNode * > mid { count/2 /* 0 */, head};

        /* temp node for walk */
        ListNode * tmp = head;

        /* go forward to end list */
        while(tmp->next) {
            tmp = tmp->next;

            count++;

            /* if middle between 1 and count not equial current index of middle element then update middle index and move middle node forward to next node */
            if(count / 2 != mid.first)
                mid = {count / 2, mid.second->next };
        }

        return mid.second;
    }
};

int main() {
    Solution sol;

    cout << sol.middleNode(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))))->val << endl;
    cout << sol.middleNode(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))))->val << endl;

    return 0;
}
