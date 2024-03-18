// BFS solution
// treat the solution like a bfs, using a queue:
// -> for as long as there are nodes to process, assign a working node, perform the algorithm work then add the next nodes to the queue
// using a temporary "next" node, start at the root node, and do two things
// 1) set the curr node' next to the temporary next
// 2) set the temporary next to our current node
// we will approach this in a right-to-left manner (inverted `for` loop)

struct Node;

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) { return nullptr; }

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node *next = nullptr;

            for (int i = q.size(); i; --i) {
                Node *curr = q.front();
                q.pop();

                curr->next = next;
                next = curr;

                if (curr->right) {
                    q.push(curr->right);
                    q.push(curr->left);
                }
            }
        }

        return root;
    }
};

/*
// Definition for a Node.
struct Node {
    int val;
    
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) { }

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) { }
    
    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) { }
};
*/
