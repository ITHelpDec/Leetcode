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
