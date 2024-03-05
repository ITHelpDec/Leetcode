// O(n) solution, taking advantage of std::stack
// std::stack will reverse the order of the nodes
// we only need to go as far as halfway through the list (count -= 2), setting the top of our stack to curr->next each time
// until we reach halfway, we set "curr" to "next" - otherwise, our final pointer is nullptr

struct ListNode {
    int val_;
    ListNode *next_;
    ListNode()                      : val_(0), next_(nullptr) { }
    ListNode(int x)                 : val_(x), next_(nullptr) { }
    ListNode(int x, ListNode *next) : val_(x), next_(next)    { }
};

class Solution {
public:
    void reorderList(ListNode* head) {
       std::stack<ListNode*> nstk;

       ListNode *curr = head;

       while (curr) {
           nstk.push(curr);
           curr = curr->next;
       } curr = head;

       int count = nstk.size();

       while (count >= 0) {
           ListNode *next   = curr->next;
           nstk.top()->next = curr->next;
           curr->next = nstk.top();
           nstk.pop();

           count -= 2;

           if (count < 0) {
               curr->next = nullptr;
           } else {
               curr = next;
           }
       }       
    }
};
