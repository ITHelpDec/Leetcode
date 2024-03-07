// O(n * m) solution
// keep a track of the borders - right, bottom, left, top
// for as long as the border don't cross, process...l2r, t2b, r2l, b2t, closing the outer edges as we go along
// pay particular attention to the top border and left border, with additional if statements

class Solution {
public:
    std::vector<int> spiralOrder(const std::vector<std::vector<int>> &matrix) {
        int rb = matrix[0].size() - 1;
        int bb = matrix.size() - 1;
        int lb = 0;
        int tb = 0;

        std::vector<int> answer;

        while (lb <= rb && tb <= bb) {
            for (int i = lb; i <= rb; ++i) { answer.emplace_back(matrix[tb][i]); }
            ++tb;

            for (int i = tb; i <= bb; ++i) { answer.emplace_back(matrix[i][rb]); }
            --rb;

            if (tb <= bb) {
                for (int i = rb; i >= lb; --i) { answer.emplace_back(matrix[bb][i]); }
                --bb;
            }
            
            if (lb <= rb) {
                for (int i = bb; i >= tb; --i) { answer.emplace_back(matrix[i][lb]); }
                ++lb;
            }
        }

        return answer;
    }
};
