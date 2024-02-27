// original solution using raw pointers (would be nice to introduce shared pointers)
// quite convoluted (easier solution below this)

struct Node {
    Node(int key, int val) : key_(key), val_(val), next_(nullptr), prev_(nullptr) { }

    int key_;
    int val_;

    Node *next_;
    Node *prev_;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_    = capacity;
        head_->next_ = tail_;
        tail_->prev_ = head_;
    }
    
    int get(int key) {
        if (map_.count(key)) {
            Node *result_node = map_[key];

            int result = result_node->val_;

            map_.erase(key);

            delete_node(result_node);
            add_node(result_node);

            map_[key] = head_->next_;

            return result;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (map_.count(key)) {
            Node *existing_node = map_[key];
            map_.erase(key);
            delete_node(existing_node);
        }

        if (map_.size() == capacity_) {
            map_.erase(tail_->prev_->key_);
            delete_node(tail_->prev_);
        }

        add_node(new Node(key, value));

        map_[key] = head_->next_;
    }

private:
    int capacity_;
    std::unordered_map<int, Node*> map_;

    Node *head_ = new Node(-1, -1);
    Node *tail_ = new Node(-1, -1);

    void add_node(Node *new_node) {
        Node *temp = head_->next_;

        new_node->next_ = temp;
        new_node->prev_ = head_;

        head_->next_ = new_node;
        temp->prev_  = new_node;
    }

    void delete_node(Node *del_node) {
        auto del_prev = del_node->prev_;
        auto del_next = del_node->next_;

        del_prev->next_ = del_next;
        del_next->prev_ = del_prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// better solution (in my mind), taking advantage of std::list and more declarative explanations
// approach to this solution is
// (1) set capacity through constructor and member variable
// (2) use std::list::splice to move our found Node to the end of the list (.end() represent our most-recently used Node, and vice versa)
// (3) if we're at capacity, remove the Node at the front of the list (our least recently used Node) and then add
//
// std::list::splice complexity is constant, and does not copy values like std::list::insert does
// std::unordered_map also allows us constant time insertion and retrieval

class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) { }
    
    int get(int key) {
        if (!cache_.count(key)) { return -1; }
        nodes_.splice(nodes_.end(), nodes_, cache_[key]);
        return cache_[key]->val_;
    }
    
    void put(int key, int value) {
        if (get(key) != -1) { return; }
        
        if (nodes_.size() == capacity_) {
            cache_.erase(nodes_.front().key_);
            nodes_.pop_front();
        }

        nodes_.emplace_back(key, value);
        cache_[key] = std::prev(nodes_.end());
    }

private:
    int capacity_;

    struct Node;

    std::unordered_map<int, std::list<Node>::const_iterator> cache_;
    std::list<Node> nodes_;

    struct Node {
        int key_;
        int val_;
    };
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
