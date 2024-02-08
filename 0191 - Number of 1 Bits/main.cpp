// O(n) solution, albeit two passes - better to look at a bitwise solution
class Solution {
public:
    int hammingWeight(uint32_t n) {
        std::string s = std::bitset<32>(n).to_string();

        int count = 0;

        for (const char c : s) {
            if (c == '1') { ++count; }
        }

        return count;
    }
};
