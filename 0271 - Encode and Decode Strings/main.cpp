// O(n) solutions for both
// crux of the solution is to add and then split by a delimiter (i used '\n')
// boost libraries can resolve this quickly

class Codec {
public:

    // Encodes a list of strings to a single string.
    std::string encode(const std::vector<std::string> &strs) {
        std::string answer;

        for (const auto &s : strs) { answer += s + '\n'; }

        return answer;
    }

    // Decodes a single string to a list of strings.
    std::vector<std::string> decode(const std::string &s) {
        std::vector<std::string> strs;
        std::string tmp;

        for (const char c : s) {
            if (c == '\n') {
                strs.emplace_back(tmp);
                tmp = "";
            } else {
                tmp += c;
            }
        }

        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
