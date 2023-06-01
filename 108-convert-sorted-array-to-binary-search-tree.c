#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
        Given an integer array nums where the elements are sorted in ascending order, convert it to a
        height-balanced binary search tree.



        Example 1:
                Input: nums = [-10,-3,0,5,9]
                Output: [0,-3,9,-10,null,5]
                Explanation: [0,-10,5,null,-3,null,9] is also accepted:

        Example 2:
                Input: nums = [1,3]
                Output: [3,1]
                Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.


        Constraints:
                1 <= nums.length <= 104
                -104 <= nums[i] <= 104
                nums is sorted in a strictly increasing order.
*/




/*

  Time Complexity: O(n)

  Space Complexity: O(n + sizeof(TreeNode*) * 2) -> O(n)

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
    TreeNode * impl(vector<int>& nums, int l, int r) {
        /* if left index > right index in nums then return null */
        if(l > r)
            return nullptr;

        /* if left index equial right index then return leaf node */
        if(l == r)
            return new TreeNode(nums[l]);

        /* find middle index */
        int mid = (l + r)/2;

        /* generate left subtree */
        TreeNode * left = impl(nums, l, mid - 1);

        /* generate right subtree */
        TreeNode * right = impl(nums, mid+1, r);

        /* insert left and right subtree into root and return it for insert this tree into upper tree */
        TreeNode * node = new TreeNode(nums[mid], left, right);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int> nums) {
        return impl(nums, 0, nums.size() - 1);
    }
};


void print(TreeNode * t) {
    if(!t)
        cout << " null ";
    else
    {
        cout << " " << t->val << " ";
        print(t->left);
        print(t->right);
    }
}

int main() {
    Solution sol;

    print(sol.sortedArrayToBST({-10,-3,0,5,9}));

    return 0;
}
