// dp solution
// 0'd base array, set back to 1
// reverse traversal
// as long as we're in bounds and we find a word, set our current dp element to the element "word" size ahead
// once we find a word from the list, continue our traversal
// the front of our dp array will provide the answer
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::vector<int> dp(s.size() + 1, 0);
        dp.back() = 1;

        for (int i = s.size() - 1; ~i; --i) {
            for (const auto &word : wordDict) {
                if (i + word.size() <= s.size() && s.substr(i, word.size()) == word) {
                    dp[i] = dp[i + word.size()];
                    if (dp[i]) { break; }
                }
            }
        }

        return dp.front();
    }
};
