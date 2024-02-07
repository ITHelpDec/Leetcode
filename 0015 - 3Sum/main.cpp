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

// better time complexity
// O(nlog(n)) due to sort, then two pointer approach to narrow in on suitable matches
class Solution2 {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        std::vector<std::vector<int>> result;
        if (nums.empty()) { return result; }

        std::sort(nums.begin(), nums.end());

        std::size_t n = nums.size();
        for (int i = 0; i != n; ++i) {
            int low  = i + 1;
            int high = n - 1;

            while (low < high) {
                if (nums[i] + nums[low] + nums[high] < 0) {
                    ++low;
                } else if (nums[i] + nums[low] + nums[high] > 0) {
                    --high;
                } else {
                    result.push_back({ nums[i], nums[low], nums[high] });

                    int temp_index1 = low;
                    int temp_index2 = high;

                    while (low < high && nums[low]  == nums[temp_index1]) { ++low;  }
                    while (low < high && nums[high] == nums[temp_index2]) { --high; }
                }
            }

            while (i + 1 < n && nums[i] == nums[i + 1]) { ++i; }
        }

        return result;
    }
};
