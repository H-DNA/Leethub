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
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum, int sum = 0) {

        if (root == nullptr)
            return false;

        if (root->left == nullptr && root->right == nullptr) {
            if (sum + root->val == targetSum)
                return true;
        } else {
            if (root->left != nullptr) {
                if (hasPathSum(root->left, targetSum, sum + root->val))
                    return true;
            }

            if (root->right != nullptr) {
                if (hasPathSum(root->right, targetSum, sum + root->val))
                    return true; 
            }
        }
        
        return false;
    }
};