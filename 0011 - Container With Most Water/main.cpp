// O(n^2) solution
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.empty()) { return 0; }
        
        int result = 0;

        for (int i = 0; i != height.size() - 1; ++i) {
            for (int j = i + 1; j != height.size(); ++j) {
                int bucket = (j - i) * std::min(height[i], height[j]);
                // std::cout << i << ' ' << j << ": " << bucket << '\n';
                result = std::max(result, bucket);
            }
        }

        return result;
    }
};

// O(n) solution, using a "closing the curtains" two-pointer approach
class Solution2 {
public:
    int maxArea(vector<int>& height) {
        if (height.empty()) { return 0; }
        
        int left  = 0;
        int right = height.size() - 1;

        int result = 0;

        while (left < right) {
            // int bucket = (right - left) * std::minx(height[left], height[right]);
            // result = std::max(result, bucket);
            result = std::max(result, (right - left) * std::min(height[left], height[right]));

            if      (height[left] < height[right]) { ++left; }
            else if (height[left] > height[right]) { --right; }
            else {
                ++left;
                --right;
            }
        }

        return result;
    }
};
