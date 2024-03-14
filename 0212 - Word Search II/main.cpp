// trickier solution than most - again involving a trie
// construct a trie from the list of words then go through each character in the board and perform a dfs
// this isn't a great solution due to the std::set, but it was a means to an end to avoid duplicates

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words) {
        std::set<std::string> answer;

        TrieNode *root = buildTrie(words);

        for (int i = 0; i != board.size(); ++i) {
            for (int j = 0; j != board[0].size(); ++j) {
                dfs(board, i, j, root, answer);
            }
        }

        return std::vector<std::string>(answer.begin(), answer.end());
    }
private:
    struct TrieNode {
        std::array<TrieNode*, 26> next_;
        std::string word_;
    };

    TrieNode* buildTrie(const std::vector<std::string> &words) {
        TrieNode *root = new TrieNode();

        for (const auto &word : words) {
            TrieNode *letter = root;

            for (char c : word) {
                if (!letter->next_[c - 'a']) { letter->next_[c - 'a'] = new TrieNode(); }
                letter = letter->next_[c - 'a'];
            }

            letter->word_ = word;
        }

        return root;
    }

    void dfs(std::vector<std::vector<char>> &board, int i, int j, TrieNode *letter, std::set<std::string> &answer) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#' || !letter->next_[board[i][j] - 'a']) { return; }

        char c = board[i][j];
        if (!letter->next_[c - 'a']->word_.empty()) { answer.emplace(letter->next_[c - 'a']->word_); }

        letter = letter->next_[c - 'a'];
        
        board[i][j] = '#';

        dfs(board, i + 1, j, letter, answer);
        dfs(board, i - 1, j, letter, answer);
        dfs(board, i, j + 1, letter, answer);
        dfs(board, i, j - 1, letter, answer);

        board[i][j] = c;
    }
};

// there was another solution there everyone looks to have copied, but despite being fast, it wasn't very declarative, nor was it clean or idiomatic
// i've tidied it as best i can below, but it's still not very intuitive - i'll need to read more into why reversing words is beneficial
// or what a "haikya" is 

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words) {
        int n = board.size();
		int m = board[0].size();

		std::vector<std::string> answer;

		std::vector<std::vector<std::pair<int, int>>> vp(27);

		for (int i = 0; i != n; ++i) {
			for (int j = 0; j != m; ++j) {
				vp[board[i][j] - 'a'].push_back({ i, j });
            }
		}

		int beg = 0;
		int end = 0;

		for (const auto &word : words) {
			if (word.front() == 'a') { ++beg; }
			if (word.back()  == 'a') { ++end; }
        }

		bool reversehaikya = false;

		if (beg > end) {
			reversehaikya = true;
            for (auto &word : words) { std::reverse(word.begin(), word.end()); }
		}

		for (auto &word : words) {
			bool flag = false;

			for (auto [i, j] : vp[word[0] - 'a']) {
				flag = dfs(0, i, j, board, word, n, m);
				
                if (flag) {
					if (reversehaikya) { std::reverse(word.begin(), word.end()); }
					answer.emplace_back(word);
					break;
				}
			}
		}

		return answer;
    }
private:
    struct TrieNode {
        std::array<TrieNode*, 26> next_;
    };

    bool dfs(int pos, int i, int j, std::vector<std::vector<char>> &board, const std::string &word, int n, int m){
        if (pos == word.size())                 { return true; }
        if (i < 0 || i >= n || j < 0 || j >= m) { return false; }
        if (board[i][j] != word[pos])           { return false; }

        char c = board[i][j];

        board[i][j] = '#';
        
        bool found = dfs(pos + 1, i + 1, j, board, word, n, m) ||
                     dfs(pos + 1, i - 1, j, board, word, n, m) ||
                     dfs(pos + 1, i, j + 1, board, word, n, m) ||
                     dfs(pos + 1, i, j - 1, board, word, n, m);
        
        board[i][j] = c;
        
        return found;
    }
};
