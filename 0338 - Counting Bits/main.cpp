// O(n) solution - potentially more efficient to reserve memory in advance before adding elements
class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> result;
        // result.reserve(n + 1);

        for (int i = 0; i != n + 1; ++i) {
            result.push_back(std::bitset<32>(i).count());
        }

        return result;
    }
};

// it's also possible to use a similar hamming weight solution with bitwise operations
class Solution2 {
public:
    vector<int> countBits(int n) {
        std::vector<int> result(n + 1, 0); 

        // can start at 1 because first element will always be 0
        for (int i = 1; i != n + 1; ++i) {
            result[i] = result[i >> 1] + (i & 1); 
        }
        
        return result;
    }
};
