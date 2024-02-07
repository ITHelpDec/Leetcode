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
