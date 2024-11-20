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
    void reverseList(ListNode* beforeHead, ListNode* head, ListNode* tail, ListNode* afterTail) {
        ListNode* prevHead = afterTail;
        while (head != afterTail) {
            ListNode* tmp = head->next;
            head->next = prevHead;
            prevHead = head;
            head = tmp;
        }
        if (beforeHead) {
            beforeHead->next = tail;
        }
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* savedHead = head;
        ListNode* beforeFirst = nullptr, *afterLast = nullptr;
        ListNode* first = nullptr, *last = nullptr;
        for (int i = 1; head != nullptr; head = head->next, ++i) {
            if (i == left - 1) {
                beforeFirst = head;
            } else if (i == left) {
                first = head;
            } else if (i == right + 1) {
                afterLast = head;
            } else if (i == right) {
                last = head;
            }
        }
        if (left == right) {
            last = first;
        }
        reverseList(beforeFirst, first, last, afterLast);
        return beforeFirst ? savedHead : last;
    }
};