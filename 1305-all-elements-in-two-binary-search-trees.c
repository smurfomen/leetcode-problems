#include <string>
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

    Example 1:
          2         1
         / \       / \
        1   4     0   3

        Input: root1 = [2,1,4], root2 = [1,0,3]
        Output: [0,1,1,2,3,4]



    Example 2:
        1          8
         \        /
          8      1

        Input: root1 = [1,null,8], root2 = [8,1]
        Output: [1,1,8,8]



    Example 3:
            0                    60
             \                 /   \
             59              17    74
            /  \            / \   / \
           57  90          6  20 63 97
                                   /
                                  95

        Input: root1 = [0,null,59,57,90], root2 = [60,17,74,6,20,63,97,null,null,null,null,null,null,95]
        Output: [0,6,17,20,57,59,60,63,74,90,95,97]


    Constraints:
        The number of nodes in each tree is in the range [0, 5000].
        -105 <= Node.val <= 105
*/


/**
 * Definition for a binary tree node. */
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

    void plus(TreeNode * node, vector<int> & vec)
    {
        if(!node)
            return;

        plus(node->left, vec);
        vec.push_back(node->val);
        plus(node->right, vec);
    }


    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vec;

        plus(root1, vec);
        plus(root2, vec);
        sort(vec.begin(), vec.end());

        return vec;
    }
};


int main(int argc, char * argv[]) {
    Solution sol;

    vector<int> t1 {0,1,1,2,3,4};
    assert(sol.getAllElements(new TreeNode(2,
                                           new TreeNode(1),
                                           new TreeNode(4)),
                              new TreeNode(1,
                                           new TreeNode(0),
                                           new TreeNode(3))
                        ) == t1
           );

    vector<int> t2 {1,1,8,8};
    assert(sol.getAllElements(new TreeNode(1,
                                           nullptr,
                                           new TreeNode(8)),
                              new TreeNode(8,
                                           new TreeNode(1),
                                           nullptr)
                        ) == t2
           );


    vector<int> t3 {0,6,17,20,57,59,60,63,74,90,95,97};
    assert(sol.getAllElements(new TreeNode(0,
                                           nullptr,
                                           new TreeNode(59,
                                                        new TreeNode(57),
                                                        new TreeNode(90)
                                                        )
                                           ),
                              new TreeNode(60,
                                           new TreeNode(17,
                                                        new TreeNode(6),
                                                        new TreeNode(20)),
                                           new TreeNode(74,
                                                        new TreeNode(63),
                                                        new TreeNode(97,
                                                                     new TreeNode(95),
                                                                     nullptr)
                                                        ))
                        ) == t3
           );



    cout << "tests is passed!" << endl;

    return 0;
}
