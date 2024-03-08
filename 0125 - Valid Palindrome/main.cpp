// single-pass, O(n), two-pointer approach
// keep shifting our left and right pointers centrally until we have an alphanumeric character for each
// if the lowercase version of each pointer are not the same, then return false - otherwise, keep going

class Solution {
public:
    bool isPalindrome(const std::string &s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (!std::isalnum(s[l])) {
                ++l;
                continue;
            }

            if (!std::isalnum(s[r])) {
                --r;
                continue;
            }

            if (std::tolower(s[l]) != std::tolower(s[r])) {
                return false;
            } else {
                ++l;
                --r;
            }
        }

        return true;
    }
};
