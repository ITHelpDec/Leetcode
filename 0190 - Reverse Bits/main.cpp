// brute force solution - "curtain" solution
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        auto bs = std::bitset<32>(n);
    
        int left  = 0;
        int right = 31;

        while (left < right) {
            int temp    = bs[left];
            bs[left++]  = bs[right];
            bs[right--] = temp;
        }
        
        return bs.to_ulong();
    }
};

// wild divide and conquer solution (pain to write out)
// premise is shift left half to other side, then vice versa versa - keep dividing until we up with alternating bits
class Solution2 {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n & 0b11111111111111110000000000000000) >> 16 | (n & 0b00000000000000001111111111111111) << 16;
        n = (n & 0b11111111000000001111111100000000) >>  8 | (n & 0b00000000111111110000000011111111) <<  8;
        n = (n & 0b11110000111100001111000011110000) >>  4 | (n & 0b00001111000011110000111100001111) <<  4;
        n = (n & 0b11001100110011001100110011001100) >>  2 | (n & 0b00110011001100110011001100110011) <<  2;
        n = (n & 0b10101010101010101010101010101010) >>  1 | (n & 0b01010101010101010101010101010101) <<  1;
        return n;
    }
};

// soltuion provided by standfor page
// http://graphics.stanford.edu/~seander/bithacks.html#BitReverseTable
class Solution3 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t r = n;
        int      s = sizeof(n) * CHAR_BIT - 1;

        for (n >>= 1; n; n >>= 1) {   
            r <<= 1;
            r |= n & 1;
            --s;
        }
        
        r <<= s;

        return r;
    }
};
