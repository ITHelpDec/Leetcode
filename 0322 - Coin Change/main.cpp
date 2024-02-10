// dynamic programming solution using a base array
// O(nlogn) time due to sort, O(m) space because we created another array to store progress
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp(++amount, INT_MAX);
        dp[0] = 0;

        std::sort(coins.begin(), coins.end());

        for (int i = 0; i != amount; ++i) {
            for (const int coin : coins) {
                if (i - coin < 0) { break; }
                if (dp[i - coin] != INT_MAX) {
                    dp[i] = std::min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        return dp[--amount] == INT_MAX ? -1 : dp[amount];
    }
};
