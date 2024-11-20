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
    ListNode* middleNode(ListNode* head) {
        ListNode* fir = head->next;
        ListNode* sec = head->next;
        if (sec == nullptr) return head;
        while (sec->next != nullptr && sec->next->next != nullptr) {
            fir = fir->next;
            sec = sec->next->next;
        }
        return fir;
    }
};