#include <string>
#include <cassert>
#include <iostream>

using namespace std;

/*
    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
    You may assume the two numbers do not contain any leading zero, except the number 0 itself.


    Example 1:
        2 -> 4 -> 3
        5 -> 6 -> 4
        ___________
        7 -> 0 -> 8

        Input: l1 = [2,4,3], l2 = [5,6,4]
        Output: [7,0,8]
        Explanation: 342 + 465 = 807.

    Example 2:
        Input: l1 = [0], l2 = [0]
        Output: [0]

    Example 3:
        Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
        Output: [8,9,9,9,0,0,0,1]

    Constraints:
        The number of nodes in each linked list is in the range [1, 100].
        0 <= Node.val <= 9
        It is guaranteed that the list represents a number that does not have leading zeros.
*/

/**
 * Definition for singly-linked list.
 *  */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int sum = 0;
            ListNode * head = nullptr;
            ListNode ** node = &head;

            while(l1 || l2 || sum > 0)
            {
                /* sum = prev_sum/10 + l1.val + l2.val */
                {
                    if(l1)
                    {
                        sum+=l1->val;
                        l1=l1->next;
                    }

                    if(l2)
                    {
                        sum += l2->val;
                        l2 = l2->next;
                    }
                }

                (*node) = new ListNode(sum%10);

                sum /= 10;

                /* get next node */
                node = &((*node)->next);
            }
            return head;
        }
};


int main(int argc, char * argv[]) {
    Solution sol;

    auto to_val = [](ListNode * l) {
        int v = 0;
        int c = 1;
        while(l)
        {
            v += (l->val * c);
            c *= 10;
            l = l->next;
        }

        return v;
    };

    assert(to_val(sol.addTwoNumbers(new ListNode(2, new ListNode(4, new ListNode(3))),
                                    new ListNode(5, new ListNode(6, new ListNode(4))))) == 807);

    assert(to_val(sol.addTwoNumbers(new ListNode(0),
                                    new ListNode(0))) == 0);

    assert(to_val(sol.addTwoNumbers(new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))))))),
                                    new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))) == 10009998);



    cout << "tests is passed!" << endl;

    return 0;
}
