/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <climits>

class Solution {
public:
    void longestPathRecur(TreeNode* root, int sum, int& res) {
        if (res < sum)
            res = sum;

        if (root->left != nullptr)
            longestPathRecur(root->left, sum + root->left->val, res);

        if (root->right != nullptr)
            longestPathRecur(root->right, sum + root->right->val, res);   
    }

    int longestPath(TreeNode* root) {
        int res = INT_MIN;
        longestPathRecur(root, root->val, res);
        return res;
    }

    int maxPathSum(TreeNode* root) {
    
        if (root->left == nullptr && root->right == nullptr)
            return root->val;

        int res = INT_MIN;

        if (root->right != nullptr) {
            int rsum = maxPathSum(root->right);
            if (res < rsum)
                res = rsum;
        }

        if (root->left != nullptr) {
            int lsum = maxPathSum(root->left);
            if (res < lsum)
                res = lsum;
        }

        int rlpth = (root->right != nullptr) ? longestPath(root->right) : 0;
        int llpth = (root->left != nullptr) ? longestPath(root->left) : 0;

        int psum = ((rlpth < 0) ? 0 : rlpth) + ((llpth < 0) ? 0 : llpth) + root->val;
        if (res < psum)
            res = psum;
    

        return res;
    }
};