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
    TreeNode* recoverFromPreorder(string traversal) {
        int string_index = 0;
        int root_num = readNumber(traversal, string_index);
        TreeNode* root = new TreeNode(root_num);
        try {
            recoverFromPreorder_recur(traversal, 1, root, string_index);
        } catch (...) {
            
        }
        return root;
    }

    void recoverFromPreorder_recur(const string& traversal, int level, TreeNode* current_node, int& string_index) {
        if (string_index == traversal.size()) {
            return;
        }

        int next_level = readLevel(traversal, string_index);
        bool caught_exception = false;
        if (next_level == level) {
            int num = readNumber(traversal, string_index);
            TreeNode* left = new TreeNode(num);
            current_node->left = left;
            try {
                recoverFromPreorder_recur(traversal, level + 1, left, string_index);
            } catch (int e) {
                if (level != e) {
                    throw;
                }
                caught_exception = true;
                next_level = e;
            }
        } else {
            throw next_level;
        }

        if (!caught_exception) {
            next_level = readLevel(traversal, string_index);
        }
        if (next_level == level) {
            int num = readNumber(traversal, string_index);
            TreeNode* right = new TreeNode(num);
            current_node->right = right;
            recoverFromPreorder_recur(traversal, level + 1, right, string_index);
        } else {
            throw next_level;
        }
    }

    inline int readLevel(const string& traversal, int& string_index) {
        int i = string_index;
        while (string_index < traversal.size() && traversal[string_index] == '-') {
            ++string_index;
        }
        return string_index - i;
    }

    inline int readNumber(const string& traversal, int& string_index) {
        int i = string_index;
        while (string_index < traversal.size() && traversal[string_index] <= '9' && traversal[string_index] >= '0') {
            ++string_index;
        }
        return std::stoi(traversal.substr(i, string_index - i));
    }
};