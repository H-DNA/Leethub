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
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while (cur != nullptr && cur->next != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = cur;
            if (prev == nullptr)
                head = tmp;
            else prev->next = tmp;
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};