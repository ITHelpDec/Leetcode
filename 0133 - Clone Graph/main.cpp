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
