// multi-pass O(n) solution
// early exit by making sure the strings are of the same length
// create a frequency map of all the potential characters, and add the characters seen from s, but remove the characters seen from t
// we should be left with all '0's in our frequency map (compare it to an empty array of similar dimensions)

class Solution {
public:
    bool isAnagram(const std::string &s, const std::string &t) {
        if (s.size() != t.size()) { return false; }

        std::array<int, 26> fmap;

        for (const char c : s) { ++fmap[c - 'a']; }
        for (const char c : t) { --fmap[c - 'a']; }

        return fmap == std::array<int, 26>();
    }
};
