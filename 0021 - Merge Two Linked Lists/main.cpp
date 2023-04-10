class Recursive_Solution {
public:
    ListNode* mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (!list1) { return list2; }
        if (!list2) { return list1; }
        
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

class Iterative_Solution {
public:
    ListNode* mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (!list1 || !list2) { return !list1 ? list2 : list1; }
        
        ListNode dummy(INT_MIN), *tail = &dummy;
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            } tail = tail->next;
        }
        
        tail->next = list1 ? list1 : list2;
        
        return dummy.next;
    }
};
