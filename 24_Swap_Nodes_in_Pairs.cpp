/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *curr, *nxt;
        while(pre->next && pre->next->next) {
            curr = pre->next;
            nxt = curr->next;
            curr->next = nxt->next;
            nxt->next = curr;
            pre->next = nxt;
            pre = curr;
        }
        return dummy->next;
    }
};