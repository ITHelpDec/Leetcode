// O(n) solution
// go through every letter in the column string

class Solution {
public:
    int titleToNumber(const std::string &columnTitle) {
        int answer = 0;

        for (char c : columnTitle) {
            answer = answer * 26 + (c - 'A' + 1);
        }

        return answer;
    }
};
