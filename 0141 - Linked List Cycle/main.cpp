// O(n) solution
// think of "tortoise and the hare"
// we have a "fast" node that jumps two steps, and we have a slow node that jumps one
// if the fast node catches up with the slow node, we have a cycle

struct ListNode {
    int val_;
    ListNode *next_;
    ListNode(int x) : val_(x), next_(nullptr) { }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next_) {
            fast = fast->next_->next_;
            slow = slow->next_;

            if (slow == fast) { return true; }
        }

        return false;
    }
};
