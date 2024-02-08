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

// Not sure how I would classify this solution - linear(?), given that we're iterating through hte bits?
class Solution2 {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while (n != 0) {
            count += n & 1;
            n >>= 1;
        }

        return count;
    }
};

// we can also take advantage of member functions from std::bitset<>
class Solution3 {
public:
    int hammingWeight(uint32_t n) {
        return std::bitset<32>(n).count();
    }
};

class Solution4 {
public:
    int hammingWeight(uint32_t n) {
        return std::popcount(n);
    }
};
