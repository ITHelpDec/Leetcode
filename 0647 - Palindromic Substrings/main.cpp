// O(n^2) solution, similar to Largest Palindromic Substring
// traverse through each character of the string and check for odd and even palindromes
// as long as the left and right characters either side of the axis are the same, increment the coutner and keep expanding out

class Solution {
public:
    int countSubstrings(const std::string &s) {
        int count = 0;

        for (int i = 0; i != s.size(); ++i) {
            check(s, i, i,     count);
            check(s, i, i + 1, count);
        }

        return count;
    }
private:
    void check(const std::string &s, int l, int r, int &count) {
        while (~l && r != s.size() && s[l] == s[r]) {
            ++count;
            --l;
            ++r;
        }
    }
};
