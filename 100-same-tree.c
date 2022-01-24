#include <string>
#include <cassert>
#include <iostream>

using namespace std;

/*
    Given the roots of two binary trees p and q, write a function to check if they are the same or not.

    Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

    Example 1:
            1          1
          /  \       /  \
         2   3      2   3
    Input: p = [1,2,3], q = [1,2,3]
    Output: true

    Example 2:
            1          1
          /             \
         2              2
    Input: p = [1,2], q = [1,null,2]
    Output: false

    Example 3:
            1          1
          /  \       /  \
         2   1      1   2
    Input: p = [1,2,1], q = [1,1,2]
    Output: false


    Constraints:
    The number of nodes in both trees is in the range [0, 100].
    -104 <= Node.val <= 104
*/


/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    bool isEq(TreeNode * p, TreeNode * q) {
        if(!p && !q)
            return true;
        else if (!p || !q)
            return false;

        return p->val == q->val && isEq(p->left, q->left) && isEq(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
            return isEq(p,q);
    }
};


int main(int argc, char * argv[]) {
    Solution sol;

    assert(sol.isSameTree(new TreeNode(1,
                                       new TreeNode(2),
                                       new TreeNode(3)),
                          new TreeNode(1,
                                       new TreeNode(2),
                                       new TreeNode(3))
                          )
           );

    assert(!sol.isSameTree(new TreeNode(1,
                                        new TreeNode(2),
                                        nullptr),
                           new TreeNode(1,
                                        nullptr,
                                        new TreeNode(2))
                           )
           );
    assert(!sol.isSameTree(new TreeNode(1,
                                        new TreeNode(2),
                                        new TreeNode(1)),
                           new TreeNode(1,
                                        new TreeNode(1),
                                        new TreeNode(2))
                           )
           );

    cout << "tests is passed!" << endl;

    return 0;
}
