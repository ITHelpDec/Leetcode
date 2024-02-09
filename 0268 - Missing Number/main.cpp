// O(nlogn) brute-force solution due to sort
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i != nums.size(); ++i) {
            if (nums[i] != i) { return i; }
        }
        return nums.size();
    }
};

// O(n) solution, O(1) space
class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int n     = nums.size();
        int range = n * (n + 1) / 2;
        
        int sum = 0;
        for (const int num : nums) { sum += num; }

        return range - sum;
    }
};
