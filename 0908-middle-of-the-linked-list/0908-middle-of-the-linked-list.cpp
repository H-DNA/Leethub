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
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head->next;
        if (fast_ptr == nullptr) {
            return slow_ptr;
        }
        while (true) {
            slow_ptr = slow_ptr->next;
            if (fast_ptr == nullptr || fast_ptr->next == nullptr || fast_ptr->next->next == nullptr) {
                return slow_ptr;
            }
            fast_ptr = fast_ptr->next->next;
        }
    }
};