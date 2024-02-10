// dynamic programming solution using a base array
// O(nlogn) time due to sort, O(m) space because we created another array to store progress
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp(++amount, INT_MAX);
        dp[0] = 0;

        std::sort(coins.begin(), coins.end());

        for (int i = 1; i != amount; ++i) {
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

// slightly cleaner solution, inverting the loops and opting for std::size_t in place of int
// doesn't appear to work with std::numeric_limits<std::size_t>::max() in place of INT_MAX, though...
class Solution2 {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<std::size_t> dp(amount + 1, INT_MAX); 
        dp[0] = 0;

        std::sort(coins.begin(), coins.end()); 
        
        for (const std::size_t coin : coins) {
            for (std::size_t i = coin; i <= amount; ++i){
                dp[i] = std::min(dp[i], 1 + dp[i - coin]);
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
