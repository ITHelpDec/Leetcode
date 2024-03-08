// another tricky solution, similar to Longest Repeating Character Replacement
// populate a character frequency map with our desired string
// must be a better way to solve / write this algorithm

class Solution {
public:
    std::string minWindow(const std::string &s, const string &t) {
        std::vector<int> fmap(128, 0);

        for (const char c : t) { ++fmap[c]; }

        int count = t.size();
        int begin = 0;
        int end = 0;
        int sc = INT_MAX;
        int head = 0;

        while (end < s.size()) {
            if (fmap[s[end++]]-- > 0) { --count; }

            while (count == 0) {
                if (end - begin < sc) { sc = end - (head = begin); }
                
                if (fmap[s[begin++]]++ == 0) { ++count; }
            }
        }

        return sc == INT_MAX ? "" : s.substr(head, sc);
    }
};
