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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* nptr = head;
      ListNode* prevptr = nullptr;
      for (ListNode* ptr = head; ptr != nullptr; ptr=ptr->next) {
        --n;
        if (n < 0) {
          prevptr = nptr;
          nptr = nptr->next;
        }
      }
      if (!prevptr) head = head->next;
      else if (!nptr) prevptr = nullptr;
      else {
        prevptr->next = nptr->next;
      }
      return head;
    }
};