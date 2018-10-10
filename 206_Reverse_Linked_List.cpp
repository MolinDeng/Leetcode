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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL, *next = NULL;
        if(!head) return head;
        while(head->next) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        head->next = pre;
        return head;
    }
};