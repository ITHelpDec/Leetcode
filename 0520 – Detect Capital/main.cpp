#include <string>
#include <iostream>
#include <vector>
#include <thread>
#include "Solution.hpp"

#include <random>
#include <fstream>
#include <chrono>
#include "TestCases.hpp"

int main()
{
    // std::cout << "No multi-threading...\n" << std::boolalpha;
    // std::cout << Solution().detectCapitalUse("usa") << ", ";
    // std::cout << Solution().detectCapitalUse("USA") << ", ";
    // std::cout << Solution().detectCapitalUse("leetcode") << ", ";
    // std::cout << Solution().detectCapitalUse("Google") << ", ";
    // std::cout << Solution().detectCapitalUse("Leetcode") << ", ";
    // std::cout << Solution().detectCapitalUse("WooF") << std::endl;
    
    // std::cout << "YES multi-threading...\n";
    // std::cout << Solution().detectCapitalUse_mt("usa") << ", ";
    // std::cout << Solution().detectCapitalUse_mt("USA") << ", ";
    // std::cout << Solution().detectCapitalUse_mt("leetcode") << ", ";
    // std::cout << Solution().detectCapitalUse_mt("Google") << ", ";
    // std::cout << Solution().detectCapitalUse_mt("Leetcode") << ", ";
    // std::cout << Solution().detectCapitalUse_mt("WooF") << std::endl;
    
    TestCases obj(20);
    
    obj.benchmark();
    obj.benchmark_mt();
    
    obj.write();
    
    return 0;
}

// multithreaded approach doesn't seem right...
//
// Your solution took 4206 nanoseconds across 20 test cases.
// Your solution took 2820166 nanoseconds across 20 test cases.
// Creating test case file......file created successfully.
// Program ended with exit code: 0
