#include <string>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/*
    Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
    Example 1:
        1 -> 2 -> 3 -> 4
                ↓
        2 -> 1 -> 4 -> 3

        Input: head = [1,2,3,4]
        Output: [2,1,4,3]

    Example 2:
        Input: head = []
        Output: []

    Example 3:
        Input: head = [1]
        Output: [1]


    Constraints:
        The number of nodes in the list is in the range [0, 100].
        0 <= Node.val <= 100

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
    ListNode* swapPairs(ListNode* head) {
        ListNode * first = head;
        ListNode * need_link = nullptr;
        while(first)
        {
            ListNode * second = first->next;
            if(second)
            {
                first->next = second->next;

                second->next = first;

                if(need_link)
                    need_link->next = second;

                if(first == head)
                    head = second;
            }

            need_link = first;
            first = first->next;
        }

        return head;
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

    assert((to_vec(sol.swapPairs(make({1, 2, 3, 4}))) == std::vector<int>{2, 1, 4, 3}));
    assert((to_vec(sol.swapPairs(make({}))) == std::vector<int>{}));
    assert((to_vec(sol.swapPairs(make({1}))) == std::vector<int>{1}));
    assert((to_vec(sol.swapPairs(make({1, 2, 3, 4, 5}))) == std::vector<int>{2, 1, 4, 3, 5}));

    cout << "tests is passed!" << endl;

    return 0;
}
