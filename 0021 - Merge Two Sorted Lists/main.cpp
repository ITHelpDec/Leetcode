// recursive O(n) solution
// if either of the lists are empty, no need to merge - return the non-empty list
// if the 1st list value is greater than hte 2nd, we swap them about and begin calling list1->next recursively
//
// think "list1->next" as the crux of this solution

class Solution {
public:
    ListNode* mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (!list1 || !list2) { return list1 ? list1 : list2; }

        if (list1->val > list2->val) { std::swap(list1, list2); }

        list1->next = mergeTwoLists(list1->next, list2);

        return list1;
    }
};
