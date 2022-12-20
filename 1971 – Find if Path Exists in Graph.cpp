#include <vector>
#include <queue>
#include <numeric>
#include <iostream>
#include <chrono>

// // // // // // // // //
/*  Solution using BFS  */
// // // // // // // // //

class Solution {
public:
    bool validPath(int n, std::vector<std::vector<int>>& edges,
                   int source, int destination) {
        
        bool v[n];
        std::memset(v, false, sizeof(v));
        std::vector<int> total[n];
        
        for (const auto &edge : edges) {
            total[edge.front()].push_back(edge.back());
            total[edge.back()].push_back(edge.front());
        }
        
        std::queue<int> q;
        q.push(source);
        
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            
            if (p == destination) { return true; }
            
            for (int i = 0; i != total[p].size(); ++i) {
                if (!v[total[p][i]]) {
                    q.push(total[p][i]);
                    v[total[p][i]] = true;
                }
            }
        }
        
        return false;
    }
};

// // // // // // // // // // // //
/*   Solution using Union-Find   */
// // // // // // // // // // // //

// 1: create vector to represent each node
// 2: work out the parent of each node
// 3: check that source and destination have the same parent ("are connected")

class Solution2 {
public:
    bool validPath(int n, const std::vector<std::vector<int>> &edges, int start, int end){
        createParentVec(n);
        setParents(edges);
        
        return find(start) == find(end);
    }
    
private:
    std::vector<int> parents;
    
    int find(const int&);
    
    void createParentVec(const int&);
    void setParent(const int&, const int&);
    void setParents(const std::vector<std::vector<int>>&);
    
    void printParentVec(const std::vector<int>&);
};

inline int Solution2::find(const int &x)
{
    return parents[x] == x ? x : find(parents[x]);
}

inline void Solution2::createParentVec(const int &n)
{
    parents.resize(n);
    std::iota(parents.begin(), parents.end(), 0);
}

inline void Solution2::setParent(const int &x, const int &y)
{
    if (x != y) {
        int a = find(x), b = find(y);
        parents[b] = a;
    }
}

inline void Solution2::setParents(const std::vector<std::vector<int>> &edges)
{
    for (const auto &edge : edges)
        if ( find(edge.front()) != find(edge.back()) )
            setParent(edge.front(), edge.back());
}

inline void Solution2::printParentVec(const std::vector<int> &parents) {
    for (const auto &parent : parents) {
        std::cout << parent << " ";
    } std::cout << std::endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void printTest(const std::vector<std::vector<int>> &test) {
    for (const auto &pair : test) {
        std::cout << "{ ";
        std::cout << pair.front() << ", " << pair.back();
        std::cout << " }, ";
    } std::cout << std::endl;
}

int main()
{
    std::vector<std::vector<int>> test1 = { {0,1},{1,2},{2,0} };
    std::vector<std::vector<int>> test2 = { {0,1},{0,2},{3,5},{5,4},{4,3} };
    
    std::vector<std::vector<int>> test3(100, std::vector<int>(2, 0));
    for (auto &v : test3) { v.front() = rand() % 10; v.back() = rand() % 10; }
    
    // printTest(test3);
    // test3 = {
    // { 7, 9 }, { 3, 8 }, { 0, 2 }, { 4, 8 }, { 3, 9 }, { 0, 5 }, { 2, 2 },
    // { 7, 3 }, { 7, 9 }, { 0, 2 }, { 3, 9 }, { 9, 7 }, { 0, 3 }, { 9, 8 },
    // { 6, 5 }, { 7, 6 }, { 2, 7 }, { 0, 3 }, { 9, 9 }, { 9, 1 }, { 7, 2 },
    // { 3, 6 }, { 5, 5 }, { 8, 1 }, { 4, 7 }, { 1, 3 }, { 8, 4 }, { 8, 0 },
    // { 4, 6 }, { 0, 3 }, { 2, 6 }, { 9, 4 }, { 1, 3 }, { 7, 8 }, { 8, 3 },
    // { 8, 1 }, { 5, 3 }, { 5, 4 }, { 3, 6 }, { 5, 9 }, { 5, 4 }, { 9, 1 },
    // { 7, 5 }, { 5, 4 }, { 1, 8 }, { 8, 3 }, { 5, 2 }, { 2, 6 }, { 6, 7 },
    // { 8, 4 }, { 1, 7 }, { 1, 8 }, { 7, 8 }, { 7, 7 }, { 4, 4 }, { 9, 1 },
    // { 5, 5 }, { 5, 8 }, { 2, 9 }, { 8, 2 }, { 0, 7 }, { 4, 8 }, { 5, 8 },
    // { 3, 0 }, { 6, 2 }, { 2, 5 }, { 2, 2 }, { 7, 1 }, { 5, 2 }, { 1, 1 },
    // { 0, 1 }, { 8, 7 }, { 6, 0 }, { 0, 9 }, { 5, 6 }, { 2, 8 }, { 5, 9 },
    // { 4, 3 }, { 9, 0 }, { 5, 6 }, { 3, 6 }, { 3, 0 }, { 8, 4 }, { 0, 4 },
    // { 6, 4 }, { 6, 4 }, { 3, 8 }, { 4, 0 }, { 0, 9 }, { 3, 7 }, { 5, 7 },
    // { 2, 9 }, { 7, 5 }, { 6, 5 }, { 3, 0 }, { 4, 8 }, { 5, 5 }, { 5, 4 },
    // { 2, 1 }, { 9, 2 }
    // };
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    std::cout << "Solution():  ";
    std::cout << Solution().validPath(3, test1, 0, 2) << ", ";
    std::cout << Solution().validPath(6, test2, 0, 5) << ", ";
    std::cout << Solution().validPath(100, test3, 0, 12) << std::endl;
    
    std::cout << "Solution2(): ";
    std::cout << Solution2().validPath(3, test1, 0, 2) << ", ";
    std::cout << Solution2().validPath(6, test2, 0, 5) << ", ";
    std::cout << Solution2().validPath(100, test3, 0, 12) << "\n" << std::endl;
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    auto t1 = std::chrono::high_resolution_clock::now();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto t3 = std::chrono::high_resolution_clock::now();
    auto t4 = std::chrono::high_resolution_clock::now();
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    t1 = std::chrono::high_resolution_clock::now();
    Solution().validPath(3, test1, 0, 2);
    Solution().validPath(6, test2, 0, 5);
    Solution().validPath(100, test3, 0, 12);
    t2 = std::chrono::high_resolution_clock::now();
    auto result1 = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    
    t3 = std::chrono::high_resolution_clock::now();
    Solution2().validPath(3, test1, 0, 2);
    Solution2().validPath(6, test2, 0, 5);
    Solution2().validPath(100, test3, 0, 12);
    t4 = std::chrono::high_resolution_clock::now();
    auto result2 = std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3).count();
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    std::cout << "Solution()  took " << result1 << " nanoseconds." << std::endl;
    std::cout << "Solution2() took " << result2 << " nanoseconds." << std::endl;
    
    std::cout << (result1 < result2 ? "\nSolution()" : "\nSolution2()") << " was "
    << (result1 < result2 ? result2 * 1.0 / result1 : result1 * 1.0 / result2)
    << " times faster.\n" << std::endl;
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    return 0;
}
