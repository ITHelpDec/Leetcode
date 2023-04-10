#ifndef Solution_hpp
#define Solution_hpp

class Solution {
public:
    bool detectCapitalUse(const std::string &word) {
        // std::cout << all_caps(word) << " " << all_lower(word) << " " << only_first(word) << std::endl;
        return all_caps(word) || all_lower(word) || only_first(word);
    }
    
    bool detectCapitalUse_mt(const std::string &word) {
        std::vector<std::thread> threads;
      
        threads.emplace_back(&Solution::all_caps_mt, this, word);
        threads.emplace_back(&Solution::all_lower_mt, this, word);
        threads.emplace_back(&Solution::only_first_mt, this, word);
      
        for (auto &t : threads) t.join();
        
        // std::cout << all_caps_result << " " << all_lower_result << " " << only_first_result << std::endl;
        return all_caps_result || all_lower_result || only_first_result;
    }
    
private:
    bool all_caps(const std::string&);
    bool all_lower(const std::string&);
    bool only_first(const std::string&);
    
    void all_caps_mt(const std::string&);
    void all_lower_mt(const std::string&);
    void only_first_mt(const std::string&);

    bool all_caps_result = false;
    bool all_lower_result = false;
    bool only_first_result = false;
};

inline bool Solution::all_caps(const std::string &word)
{
    for (const auto &c : word)
        if (std::islower(c)) { return false; }
    return true;
}

inline bool Solution::all_lower(const std::string &word)
{
    for (const auto &c : word)
        if (std::isupper(c)) { return false; }
    return true;
}

inline bool Solution::only_first(const std::string &word)
{
    for (const auto &c : word.substr(1))
        if (std::isupper(c)) { return false; }
    if (std::islower(word[0])) { return false; }
    return true;
}

inline void Solution::all_caps_mt(const std::string &word)
{
    for (const auto &c : word)
        if (std::islower(c)) { return; }
    all_caps_result = true;
}

inline void Solution::all_lower_mt(const std::string &word)
{
    for (const auto &c : word)
        if (std::isupper(c)) { return; }
    all_lower_result = true;
}

inline void Solution::only_first_mt(const std::string &word)
{
    for (const auto &c : word.substr(1))
        if (std::isupper(c)) { return; }
    if (std::islower(word[0])) { return; }
    only_first_result = true;
}

#endif /* Solution_hpp */
