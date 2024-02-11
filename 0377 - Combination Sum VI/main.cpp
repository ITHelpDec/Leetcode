// dp solution
// zero'd base array with 1 on front
// from 1 to no more than target, go through each number
// if our position is greater than or equal to the number, increase our dp element by the elment "num" places back
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        std::vector<uint32_t> dp(target + 1, 0);
        dp.front() = 1;

        for (int i = 1; i != target + 1; ++i) {
            for (const int num : nums) {
                if (i >= num) { dp[i] += dp[i - num]; }
            }
        }

        return static_cast<int>(dp[target]);
    }
};
