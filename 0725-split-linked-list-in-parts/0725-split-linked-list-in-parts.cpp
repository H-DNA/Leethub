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
    int length(ListNode* head) {
        int cnt = 0;
        while (head != nullptr) {
            ++cnt;
            head = head->next;
        }
        return cnt;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k);
        const int list_len = length(head);
        const int short_cnt = list_len % k == 0 ? list_len % k : k - list_len % k;
        const int long_num = (list_len + (k - 1)) / k;
        for (int i = 0; i < k - short_cnt; ++i) {
            res[i] = head;
            for (int j = 0; j < long_num - 1; ++j) {
                head = head->next;
            }
            if (long_num > 0) {
                ListNode* prev = head;
                head = head->next;
                prev->next = nullptr;
            }
        }
        for (int i = 0; i < short_cnt; ++i) {
            res[k - short_cnt + i] = head;
            for (int j = 0; j < long_num - 2; ++j) {
                head = head->next;
            }
            if (long_num - 1 > 0) {
                ListNode* prev = head;
                head = head->next;
                prev->next = nullptr;
            }
        }

        return res;
    }
};