// As a medium, O(n) is very easy
class Solution {
public:
    int search(const std::vector<int> &nums, int target) {
        for (int i = 0; i != nums.size(); ++i)
            if (nums[i] == target) { return i; }
        return -1;
    }
};

// To achieve O(logn) time, we will want to employ a binary search technique
// Some adaptations are needed because the sorted array may have been rotated

class Solution2 {
public:
    int search(const std::vector<int> &nums, int target) {
        int left  = 0;
        int right = nums.size() - 1;
        
        int mid;

        while (left <= right) {
            mid = (left + right) / 2;

            if (nums[mid] == target) { return mid; }

            if (nums[mid] > nums.back()) {
                target > nums[mid] || target < nums.front() ? left  = mid + 1
                                                            : right = mid - 1;
            } else {
                target < nums[mid] || target > nums.back()  ? right = mid - 1
                                                            : left  = mid + 1;  
            }
        }

        return -1;
    }
};
