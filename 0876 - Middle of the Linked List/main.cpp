// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// successful attempt
class Solution1 {
public:
    ListNode* middleNode(ListNode *head) {
        straggler_ = head;

        while (head) {
            head = head->next;
            ++counter_;

            if (counter_ % 2 == 0) { straggler_ = straggler_->next; }
        }

        return straggler_;
    }
private:
    int counter_ = 0;
    ListNode *straggler_;
};

// better attempt without the need for a counter
// similar to cyclical "slow & fast" challenge

class Solution2 {
public:
    ListNode* middleNode(ListNode *head) {
        ListNode *gonzalez = head;

        while (gonzalez && gonzalez->next) {
            gonzalez = gonzalez->next->next;
            head = head->next;
        }

        return head;
    }
};
