/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr || root->left == nullptr) return root;
        root->left->next = root->right;
        connect_subtrees(root->left, root->right);
        connect(root->left);
        connect(root->right);
        return root;
    }
    
    void connect_subtrees(Node* rootl, Node* rootr) {
        if (rootl->left == nullptr) return;
        rootl->right->next = rootr->left;
        connect_subtrees(rootl->right, rootr->left);
    }
    
    
};