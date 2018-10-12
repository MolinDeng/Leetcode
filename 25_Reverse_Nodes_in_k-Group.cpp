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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        ListNode *dummy = new ListNode(0);
        ListNode *pre = NULL, *nxt = NULL, *p = head, *end = dummy;
        while(head) {
            int cnt = 0;
            while(p && cnt < k) {
                p = p->next;
                cnt++;
            }
            if(cnt < k) {
                end->next = head;
                break;
            }
            else {
                p = head;
                pre = NULL;
                while(cnt--) {
                    nxt = p->next;
                    p->next = pre;
                    pre = p;
                    p = nxt;
                }
                end->next = pre;
                end = head;
            }
            head = p;
        }
        return dummy->next;
    }
};