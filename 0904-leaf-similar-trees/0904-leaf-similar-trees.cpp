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
    void collectLeaves(TreeNode* root, vector<int>& res) {
        if (root->left == nullptr && root->right == nullptr) {
            return res.push_back(root->val);
        }
        if (root->left != nullptr) {
            collectLeaves(root->left, res);
        }
        if (root->right != nullptr) {
            collectLeaves(root->right, res);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2 == nullptr;
        if (root2 == nullptr) return false;

        vector<int> seq1;
        collectLeaves(root1, seq1);
        vector<int> seq2;
        collectLeaves(root2, seq2);

        if (seq1.size() != seq2.size()) {
            return false;
        }

        for (int i = 0; i < seq1.size(); ++i) {
            if (seq1[i] != seq2[i]) {
                return false;
            }
        }

        return true;
    }
};