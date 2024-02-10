// O(n^2) back-tracking solution,
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> dp(nums.size() + 1, 1);

        for (int i = 0; i != nums.size(); ++i) {
            for (int j = 0; j != i; ++j) {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};

// e.g.
// i: 1	j: 0	dp: 1 1 1 1 1 1 1 1 1 
// i: 2	j: 0	dp: 1 1 1 1 1 1 1 1 1 
// i: 2	j: 1	dp: 1 1 1 1 1 1 1 1 1 
// i: 3	j: 0	dp: 1 1 1 1 1 1 1 1 1 
// i: 3	j: 1	dp: 1 1 1 1 1 1 1 1 1 
// i: 3	j: 2	dp: 1 1 1 2 1 1 1 1 1 
// i: 4	j: 0	dp: 1 1 1 2 1 1 1 1 1 
// i: 4	j: 1	dp: 1 1 1 2 1 1 1 1 1 
// i: 4	j: 2	dp: 1 1 1 2 2 1 1 1 1 
// i: 4	j: 3	dp: 1 1 1 2 2 1 1 1 1 
// i: 5	j: 0	dp: 1 1 1 2 2 1 1 1 1 
// i: 5	j: 1	dp: 1 1 1 2 2 1 1 1 1 
// i: 5	j: 2	dp: 1 1 1 2 2 2 1 1 1 
// i: 5	j: 3	dp: 1 1 1 2 2 3 1 1 1 
// i: 5	j: 4	dp: 1 1 1 2 2 3 1 1 1 
// i: 6	j: 0	dp: 1 1 1 2 2 3 2 1 1 
// i: 6	j: 1	dp: 1 1 1 2 2 3 2 1 1 
// i: 6	j: 2	dp: 1 1 1 2 2 3 2 1 1 
// i: 6	j: 3	dp: 1 1 1 2 2 3 3 1 1 
// i: 6	j: 4	dp: 1 1 1 2 2 3 3 1 1 
// i: 6	j: 5	dp: 1 1 1 2 2 3 4 1 1 
// i: 7	j: 0	dp: 1 1 1 2 2 3 4 2 1 
// i: 7	j: 1	dp: 1 1 1 2 2 3 4 2 1 
// i: 7	j: 2	dp: 1 1 1 2 2 3 4 2 1 
// i: 7	j: 3	dp: 1 1 1 2 2 3 4 3 1 
// i: 7	j: 4	dp: 1 1 1 2 2 3 4 3 1 
// i: 7	j: 5	dp: 1 1 1 2 2 3 4 4 1 
// i: 7	j: 6	dp: 1 1 1 2 2 3 4 4 1 
//
// max = 4
