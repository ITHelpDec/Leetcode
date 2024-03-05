// tricky min-heap question requiring a tail and a dummy node (dummy will always point to the original start positino)
// we add ours lists to the queue / min-heap
//
// set the top of the queue to tail->next_
// move tail along one, ...
// ...and if tali->next_ is valid add it to the queue
//
// once we've processed everything in the queue, return dummy.next

struct ListNode {
    int val_;
    ListNode* next_;

    ListNode()                      : val_(0), next_(nullptr) { }
    ListNode(int x)                 : val_(x), next_(nullptr) { }
    ListNode(int x, ListNode *next) : val_(x), next_(next)    { }
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*> &lists) {
        ListNode dummy;
        ListNode *tail = &dummy;

        auto cmp = [] (ListNode *lhs, ListNode *rhs) { return lhs->val_ > rhs->val_; };
        
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> q;

        for (auto list : lists) {
            if (list) { q.push(list); }
        }

        while (!q.empty()) {
            tail->next_ = q.top();
            q.pop();

            tail = tail->next_;

            if (tail->next_) { q.push(tail->next_); }
        }

        return dummy.next;
    }
};
