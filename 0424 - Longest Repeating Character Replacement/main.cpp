// O(n) solution
// tricky solution to explain
// set up a frequency map of the uppercase characters
// traverse through the string and see which is greater - our current max, or one count more than the current character
// will need to look for a more legible solution...

class Solution {
public:
    int characterReplacement(const string &s, int k) {
        int max = 0;
        int i = 0;
        int n = s.size();

        std::vector<int> count(26);

        for (int j = 0; j != n; ++j) {
            max = std::max(max, ++count[s[j] - 'A']);

            if (j - i + 1 > max + k) { --count[s[i++] - 'A']; }
        }

        return n - i;
    }
};
