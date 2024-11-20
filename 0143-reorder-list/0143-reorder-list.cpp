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
    void recur(ListNode*& cur1, ListNode* cur2, bool& stop) {
        if (cur2 == nullptr)
            return;
        recur(cur1, cur2->next, stop);

        if (!stop) {
            bool stop1 = false, stop2 = false;
            if (cur1->next == cur2)
                stop1 = true;
            if (cur1->next->next == cur2)
                stop2 = true;
            stop = stop1 || stop2;

            ListNode* tmp = cur1->next;
            cur1->next = cur2;
            cur2->next = tmp;
            cur1 = tmp;

            if (stop1)
                cur2->next = nullptr;
            if (stop2)
                cur1->next = nullptr;
        }
    }

    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;
            
        ListNode* cur = head;
        bool stop = false;
        recur(cur, head, stop);
    }
};