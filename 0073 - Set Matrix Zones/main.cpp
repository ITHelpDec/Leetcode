// O(n * m) solution, O(n + m) space
// two passes
// (1) keep a tally of the rows and columns that have a '0' element
// (2) traverse the matrix again, and use the info we collected in step (1) to set the appropriate elements to '0'

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        std::vector<bool> row(n, false);
        std::vector<bool> col(m, false);

        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != m; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != m; ++j) {
                if (row[i] || col[j]) { matrix[i][j] = 0; }
            }
        }

    }
};
