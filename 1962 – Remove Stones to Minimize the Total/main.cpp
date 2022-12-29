#include "Solution.hpp"
#include "TestCases.hpp"

int main()
{
    // Example test cases
    // std::vector<int> test1 = { 5, 4, 9 };
    // std::vector<int> test2 = { 4, 3, 6, 7 };

    // Print out 10 test cases with solutions
    TestCases(10).print();
    
    // Write out 10 test cases solutions
    TestCases(10).write();
    
    return 0;
}
