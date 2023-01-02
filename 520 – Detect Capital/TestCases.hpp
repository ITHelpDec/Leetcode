#ifndef TestCases_hpp
#define TestCases_hpp

class TestCases {
public:
    TestCases(std::size_t n) { generate(n); }
    
    void print()
    {
        for (const auto &word : testcases_) {
            std::cout << "\"" << word << "\"\n"
                      << std::boolalpha
                      << Solution().detectCapitalUse_mt(word)
                      << "\n" << std::endl;
        }
    }
    
    void write()
    {
        std::cout << "Creating test case file...";
        std::ofstream output("testcases");
        
        for (const auto &word : testcases_) {
            output << "\"" << word << "\"\n"
                   << std::boolalpha
                   << Solution().detectCapitalUse(word)
                   << "\n" << std::endl;
        }
        
        output.close();
        
        std::cout << "...file created successfully." << std::endl;
    }
    
    void benchmark()
    {
        auto t1 = std::chrono::high_resolution_clock::now();
        auto t2 = std::chrono::high_resolution_clock::now();
        auto result = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t2).count();
        
        for (const auto &word : testcases_) {
            t1 = std::chrono::high_resolution_clock::now();
            Solution().detectCapitalUse(word);
            t2 = std::chrono::high_resolution_clock::now();
            result += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
        }
        
        std::cout << "Your solution took " << result << " nanoseconds across "
                  << testcases_.size() << " test cases." << std::endl;
    }
    
    void benchmark_mt()
    {
        auto t1 = std::chrono::high_resolution_clock::now();
        auto t2 = std::chrono::high_resolution_clock::now();
        auto result = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t2).count();
        
        for (const auto &word : testcases_) {
            t1 = std::chrono::high_resolution_clock::now();
            Solution().detectCapitalUse_mt(word);
            t2 = std::chrono::high_resolution_clock::now();
            result += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
        }
        
        std::cout << "Your solution took " << result << " nanoseconds across "
                  << testcases_.size() << " test cases." << std::endl;
    }
    
private:
    std::string testcase_;
    std::vector<std::string> testcases_;
    
    void generate(const std::size_t &n)
    {
        for (std::size_t i = 0; i != n; ++i) {
            testcase_.resize(length());
            std::generate(testcase_.begin(), testcase_.end(), [this] () { return c(); });
            testcases_.push_back(testcase_);
        }
    }
    
    char c()
    {
        static std::default_random_engine e;
        static std::bernoulli_distribution b(0.1);
        static std::uniform_int_distribution upper_u('A', 'Z');
        static std::uniform_int_distribution lower_u('a', 'z');
        return b(e) ? upper_u(e) : lower_u(e);
    }
    
    std::size_t length()
    {
        static std::default_random_engine e;
        static std::uniform_int_distribution u(1, 100);
        return u(e);
    }
};

#endif /* TestCases_hpp */
