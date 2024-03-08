// O(n^2) solution, although there is a linear solution (Manacher's algorithm)
// https://en.wikipedia.org/wiki/Longest_palindromic_substring#Manacher's_algorithm
// traverse through the string and use a private helper function to expand out centrally for odd and even substrings
// store and return the largest substring found

class Solution {
public:
    std::string longestPalindrome(const std::string &s) {
        for (int i = 0; i != s.size(); ++i) {
            expand(s, i, i);
            expand(s, i, i + 1);
        }

        return answer_;
    }
private:
    std::string answer_;

    void expand(const std::string &s, int l, int r) {
        while (~l && r != s.size()) {
            if (s[l] != s[r]) { break; }
            
            --l;
            ++r;

            if (answer_.size() < r - l) { answer_ = s.substr(l + 1, r - l - 1); }
        }
    }
};
