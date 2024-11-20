class IntervalTree {
    enum Color {
        RED, BLACK  
    };
    struct Node {
        Node* left;
        Node* right;
        Node* p;
        Color color;
        int start;
        int end;
        int furthest_end;
    };
public:
    void insert(int start, int end) {
        Node* cur = head;
        Node* prev = NIL_p;
        if (cur == NIL_p) {
            head = new Node {NIL_p, NIL_p, NIL_p, BLACK, start, end, end};
            return;
        }
        
        while (cur != NIL_p) {
            prev = cur;
            cur->furthest_end = max(cur->furthest_end, end);
            if (cur->start < start)
                cur = cur->right;
            else cur = cur->left;
        }
        
        Node* new_node = new Node {NIL_p, NIL_p, prev, RED, start, end, end};
        if (prev->start < start) prev->right = new_node;
        else prev->left = new_node;
        
        insert_fixup(new_node);
    }
    
    bool checkNoOverlap(int start, int end) {
        Node* cur = head;
        while (cur != NIL_p) {
            if (doesOverlap(cur->start, cur->end, start, end)) return false;
            if (start < cur->start) cur = cur->left;
            else if (cur->left->furthest_end <= start) cur = cur->right;
            else return false;
        }
        return true;
    }
    
    bool doesOverlap(int start1, int end1, int start2, int end2) {
        return ((start1 <= start2 && start2 < end1) || (start2 <= start1 && start1 < end2));
    }
    
    ~IntervalTree() {
        free_subtree(head);
    }
private:
    void insert_fixup(Node* n) {
        while (n->p->color == RED) {
            Node* m = n->p->p;
            if (n->p == m->left) {
                if (m->right->color == RED) {
                    n->p->color = BLACK;
                    m->right->color = BLACK;
                    m->color = RED;
                    n = m;
                }
                else {
                    if (n == n->p->right) {
                        n = n->p;
                        left_rotate(n);
                    }
                    m->color = RED;
                    n->p->color = BLACK;
                    right_rotate(m);
                }
            }
            else {
                if (m->left->color == RED) {
                    n->p->color = BLACK;
                    m->left->color = BLACK;
                    m->color = RED;
                    n = m;
                }
                else {
                    if (n == n->p->left) {
                        n = n->p;
                        right_rotate(n);
                    }
                    m->color = RED;
                    n->p->color = BLACK;
                    left_rotate(m);
                }
            }
        }
        head->color = BLACK;
    }
    
    void left_rotate(Node* u) {
        Node* v = u->right;
        if (v == NIL_p) return;
        v->p = u->p;
        if (u->p == NIL_p)
            head = v;
        else if (u->p->right == u) u->p->right = v;
        else u->p->left = v;
        u->p = v;
        u->right = v->left;
        v->left->p = u;
        v->left = u;
        
        u->furthest_end = max(max(u->end, u->left->furthest_end), u->right->furthest_end);
        v->furthest_end = max(u->furthest_end, v->furthest_end);
    }
    
    void right_rotate(Node* u) {
        Node* v = u->left;
        if (v == NIL_p) return;
        v->p = u->p;
        if (u->p == NIL_p)
            head = v;
        else if (u->p->right == u) u->p->right = v;
        else u->p->left = v;
        u->p = v;
        u->left = v->right;
        v->right->p = u;
        v->right = u;
        
        
        u->furthest_end = max(max(u->end, u->right->furthest_end), u->left->furthest_end);
        v->furthest_end = max(u->furthest_end, v->furthest_end);
    }
    
    Node* head = NIL_p;
    static Node NIL;
    static constexpr Node* NIL_p = &NIL;
    
    void free_subtree(Node* cur) {
        if (cur == NIL_p) return;
        free_subtree(cur->left);
        free_subtree(cur->right);
        delete cur;
    }
};

IntervalTree::Node IntervalTree::NIL = {&NIL, &NIL, &NIL, BLACK, -1, -1, -1};

class MyCalendar {
    IntervalTree tree;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if (tree.checkNoOverlap(start, end)) {
            tree.insert(start, end);
            return true;
        }
        else return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */