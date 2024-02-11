// O(n * m) solution
// set up zero'd dp array
// nested for loop from index 1
// if previous characters are the same, increment current dp entry - otherwise, set to max of back an 'i' or back a 'j'
// return last dp entry
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] =  (text1[i - 1] == text2[j - 1])
                                ? dp[i - 1][j - 1] + 1
                                : std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }
};
