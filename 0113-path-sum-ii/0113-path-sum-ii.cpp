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
    void recur(TreeNode* root, int sum, int targetSum, vector<int>& curvec, vector<vector<int>>& res) {
        curvec.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            if (sum + root->val == targetSum)
                res.push_back(curvec);
        } else {
            if (root->left != nullptr)
                recur(root->left, sum + root->val, targetSum, curvec, res);
            
            
            if (root->right != nullptr)
                recur(root->right, sum + root->val, targetSum, curvec, res);
        }

        curvec.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return {};
        vector<int> vec;
        vector<vector<int>> res;
        recur(root, 0, targetSum, vec, res);
        return res;
    }
};