// terrible runtime with the nested for loops
// traverse through each square in the grid, looking for squares with no stones
// recursively pull rocks into the empty square, and return the minimum amount of changes it takes to do the population

class Solution {
public:
    int minimumMoves(std::vector<std::vector<int>> &grid) {
        int answer = INT_MAX;

        for (int i = 0; i != 3; ++i) {
            for (int j = 0; j != 3; ++j) {

                if (grid[i][j]) { continue; }

                for (int a = 0; a != 3; ++a) {
                    for (int b = 0; b != 3; ++b) {
                        
                        if (grid[a][b] < 2) { continue; }

                        int result = std::abs(i - a) + std::abs(j - b);

                        --grid[a][b];
                        ++grid[i][j];

                        result += minimumMoves(grid);

                        ++grid[a][b];
                        --grid[i][j];

                        answer = std::min(answer, result);
                    }
                }
            }
        }

        return (answer == INT_MAX) ? 0 : answer;
    }
};
