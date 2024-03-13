// a nice implementation
// we have two member variables - one to keep track of next letters, and one to confirm whether we have landed on a complete word
// similar patterns are repeated throughout - we create a pointer from `this`, and iterate through each letter of the word
//
// for insert, if we can't find the letter, we create it with a new node, and once we reach the end we change our `is_word_` flag to `true`
//
// for search and startsWith, we return false if the character isn't found
// once we get to the end, search will return whether or not we have landed on a word, whereas starts with will always return true
//
// we opt for a std::array because we already know the number of letters involved (all lowercase), ...
// ... and we default construct to allow for rule of five
//
// all functions are O(n)

class Trie {
public:
    Trie() = default;
    
    void insert(const std::string &word) {
        Trie *letter = this;

        for (char c : word) {
            if (!letter->next_[c - 'a']) { letter->next_[c - 'a'] = new Trie(); }
            letter = letter->next_[c - 'a'];
        }

        letter->is_word_ = true;
    }
    
    bool search(const std::string &word) {
        Trie *letter = this;

        for (char c : word) {
            if (!letter->next_[c - 'a']) { return false; }
            letter = letter->next_[c - 'a'];
        }

        return letter->is_word_;
    }
    
    bool startsWith(const std::string &prefix) {
        Trie *letter = this;

        for (char c : prefix) {
            if (!letter->next_[c - 'a']) { return false; }
            letter = letter->next_[c - 'a'];
        }

        return true;
    }
private:
    std::array<Trie*, 26> next_;

    bool is_word_ = false;
};
