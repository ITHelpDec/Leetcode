// two pass O(n) solution
// go through the list to get an idea of how many nodes there are
// if count is the same as n, return the next node
// otherwise, go thrugh the list again and remove the "count - n"th node by skipping it

struct ListNode {
    int val_;
    ListNode *next_;
    ListNode()                      : val_(0), next_(nullptr) { }
    ListNode(int x)                 : val_(x), next_(nullptr) { }
    ListNode(int x, ListNode *next) : val_(x), next_(next)    { }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;

        ListNode *curr = head;

        while (curr) {
            curr = curr->next_;
            ++count;
        }

        if (count == n) { return head->next_; }

        curr = head;

        for (int i = 1; i != count - n; ++i) { curr = curr->next_; }
        curr->next_ = curr->next_->next_;

        return head;
    }
};
