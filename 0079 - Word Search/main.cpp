// trickier matrix traversal combined with dfs
// my solution appears to be much slower than those on leetcode, but the approach is as follows:
// if we reach the length of the word, return true
// if we're out of bounds, and we can't find the character we're looking for, return false
// create offsets for your rows and columns then pass then into recursive dfs calls
// if any return true, stop searching and restore the character to what it was
// return whether we found the word or not

class Solution {
public:
    bool exist(std::vector<std::vector<char>> &board, const std::string &word) {
        int n = board.size();
        int m = board[0].size();
        
        for (int r = 0; r != n; ++r) {
            for (int c = 0; c != m; ++c) {
                if (dfs(r, c, board, word, 0, n, m)) { return true; }
            }
        }

        return false;
    }
private:
    template <typename B>
    bool dfs(int r, int c, B &board, const std::string &word, int i, int n, int m) {
        if (i == word.size()) { return true; }

        if (r != std::clamp(r, 0, n - 1) || c != std::clamp(c, 0, m - 1) || board[r][c] != word[i]) { return false; }

        board[r][c] = '#';

        std::vector<std::pair<int, int>> offsets = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0} };

        bool result = false;
        for (const auto [x, y] : offsets) {
            result = dfs(r + x, c + y, board, word, i + 1, n, m);
            if (result) { break; }
        }

        board[r][c] = word[i];

        return result;
    }
};
