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
    int pseudoPalindromicPaths (TreeNode* root) {
        if (root == nullptr) return 0;
        bool is_count_odd[10]{};
        int odd_count = 0;
        return recur(is_count_odd, odd_count, root);
    }
    
    int recur(bool* is_count_odd, int& odd_count, TreeNode* root) {
        int num = root->val;
        int old_odd_count = odd_count;
        if (!is_count_odd[num])
            ++odd_count;
        else --odd_count;
        is_count_odd[num] = !is_count_odd[num];
        
        int res = 0;
        if (root->left != nullptr)
            res += recur(is_count_odd, odd_count, root->left);
        if (root->right != nullptr)
            res += recur(is_count_odd, odd_count, root->right);
        if (root->left == nullptr and root->right == nullptr)
            res += (odd_count <= 1) ? 1 : 0;
        
        is_count_odd[num] = !is_count_odd[num];
        odd_count = old_odd_count;
        return res;
    }
};