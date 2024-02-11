// (O(n * m) DFS solution
// start a hash map
// if the node doesn't exist, create it, then populate it's neighbours recursively
// return the node copy from the map
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) { return node; }

        if (clone_.find(node) == clone_.end()) {
            clone_[node] = new Node(node->val, {});

            for (const auto &neighbor: node->neighbors) {
                clone_[node]->neighbors.emplace_back(cloneGraph(neighbor));
            }
        }

        return clone_[node];
    }
private:
    std::unordered_map<Node*, Node*> clone_;
};

// BFS solution
// create initial empty clone node and add it to a queue
// for as long as there are elements in the queue:
// // create a working node from the front of the queue
// // // add each neighbour to the queue for processing later
// // // assign the neighbour to our current node by adding it to our clone map 
class Solution2 {
public:
    Node* cloneGraph(Node* node) {
        if (!node) { return node; }

        Node *first = new Node(node->val, {});
        clone_[node] = first;

        std::queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node *current = q.front();
            q.pop();

            for (const auto &neighbor : current->neighbors) {
                if (clone_.find(neighbor) == clone_.end()) {
                    clone_[neighbor] = new Node(neighbor->val, {});
                    q.push(neighbor);
                }

                clone_[current]->neighbors.emplace_back(clone_[neighbor]);
            }
        }

        return clone_[node];
    }
private:
    std::unordered_map<Node*, Node*> clone_;
};
