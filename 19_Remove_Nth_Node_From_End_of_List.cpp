/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Two pass
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        ListNode* p = head; int size = 0;
        while(p) {
            size++;
            p = p->next;
        }
        if(size == n) return head->next;
        p = head;
        for(int i = 0; i < size - n - 1; ++i) 
            p = p->next;
        p->next = p->next->next;
        return head;
    }
};

// Two pass
class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int size = 0;
        ListNode* p = head;
        while(p) {
            size++;
            p = p->next;
        }
        size -= n;
        p = dummy;
        while(size--) 
            p = p->next;
        p->next = p->next->next;
        return dummy->next;
    }
};

// One pass
class Solution3 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        ListNode* dummy = new ListNode(0);
        dummy.next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        for(int i = 0; i <= n; ++i) 
            first = first->next;
        while(first) {
            second = second->next;
            first = first->next;
        }
        second->next = second->next->next;
        return dummy->next;
    }
};