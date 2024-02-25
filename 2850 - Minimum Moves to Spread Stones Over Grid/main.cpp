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

// faster DFS algorithm
class Solution {
public:
    int minimumMoves(std::vector<std::vector<int>> &grid) {
        dfs(0, 0, grid);
        return min_moves;
    }

private:
    int min_moves = INT_MAX;

    void dfs(int current, int moves, std::vector<std::vector<int>>& grid) {
        if (min_moves < moves) { return; }

        if (current == 9) {
            min_moves = std::min(min_moves, moves);
            return;
        }            

        int i = current / 3;
        int j = current % 3;

        if (grid[i][j]) {
            dfs(current + 1, moves, grid);
            return;
        }

        for (int a = 0; a != 3; ++a) {
            for (int b = 0; b != 3; ++b) {
                if (grid[a][b] < 2) { continue; }
                
                --grid[a][b];
                ++grid[i][j];

                dfs(current + 1, moves + std::abs(a - i) + std::abs(b - j), grid);
                
                ++grid[a][b];
                --grid[i][j];
            }
        }
    }
};
