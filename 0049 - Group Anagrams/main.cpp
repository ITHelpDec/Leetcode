// multi-pass O(n) solution
// create a map where the key is the sorted characters of each word, paired with the corresponding collection of words
// transfer each group of words to a suitable container and return

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;

        for (const auto &s : strs) {
            std::string chars = s;
            std::sort(chars.begin(), chars.end());
            map[chars].emplace_back(s);
        }

        std::vector<std::vector<std::string>> answer;

        for (const auto &[_, words] : map) { answer.emplace_back(words); }
        
        return answer;
    }
};
