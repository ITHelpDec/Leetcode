
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// bit of a keeky example
// space complexity is probably a little unnecessary
class Solution1 {
public:
    bool isPalindrome(ListNode *head) {
        while (head) {
            data.push_back(head->val);
            head = head->next;
        }

        std::vector<int> rev_data(data.rbegin(), data.rend());

        return data == rev_data;
    }
private:
    std::vector<int> data;
};

// a lengthier workaround:
// // better on space complexity, ...
// // ...but maybe less intuitive than a simple "return l2r == r2l" (still linear)
//
// 1) find the middle; reverse from there until the end
// 2) compare values from head -> middle and end -> middle
// 3) traverse the two lists in parallel:
// //  => exit early if a pair of node values don't match
// //  => return true otherwise
//
// ideally, i'd re-write each block into its own member function to express the intent more clearly
class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;

        // slow to middle, fast to end
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev;
        ListNode *temp;

        // reverse from middle to end
        prev = slow;
        slow = slow->next;
        prev->next = nullptr;

        while (slow) {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        // reset nodes:
        // fast: head -> middle
        // slow: end -> middle
        fast = head;
        slow = prev;

        // compare, early traverse
        while (slow) {
            if (fast->val != slow->val) {
                return false;
            } else {
                fast = fast->next;
                slow = slow->next;
            }
        }

        return true;
    }
};
