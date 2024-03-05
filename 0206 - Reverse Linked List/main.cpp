// O(n) solution
// keep a temp copy of the next_ Node as you go through each node
// think of the following in a loop for as long as our head Node is valid
// next => head->next_ => prev => head => next
// i.e. "the previous node is the next node"

struct ListNode {
    int val_;
    ListNode *next_;

    ListNode()                      : val_(0), next_(nullptr) { }
    ListNode(int x)                 : val_(x), next_(nullptr) { }
    ListNode(int x, ListNode *next) : val_(x), next_(next)    { }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *next;

        while (head) {
            next = head->next_;
            head->next_ = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
};
