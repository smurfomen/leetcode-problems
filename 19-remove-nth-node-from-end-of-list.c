#include <string>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/*
    Given the head of a linked list, remove the nth node from the end of the list and return its head.

    Example 1:
        Input: head = [1,2,3,4,5], n = 2
        Output: [1,2,3,5]

    Example 2:
        Input: head = [1], n = 1
        Output: []

    Example 3:
        Input: head = [1,2], n = 1
        Output: [1]

    Constraints:
        The number of nodes in the list is sz.
        1 <= sz <= 30
        0 <= Node.val <= 100
        1 <= n <= sz
*/
/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> tmp;
        int size = 0;

        do {
            size++;
            tmp.push_back(head);
            head = head->next;
        } while(head);

        head = tmp[0];

        int indx = size - n;

        if(indx == 0)
            head = head->next;

        else if(indx == size - 1)
           tmp[indx-1]->next = nullptr;

        else if(indx > 0)
            tmp[indx - 1]->next = tmp[indx+1];

        return head;
    }
};


int main(int argc, char * argv[]) {
    Solution sol;

    auto to_vec = [](ListNode * node){
        vector<int> vec;
        while(node)
        {
            vec.push_back(node->val);
            node = node->next;
        }

        return vec;
    };

    assert((to_vec(sol.removeNthFromEnd(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))), 2)) == vector<int>{1,2,3,5}));

    assert((to_vec(sol.removeNthFromEnd(new ListNode(1), 1)) == vector<int>{}));

    assert((to_vec(sol.removeNthFromEnd(new ListNode(1, new ListNode(2)), 1)) == vector<int>{1}));

    cout << "tests is passed!" << endl;

    return 0;
}
