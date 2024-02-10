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
        
        for (const std::size_t coin : coins) {
            for (std::size_t i = coin; i <= amount; ++i) {
                dp[i] = std::min(dp[i], 1 + dp[i - coin]);
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

// the premise is "which is smaller - the current cell, or the cell 'coin' times back?"
// e.g.
// { 1, 2, 5 }, 6
//
// coin: 1, i: 1, dp: 0, 1, M, M, M, M, M, 
// coin: 1, i: 2, dp: 0, 1, 2, M, M, M, M, 
// coin: 1, i: 3, dp: 0, 1, 2, 3, M, M, M, 
// coin: 1, i: 4, dp: 0, 1, 2, 3, 4, M, M, 
// coin: 1, i: 5, dp: 0, 1, 2, 3, 4, 5, M, 
// coin: 1, i: 6, dp: 0, 1, 2, 3, 4, 5, 6, 
// coin: 2, i: 2, dp: 0, 1, 1, 3, 4, 5, 6, 
// coin: 2, i: 3, dp: 0, 1, 1, 2, 4, 5, 6, 
// coin: 2, i: 4, dp: 0, 1, 1, 2, 2, 5, 6, 
// coin: 2, i: 5, dp: 0, 1, 1, 2, 2, 3, 6, 
// coin: 2, i: 6, dp: 0, 1, 1, 2, 2, 3, 3, 
// coin: 5, i: 5, dp: 0, 1, 1, 2, 2, 1, 3, 
// coin: 5, i: 6, dp: 0, 1, 1, 2, 2, 1, 2, 
    
