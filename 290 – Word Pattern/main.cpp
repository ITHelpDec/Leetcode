#include "Solution.hpp"
#include "TestCases.hpp"

int main()
{
    std::cout << std::boolalpha
              << Solution().wordPattern("abba", "dog cat cat dog") << "\n"
              << Solution().wordPattern("abba", "dog cat cat fish") << "\n"
              << Solution().wordPattern("abba", "dog dog dog dog") << "\n"
              << Solution().wordPattern("a", "a") << "\n"
              << Solution().wordPattern("manbearpig", "manbearpig") << std::endl;
    
    // TestCases(9999).print();
    TestCases(9999).write();
    
    return 0;
}
