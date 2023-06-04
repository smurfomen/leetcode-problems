#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/*
        Given the head of a singly linked list, return true if it is a
        palindrome or false otherwise.


        Example 1:
                Input: head = [1,2,2,1]
                Output: true

        Example 2:
                Input: head = [1,2]
                Output: false


        Constraints:
                The number of nodes in the list is in the range [1, 10^5].
                0 <= Node.val <= 9
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/* this solution don't broke original list */
class SolutionForNotLongLists {
public:

    /*

      Time Complexity: O(n)

      Space Complexity: O(1)

    */
    int toNum(const ListNode * head, const ListNode * end) {
        const ListNode * cur = head;

        int num = 0;
        while(cur != end) {
            num = num * 10 + cur->val;
            cur = cur->next;
        }

        return num;
    }

    /*

      Time Complexity: O(n)

      Space Complexity: O(1)

    */
    int toReversedNum(const ListNode * head, const ListNode * end) {
        if(head->next == end)
            return head->val;

        return toReversedNum(head->next, end) * 10 + head->val;
    }


    /*

      Time Complexity: O(n/2 + n/2 + n/2) -> O(1.5n) -> O(n)

      Space Complexity: O(1)

    */
    bool isPalindrome(const ListNode* head) {
        const ListNode * fast = head;
        const ListNode * middle = head;
        int count = 1;

        /* find middle element and counting total count element */
        while(fast && fast->next) {
            middle = middle->next;
            fast = fast->next->next;
            count += (fast ? 2 : 1);
        }


        /* if count elements is even then middle is start element which begins second part,
                 * otherwise middle is include both to first and to second parts list */
        int firstPart = toNum(head, count % 2 == 0 ? middle : middle->next);

        /* reversed calc second part before the end list */
        int secondPart = toReversedNum(middle, nullptr);

        /* return first digit equial second digit */
        return firstPart == secondPart;
    }
};


/* this solution broke original list */
class Solution {
public:

    /*

      Time Complexity: O(n)

      Space Complexity: O(1)

    */
    ListNode * reverse(ListNode * head) {
        ListNode * prev = nullptr;

        while(head) {
            ListNode * nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }

        return prev;
    }


    /*

      Time Complexity: O(n/2 + n/2 + n/2) -> O(1.5n) -> O(n)

      Space Complexity: O(1)

    */
    bool isPalindrome(ListNode* head) {
        ListNode * fast = head;
        ListNode * slow = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        /* middle element */
        ListNode * mid = slow;

        /* reverse range in list starts from middle to the end */
        ListNode * h2 = reverse(mid);

        ListNode * h1 = head;

        while(h2) {
            /* if count elements in list not even, in last iteration */
            if(h1->val != h2->val)
                return false;

            h1 = h1->next;
            h2 = h2->next;
        }

        return true;
    }
};



int main() {
    Solution sol;

    cout << sol.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(1)))) << endl;
    cout << sol.isPalindrome(new ListNode(0, new ListNode(0))) << endl;
    cout << sol.isPalindrome(new ListNode(1)) << endl;
    cout << sol.isPalindrome(new ListNode(1, new ListNode(0, new ListNode(1, new ListNode(1))))) << endl;
    cout << sol.isPalindrome(new ListNode(1, new ListNode(1, new ListNode(0, new ListNode(1))))) << endl;
    cout << sol.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))))) << endl;

    return 0;
}
