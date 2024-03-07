// two-step approach
// reverse the order of the rows, then swap alternating cells i.e. "ij" vs "ji"
// 1 2 3     7 8 9     7 4 1
// 4 5 6  => 4 5 6  => 8 5 2
// 7 8 9     1 2 3     9 6 3

class Solution {
public:
    void rotate(std::vector<std::vector<int>> &matrix) {
        std::reverse(matrix.begin(), matrix.end());
        
        for (int i = 0; i != matrix.size(); ++i) {
            for (int j = i + 1; j != matrix[i].size(); ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
