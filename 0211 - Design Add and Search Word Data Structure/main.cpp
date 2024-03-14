// similar solution to creating a prefix tree (trie), with the added complexity of globbing ('.')
//
// we implement a similar add / insert solution using a TrieNode struct that contains all lowercase letters and a sentinel
//
// for searching we can create an overload that passes the word as well as our current index and the letter we're on
/// if the letter is null then we return false because we know it does't exist
/// if we reach our required word size, we check for the sentinel being true (.is_word_)
/// as long as the letter isn't a '.', we start a search for the next letter
/// otherwise, we go through all of the next potential lowercase letters to see if they exist
//
// i'd like to look into implementing this without operator new at some point

class WordDictionary {
public:
    WordDictionary() : root_(new TrieNode()) { }
    
    void addWord(const std::string &word) {
        TrieNode *letter = root_;
        for (char c : word) {
            if (!letter->next_[c - 'a']) { letter->next_[c - 'a'] = new TrieNode(); }
            letter = letter->next_[c- 'a'];
        }
        letter->is_word_ = true;
    }
    
    bool search(const std::string &word) {
        TrieNode *letter = root_;
        return search(word, 0, letter);
    }
private:
    struct TrieNode {
        std::array<TrieNode*, 26> next_;
        bool is_word_;
    };

    TrieNode *root_;
    
    bool search(const std::string &word, int i, TrieNode *letter) {
        if (!letter)          { return false; }
        if (i == word.size()) { return letter->is_word_; }
        
        if (word[i] != '.') {
            return search(word, i + 1, letter->next_[word[i] - 'a']);
        } else {
            for (int j = 0; j != 26; ++j) {
                if (search(word, i + 1, letter->next_[j])) { return true; }
            }
        }
        
        return false;
    }
};
