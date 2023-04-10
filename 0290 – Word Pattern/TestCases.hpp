#ifndef TestCases_hpp
#define TestCases_hpp

#include <iostream>
#include <random>
#include <fstream>

class TestCases {
public:
    TestCases(std::size_t n) { generate(n); }
    
    void print()
    {
        for (const auto &[pattern, s] : testcases_) {
            // std::cout << "pattern =\n\"" << pattern << "\"\n"
            //           << "s =\n\"" << s << "\"\n"
            //           << "Solution =\n" << std::boolalpha
            //           << Solution().wordPattern(pattern, s)
            //           << "\n" << std::endl;
            
            // for finding only working solutions with larger testcases
            // if (Solution().wordPattern(pattern, s))
            std::cout << "\"" << pattern << "\"\n"
                      << "\"" << s << "\"\n"
                      << std::boolalpha
                      << Solution().wordPattern(pattern, s)
                      << "\n" << std::endl;
        }
    }
    
    void write()
    {
        std::ofstream output("testcases");
        
        for (const auto &[pattern, s] : testcases_) {
            // output << "pattern =\n\"" << pattern << "\"\n"
            //        << "s =\n\"" << s << "\"\n"
            //        << "Solution =\n" << std::boolalpha
            //        << Solution().wordPattern(pattern, s)
            //        << "\n" << std::endl;
            
            // for finding only working solutions with larger testcases
            if (Solution().wordPattern(pattern, s))
            output << "\"" << pattern << "\"\n"
                   << "\"" << s << "\"\n"
                   << std::boolalpha
                   << Solution().wordPattern(pattern, s)
                   << "\n" << std::endl;
        }
        
        output.close();
    }
    
private:
    std::vector<std::pair<std::string, std::string>> testcases_;
    
    void generate(std::size_t n)
    {   // generate patterns then s's
        for (int i = 0; i != n; ++i) {
            std::size_t pl = plength();
            std::string pattern(pl, ' ');
            std::generate(pattern.begin(), pattern.end(), [this] () { return c(); } );
            // std::cout << pattern_ << std::endl;
            
            std::string s;
            for (int i = 0; i != pl; ++i) {
                s.push_back(c());
                if (i != pl - 1) { s.push_back(' '); }
            }  // std::cout << "\"" << s << "\"" << std::endl;
            
            testcases_.push_back({ pattern, s });
        }
    }
    
    char c()
    {
        static std::default_random_engine e;
        static std::uniform_int_distribution u(0, 25);
        return 'z' - u(e);
    }
    
    std::size_t plength()
    {
        static std::default_random_engine e;
        static std::uniform_int_distribution u(1, 300);
        return u(e);
    }
};

#endif /* TestCases_hpp */
