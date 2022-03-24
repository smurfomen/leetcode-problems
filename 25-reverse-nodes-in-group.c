#include <string>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/*
    Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
    k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

    You may not alter the values in the list's nodes, only nodes themselves may be changed.

    Example 1:
        Input: head = [1,2,3,4,5], k = 2
        Output: [2,1,4,3,5]

    Example 2:
        Input: head = [1,2,3,4,5], k = 3
        Output: [3,2,1,4,5]


    Constraints:
        The number of nodes in the list is n.
        1 <= k <= n <= 5000
        0 <= Node.val <= 1000

    Follow-up: Can you solve the problem in O(1) extra memory space?
*/

/**
 * Definition for singly-linked list.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return nullptr;

        ListNode * temp = head;

        for(int i = 0; i < k; i++)
        {
            if(!temp)
                return head;

            temp = temp->next;
        }

        ListNode * cur = head;
        ListNode * prev = nullptr;
        ListNode * ptr;

        int c = 0;
        while(c < k) {
            ptr = cur->next;
            cur->next = prev;
            prev = cur;
            cur = ptr;
            ++c;
        }

        head->next = reverseKGroup(ptr, k);

        return prev;
    }
};

int main(int argc, char * argv[]) {
    Solution sol;

    auto print = [](ListNode * root){
        while(root) {
            cout << root->val << " ";
            root = root->next;
        }
        cout << endl;
    };

    auto make = [=](std::initializer_list<int> l) {
        ListNode * head = nullptr;
        ListNode * cur = head;
        for(auto it : l) {
            auto tmp = new ListNode(it);
            if(cur)
                cur->next = tmp;
            else
                head = tmp;

            cur = tmp;
        }

        return head;
    };

    auto to_vec = [](ListNode * n){
        std::vector<int> result;
        while(n)
        {
            result.push_back(n->val);
            n = n->next;
        }

        return result;
    };


    assert((to_vec(sol.reverseKGroup(make({1, 2}), 2)) == vector<int>{2,1}));
    assert((to_vec(sol.reverseKGroup(make({1, 2, 3}), 2)) == vector<int>{2,1,3}));
    assert((to_vec(sol.reverseKGroup(make({1, 2, 3, 4, 5}), 3)) == vector<int>{3,2,1,4,5}));

    cout << "tests is passed!" << endl;

    return 0;
}
