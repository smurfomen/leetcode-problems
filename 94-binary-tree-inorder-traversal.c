#include <string>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/*
    Given the root of a binary tree, return the inorder traversal of its nodes' values.

            1
          /  \
             2
            / \
           3

    Example 1:
        Input: root = [1,null,2,3]
        Output: [1,3,2]

    Example 2:
        Input: root = []
        Output: []

    Example 3:
        Input: root = [1]
        Output: [1]

    Constraints:
        The number of nodes in the tree is in the range [0, 100].
        -100 <= Node.val <= 100

*/


/**
 * Definition for a binary tree node.
 */
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
    void walk(TreeNode * root, vector<int> & store)
    {
        if(root == nullptr)
            return;

        walk(root->left, store);
        store.push_back(root->val);
        walk(root->right, store);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> store;
        walk(root, store);
        return store;
    }
};

int main(int argc, char * argv[]) {
    Solution sol;

    assert((sol.inorderTraversal(new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr))) == vector<int>{1,3,2}));

    cout << "tests is passed!" << endl;

    return 0;
}
