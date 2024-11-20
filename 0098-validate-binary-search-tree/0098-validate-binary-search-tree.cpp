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
    bool isValidBST(TreeNode* root) {
        long long prevValue = LLONG_MIN;
        return inorder(root, prevValue);
    }
    
    bool inorder(TreeNode* root, long long& prevValue) {
        if (root == nullptr) return true;
        if (!inorder(root->left, prevValue)) return false;
        if (prevValue >= root->val) return false;
        else prevValue = root->val;
        if (!inorder(root->right, prevValue)) return false;
        return true;
    }
};