// one solution, but quite a strange set up (cleaner solution below this)
class Solution {
public:
    int uniqueLetterString(std::string s) {
        std::vector<std::vector<int>> index(26, std::vector<int>(2, -1));
        int sz = s.size();
        int result = 0;

        int mod = std::pow(10, 9) + 7;
        for (int i = 0; i != sz; ++i) {
            int c = s[i] - 'A';
            
            result = (result + (i - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
            
            index[c][0] = index[c][1];
            index[c][1] = i;
        }

        for (int c = 0; c != 26; ++c) {
            result = (result + (sz - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
        }

        return result;
    }
};

// better solution starts here (dynamic)
// we keep a track of the previous combination count and previous positions
// traverse the string and get the mapping of the character we're on e.g. 'A' = 0
// keep a track of the characters, the posible combinations and their sums using dynamic programming

class Solution {
public:
    int uniqueLetterString(const std::string &s) {
        std::vector<int> prev_cnt(26,  0);
        std::vector<int> prev_pos(26, -1);

        int result = 0;

        for (int i = 0, current, count = 0, n = s.size(); i != n; ++i) {
            int c   = s[i] - 'A';
            current = i - std::exchange(prev_pos[c], i);
            count  += current - std::exchange(prev_cnt[c], current);
            result += count;
        }

        return result;
    }
};
