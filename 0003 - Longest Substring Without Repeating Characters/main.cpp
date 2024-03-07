// O(n) solution
// create a frequency map of all possible characters
// keep a track of the max substring length without repeating characters (start to current positino)
// if we encounter a repeating character (line 15), change the start position and start again

class Solution {
public:
    int lengthOfLongestSubstring(const std::string &s) {
        std::vector<int> bucket(256, - 1);

        int max = 0;
        int start = -1;

        for (int i = 0; i != s.size(); ++i) {
            if (bucket[s[i]] > start) { start = bucket[s[i]]; }

            bucket[s[i]] = i;

            max = std::max(max, i - start);
        }

        return max;
    }
};
