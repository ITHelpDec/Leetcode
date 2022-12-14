#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>

// // // // // // // // // // //
/* runtime O(n) in O(1) space */
// // // // // // // // // // //
class Solution {
public:
    int rob(std::vector<int> &nums) {
        if (nums.size() < 3) { return *std::max_element(nums.begin(), nums.end()); }
        
        nums[1] = std::max(nums[0], nums[1]);

        for (int i = 2; i != nums.size(); ++i)
            nums[i] = std::max(nums[i - 1], nums[i] + nums[i - 2]);

        return nums.back();
    }
};

// // // // // // // // // // //
/* runtime O(n) in O(1) space */
/*  (3 temporary variables)   */
// // // // // // // // // // //
class Solution2 {
public:
    int rob(std::vector<int> &nums) {
        int prev1 = 0, prev2 = 0;
        for (const auto &e : nums) {
            int temp = prev1;
            prev1 = std::max(prev2 + e, prev1);
            prev2 = temp;
        }
        return prev1;
    }
};

void printVec(const std::vector<int> &ivec) {
    for (const auto &e : ivec) {
        std::cout << e << " ";
    } std::cout << std::endl;
}

int main()
{
    std::vector<int> test1_1 = { 1, 2, 3, 1 };
    std::vector<int> test2_1 = { 2, 7, 9, 3, 1 };
    std::vector<int> test3_1 = { 1, 2 };
    std::vector<int> test4_1 = { 1 };
    std::vector<int> test5_1 = { 1, 2, 3, 1, 7, 0, 0, 0, 0, 0, 10, 11 };
    std::vector<int> test6_1 = { 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 10 };
    std::vector<int> test7_1 = { 2, 1, 1, 2 };
    std::vector<int> test8_1(100);
    std::generate(test8_1.begin(), test8_1.end(), [] () { return rand() % 100; } );
    
    std::vector<int> test1_2 = { 1, 2, 3, 1 };
    std::vector<int> test2_2 = { 2, 7, 9, 3, 1 };
    std::vector<int> test3_2 = { 1, 2 };
    std::vector<int> test4_2 = { 1 };
    std::vector<int> test5_2 = { 1, 2, 3, 1, 7, 0, 0, 0, 0, 0, 10, 11 };
    std::vector<int> test6_2 = { 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 10 };
    std::vector<int> test7_2 = { 2, 1, 1, 2 };
    std::vector<int> test8_2(test8_1);
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    std::cout << "Solution().rob():  ";
    std::cout << Solution().rob(test1_1) << ", ";
    std::cout << Solution().rob(test2_1) << ", ";
    std::cout << Solution().rob(test3_1) << ", ";
    std::cout << Solution().rob(test4_1) << ", ";
    std::cout << Solution().rob(test5_1) << ", ";
    std::cout << Solution().rob(test6_1) << ", ";
    std::cout << Solution().rob(test7_1) << ", ";
    std::cout << Solution().rob(test8_1) << ", " << std::endl;
    
    std::cout << "Solution2().rob(): ";
    std::cout << Solution2().rob(test1_2) << ", ";
    std::cout << Solution2().rob(test2_2) << ", ";
    std::cout << Solution2().rob(test3_2) << ", ";
    std::cout << Solution2().rob(test4_2) << ", ";
    std::cout << Solution2().rob(test5_2) << ", ";
    std::cout << Solution2().rob(test6_2) << ", ";
    std::cout << Solution2().rob(test7_2) << ", ";
    std::cout << Solution2().rob(test8_2) << ", " << std::endl;
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    auto t1 = std::chrono::high_resolution_clock::now();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto t3 = std::chrono::high_resolution_clock::now();
    auto t4 = std::chrono::high_resolution_clock::now();
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i != 99999; ++i) {
        Solution().rob(test1_1);
        Solution().rob(test2_1);
        Solution().rob(test3_1);
        Solution().rob(test4_1);
        Solution().rob(test5_1);
        Solution().rob(test6_1);
        Solution().rob(test7_1);
        Solution().rob(test8_1);
    }
    t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Solution()  took " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds." << std::endl;
    
    t3 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i != 99999; ++i) {
        Solution().rob(test1_2);
        Solution().rob(test2_2);
        Solution().rob(test3_2);
        Solution().rob(test4_2);
        Solution().rob(test5_2);
        Solution().rob(test6_2);
        Solution().rob(test7_2);
        Solution().rob(test8_2);
    }
    t4 = std::chrono::high_resolution_clock::now();
    std::cout << "Solution2() took " << std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3).count() << " nanoseconds." << std::endl;
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    std::cout << ( (t2 - t1) < (t4 - t3) ? "Solution()" : "Solution2()")
    << " was " << (
    (t2 - t1) < (t4 - t3)
    ? (t4 - t3) * 1.0 / (t2 - t1)
    : (t2 - t1) * 1.0 / (t4 - t3)
    ) << " times faster." << std::endl;
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    return 0;
}

// output (debug mode):
// Solution().rob():  4, 12, 2, 1, 22, 19, 4, 2871,
// Solution2().rob(): 4, 12, 2, 1, 22, 19, 4, 2871,
// Solution()  took 267814526 nanoseconds.
// Solution2() took 282096844 nanoseconds.
// Solution() was 1.05333 times faster.
// Program ended with exit code: 0
