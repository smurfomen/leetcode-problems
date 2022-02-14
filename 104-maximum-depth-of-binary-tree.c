#include <string>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

/*
    Given the root of a binary tree, return its maximum depth.

    A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

    Example 1:
        Input: root = [3,9,20,null,null,15,7]
        Output: 3

    Example 2:
        Input: root = [1,null,2]
        Output: 2

    Constraints:
        The number of nodes in the tree is in the range [0, 10^4].
        -100 <= Node.val <= 100
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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};


int main(int argc, char * argv[]) {
    Solution sol;

    assert(sol.maxDepth(new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)))) == 3);
    assert(sol.maxDepth(new TreeNode(1, nullptr, new TreeNode(2))) == 2);

    cout << "tests is passed!" << endl;

    return 0;
}
