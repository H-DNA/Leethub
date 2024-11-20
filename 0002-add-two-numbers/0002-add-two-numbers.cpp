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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = 0;
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        for (; l1 != nullptr && l2 != nullptr; l1 = l1->next, l2 = l2->next) {
            const int tmp = l1->val + l2->val + carry;
            carry = tmp / 10;
            const int res = tmp % 10;
            if (cur == nullptr)
                cur = head = new ListNode(res, nullptr);
            else {
                cur->next = new ListNode(res, nullptr);
                cur = cur->next;
            }
        }
        
        for (; l1 != nullptr; l1 = l1->next) {
            const int tmp = l1->val + carry;
            carry = tmp / 10;
            const int res = tmp % 10;
            cur->next = new ListNode(res, nullptr);
            cur = cur->next;
        }
        for (; l2 != nullptr; l2 = l2->next) {
            const int tmp = l2->val + carry;
            carry = tmp / 10;
            const int res = tmp % 10;
            cur->next = new ListNode(res, nullptr);
            cur = cur->next;
        }
        if (carry == 1)
            cur->next = new ListNode(1, nullptr);
        return head;
    }
};