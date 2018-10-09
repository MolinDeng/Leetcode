// merge one by one recursive
class Solution1 {
public:
    ListNode* merge2Lists(ListNode * l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        return dummy->next;
    }
    // recursive
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        if(lists.size() == 1) return lists[0];
        ListNode *l1 = lists.back();
        lists.pop_back();
        ListNode *l2 = lists.back();
        lists.pop_back();
        lists.push_back(merge2Lists(l1, l2));
        return mergeKLists(lists);
    }
    // also OK
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     if(lists.empty()) return NULL;
    //     if(lists.size() == 1) return lists[0];
    //     int n = lists.size();
    //     lists[n-2] = merge2Lists(lists[n-1], lists[n-2]);
    //     lists.pop_back();
    //     return mergeKLists(lists);
    // }

    // Non-recursive
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int n = lists.size();
        int i = n - 2, j = n -1;
        while(j != 0) {
            lists[i] = merge2Lists(lists[i], lists[j]);
            --i; --j;
        }
        return lists[0];
    } 
};

// compare one by one using priority_queue
class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        ListNode *dummy = new ListNode(0), *p = dummy;
        auto cmp = [](const ListNode *a, const ListNode *b){ return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> node_queue(cmp);
        for(auto p : lists) 
            if(p) node_queue.push(p);
        while(!node_queue.empty()) {
            p->next = node_queue.top();
            node_queue.pop();
            p = p->next;
            if(p->next != NULL) 
                node_queue.push(p->next);
        }
        return dummy->next;
    }
};

// merge by divide & conquer
class Solution3 {
public:
    ListNode* merge2Lists(ListNode * l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        return dummy->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        for(int gap = 1; gap < lists.size(); gap *= 2) 
            for(int i = 0; i + gap< lists.size(); i += 2*gap) 
                lists[i] = merge2Lists(lists[i], lists[i+gap]);
        return lists[0];
    }
};