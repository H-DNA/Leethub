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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
            return nullptr;
        
        ListNode* tail = head;
        int count = 1; 
        for (; tail->next != nullptr; tail = tail->next)
            ++count;
        
        k %= count;
        if (k == 0)
            return head;
        k = count - k;
        ListNode* prev = nullptr;
        ListNode* cur = head;
        for (int i = 0; i < k; ++i) {
            prev = cur;
            cur = cur->next;
        }
        
        tail->next = head;
        head = cur;
        prev->next = nullptr;
        
        return head;
        
        
    }
};