// Non-recursice
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

// Recursive ver1
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k < 2) return head;
        ListNode *p = head;
        for(int i = 0; i < k; ++i) {
            if(p) p = p->next;
            else return head;
        }
        ListNode *pre = NULL, *curr = head, *next = NULL;
        for(int i = k; i > 0; --i) { // while(curr != p)
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        head->next = reverseKGroup(p, k);
        return pre;
    }
};

// Recursive ver2
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k < 2) return head;
        ListNode *p = head;
        for(int i = 0; i < k; ++i) {
            if(p) p = p->next;
            else return head;
        }
        ListNode *pre = NULL, *curr = head, *next = NULL;
        while(curr != p) {
            next = curr->next;
            if(pre) curr->next = pre;
            else curr->next = reverseKGroup(p, k);
            pre = curr;
            curr = next;
        }
        return pre;
    }
};