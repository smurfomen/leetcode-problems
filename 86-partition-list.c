#include <string>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/*
    Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

    You should preserve the original relative order of the nodes in each of the two partitions.


    Example 1:

        1 -> 4 -> 3 -> 2 -> 5 -> 2
                  ↓
                  ↓
                  ↓
        1 -> 2 -> 2 -> 4 -> 3 -> 5

        Input: head = [1,4,3,2,5,2], x = 3
        Output: [1,2,2,4,3,5]

    Example 2:
        Input: head = [2,1], x = 2
        Output: [1,2]


    Constraints:
        The number of nodes in the list is in the range [0, 200].
        -100 <= Node.val <= 100
        -200 <= x <= 200
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
    ListNode* partition(ListNode* head, int x) {
        ListNode * it = head;

        ListNode * beg = nullptr; ListNode * end = nullptr;
        ListNode * prev = nullptr;

        auto move_next = [](ListNode *& node){
            node = node->next;
        };

        while(it)
        {
            if(it->val >= x){
                beg = it;
                end = beg;
                break;
            }
            else
                prev = it;

            move_next(it);
        }


        while(it)
        {
            if(it->val >= x)
            {
                end = it;
            }
            else {
                if(prev)
                {
                    prev->next = it;
                }

                else
                    head = it;

                end->next = it->next;
                it->next = beg;

                prev = it;
                it = end;
            }

            move_next(it);
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

    auto make = [](std::initializer_list<int> l) {
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

    assert((to_vec(sol.partition(make({1,4,3,2,5,2}), 3)) == std::vector<int>{1, 2, 2, 4, 3, 5}));
    assert((to_vec(sol.partition(make({}), 2)) == std::vector<int>{}));
    assert((to_vec(sol.partition(make({2, 1}), 2)) == std::vector<int>{1, 2}));
    assert((to_vec(sol.partition(make({4,3,2,5,2}), 3)) == std::vector<int>{2, 2, 4, 3, 5}));

    cout << "tests is passed!" << endl;

    return 0;
}






















