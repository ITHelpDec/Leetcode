// brute force solution, O(n^3) - not ideal
class Solution {
public:
    std::vector<std::vector<int>> threeSum(const std::vector<int> &nums) {
        std::set<std::vector<int>> result;

        for (int i = 0; i != nums.size() - 2; ++i) {
            for (int j = i + 1; j != nums.size() - 1; ++j) {
                for (int k = j + 1; k != nums.size(); ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) { 
                        std::vector<int> temp = { nums[i], nums[j], nums[k] };
                        std::sort(temp.begin(), temp.end());
                        result.insert(temp); }
                }
            }
        }

        return std::vector(result.begin(), result.end());
    }
};
