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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        std::reverse(postorder.begin(), postorder.end());
        return constructFromPrePost_recur(preorder, 0, preorder.size(), postorder, 0, postorder.size());
    }

    TreeNode* constructFromPrePost_recur(vector<int>& preorder, int preorder_start_idx, int preorder_end_idx, vector<int>& postorder, int postorder_start_idx, int postorder_end_idx) {
        if (postorder_start_idx >= postorder_end_idx) return NULL;
        if (preorder_start_idx >= preorder_end_idx) return NULL;

        TreeNode* root = new TreeNode(preorder[preorder_start_idx]);
        int left_postorder_start_idx;
        for (left_postorder_start_idx = postorder_start_idx + 1; left_postorder_start_idx < postorder_end_idx; ++left_postorder_start_idx) {
            if (preorder[preorder_start_idx + 1] == postorder[left_postorder_start_idx]) {
                break;
            }
        }
        int left_length = postorder_end_idx - left_postorder_start_idx;
        root->left = constructFromPrePost_recur(preorder, preorder_start_idx + 1, preorder_start_idx + 1 + left_length, postorder, left_postorder_start_idx, postorder_end_idx);
        root->right = constructFromPrePost_recur(preorder, preorder_start_idx + 1 + left_length, preorder_end_idx, postorder, postorder_start_idx + 1, left_postorder_start_idx);
        return root;
    }
};