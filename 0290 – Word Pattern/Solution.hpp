#ifndef Solution_hpp
#define Solution_hpp

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

// one-pass solution
class Solution {
public:
    bool wordPattern(const std::string &pattern, const std::string &s) {
        int i = 0;
        int n = int(pattern.size());
        
        std::string word;
        std::istringstream iss(s);
        std::unordered_map<std::string, char> unique_pairs;
        
        for (/*...*/; iss >> word; ++i) {
            if (i == n) { return false; }
            
            if (unique_pairs.count(word)) {
                if (unique_pairs[word] != pattern[i]) { return false; }
            } else {
                for (const auto &[matched_word, matched_pattern] : unique_pairs)
                    if (matched_pattern == pattern[i]) { return false; }
                unique_pairs[word] = pattern[i];
            }
        }
        
        return i == n;
    }
};

#endif /* Solution_hpp */
