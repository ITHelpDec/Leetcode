// recursive bitwise manipulation - XOR and AND
class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum((a ^ b), (a & b) << 1);
    }
};

// e.g.
// 1: 01
// 2: 10
// 1 ^ 2 = 3 (11)
// 1 & 2 = 0
// .:. result = 3
