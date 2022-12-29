#ifndef Header_h
#define Header_h

#include <algorithm>
#include <fstream>
#include <random>

class TestCases {
public:
    TestCases(std::size_t n) : n_(n) { generate(); }
    
    const std::vector<std::vector<int>>& generate()
    {
        for (int i = 0; i != n_; ++i) {
            testcase_.resize(length());
            std::generate(testcase_.begin(), testcase_.end(), [this] () { return element(); } );
            testcases_.push_back(testcase_);
        }
        return testcases_;
    }
    
    void write()
    {
        std::ofstream output("testcases");
        
        for (const auto &testcase : testcases_) {
            int k = this->k();
            output << "[";
            for (const auto &e : testcase) {
                output << e << ",";
            } output.seekp(-1, std::ofstream::end);
            output << "]\nk: " << k << "\n";
            output << "ans: " << Solution().minStoneSum(testcase, k) << "\n" << std::endl;
        }
        
        output.close();
    }
    
    void print()
    {
        for (const auto &testcase : testcases_) {
            int k = this->k();
            std::cout << "[";
            for (const auto &e : testcase) {
                std::cout << e << ",";
            } std::cout << std::cout.tellp();
            std::cout << "]\nk: " << k << "\n";
            std::cout << "ans: " << Solution().minStoneSum(testcase, k) << "\n" << std::endl;
        }
    }
    
    
private:
    std::vector<int> testcase_;
    std::vector<std::vector<int>> testcases_;
    std::size_t n_;
    
    int length() {
        static std::default_random_engine e;
        static std::uniform_int_distribution u(1, 10);
        return u(e);
    }
    
    int element() {
        static std::default_random_engine e;
        static std::uniform_int_distribution u(1, 100);
        return u(e);
    }
    
    int k() {
        static std::default_random_engine e;
        static std::uniform_int_distribution u(1, 10);
        return u(e);
    }
    
};

#endif /* Header_h */
