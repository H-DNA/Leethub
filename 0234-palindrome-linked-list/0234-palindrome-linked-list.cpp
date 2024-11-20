/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void recur(ListNode*& curhead, ListNode* curtail, bool& stop, bool& res) {
        if (curtail == nullptr)
            return;
        recur(curhead, curtail->next, stop, res);

        if (!stop) {
            if (curhead == curtail || curtail->next == curhead) {
                stop = true;
                return;
            }

            if (curhead->val != curtail->val) {
                stop = true;
                res = false;
            } 
            
            curhead = curhead->next;
        }
    }

    bool isPalindrome(ListNode* head) {
        bool stop = false;
        bool res = true;
        recur(head, head, stop, res);

        return res;
    }
};