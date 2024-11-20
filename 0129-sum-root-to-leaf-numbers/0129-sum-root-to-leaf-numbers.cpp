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
    void recur(TreeNode* root, int curnum, int& res) {
        if (root->left == root->right)
            res += curnum * 10 + root->val;
        else {
            if (root->left != nullptr)
                recur(root->left, curnum * 10 + root->val, res);
            if (root->right != nullptr)
                recur(root->right, curnum * 10 + root->val, res);
        }
    }

    int sumNumbers(TreeNode* root) {
        int res = 0;
        recur(root, 0, res);
        return res;
    }
};