// brute force O(n^2) time, O(1) space
class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        int max_profit = 0;

        for (int i = 0; i != prices.size() - 1; ++i) {
            for (int j = i + 1; j != prices.size(); ++j) {
                max_profit = std::max(prices[j] - prices[i], max_profit);
            }
        }

        return max_profit;
    }
};

// O(n) solution, O(1) space
class Solution2 {
public:
    int maxProfit(std::vector<int> &prices) {
        for (auto sell : prices) {
            buy     = std::min(buy, sell);
            profit_ = std::max(profit_, sell - buy);
        }

        return profit_;
    }

private:
    int profit_ = 0;
    int buy = INT_MAX;
};
