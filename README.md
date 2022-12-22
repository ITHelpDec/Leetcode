# Leetcode – [![](https://tokei.ekzhang.com/b1/github/ITHelpDec/Leetcode?category=code&style=plastic)](https://github.com/ITHelpDec/Leetcode)

.:. Daily Challenge – 21/12/2022 .:.

Another graph traversal problem using BFS, DFS and Union-Find with and without link-by-rank and path compression.

A great artcile from Princeton on Union-Find – https://www.cs.princeton.edu/~wayne/kleinberg-tardos/pdf/UnionFind.pdf

```cpp
#include <vector>
#include <queue>
#include <iostream>
#include <chrono>
#include <numeric>
#include <queue>
#include <utility>

// // // // // // // //
/* BFS Solution      */
/* Time:  O(N + E)   */
/* Space: O(N + E)   */
// // // // // // // //

class Solution {
public:
    bool possibleBipartition(int n, const std::vector<std::vector<int>> &dislikes) {
        buildAdjacencyList(n, dislikes);
        
        return canAssignColours(n);
    }
private:
    std::vector<std::vector<int>> adj;
    std::vector<int> colours;
    
    void buildAdjacencyList(const int&, const std::vector<std::vector<int>>&);
    void printAdjacencyList(const std::vector<std::vector<int>>&);
    
    bool canAssignColours(const int&);
    bool bfs(const int&, std::vector<std::vector<int>>&);
};

inline void Solution::buildAdjacencyList(const int &n, const std::vector<std::vector<int>> &dislikes)
{
    adj.resize(n + 1);
    for (const auto &dislike : dislikes) {
        adj[dislike.front()].push_back(dislike.back());
        adj[dislike.back()].push_back(dislike.front());
    }
}

inline void Solution::printAdjacencyList(const std::vector<std::vector<int>> &adj) {
    for (const auto &vec : adj) {
        for (const auto &e : vec) {
            std::cout << e << ", ";
        } std::cout << std::endl;
    } std::cout << std::endl;
}

inline bool Solution::canAssignColours(const int &n)
{
    colours.resize(n + 1, -1);
    
    for (int i = 0; i != n; ++i)
        if (colours[i] == -1)
            if (!bfs(i, adj)) { return false; }
    
    return true;
}

inline bool Solution::bfs(const int &current, std::vector<std::vector<int>> &adj)
{
    std::queue<int> q;
    q.push(current);
    colours[current] = 0;
    
    while (!q.empty()) {
        int worker = q.front();
        q.pop();
        
        for (const auto &neighbour : adj[worker]) {
            if (colours[neighbour] == colours[worker]) { return false; }
            
            if (colours[neighbour] == -1) {
                colours[neighbour] = 1 - colours[worker];
                q.push(neighbour);
            }
        }
    }
    
    return true;
}

// // // // // // // //
/* DFS Solution      */
/* Time:  O(N + E)   */
/* Space: O(N + E)   */
// // // // // // // //

class Solution2 {
public:
    bool possibleBipartition(int n, const std::vector<std::vector<int>> &dislikes) {
        buildAdjacenyList(n, dislikes);
        return canAssignColours(n);
    }
private:
    std::vector<std::vector<int>> adj;
    std::vector<int> colours;
    
    void buildAdjacenyList(const int&, const std::vector<std::vector<int>>&);
    
    bool canAssignColours(const int&);
    bool dfs(const int&, const int&, const std::vector<std::vector<int>>&, std::vector<int>&);
};

inline void Solution2::buildAdjacenyList(const int &n, const std::vector<std::vector<int>> &dislikes)
{
    adj.resize(n + 1);
    
    for (const auto &dislike : dislikes) {
        adj[dislike.front()].push_back(dislike.back());
        adj[dislike.back()].push_back(dislike.front());
    }
}

inline bool Solution2::canAssignColours(const int &n)
{
    colours.resize(n + 1, -1);
    
    for (int i = 0; i != n; ++i)
        if (!dfs(i, i, adj, colours)) { return false; }
    
    return true;
}

inline bool Solution2::dfs(const int &node, const int &node_colour, const std::vector<std::vector<int>> &adj, std::vector<int> &colours)
{
    colours[node] = node_colour;
    
    for (const auto &neighbour : adj[node]) {
        if (colours[neighbour] == colours[node]) { return false;}
        
        if (colours[neighbour] == -1) {
            colours[neighbour] = 1 - colours[node];
            if (!dfs(neighbour, 1 - colours[node], adj, colours)) { return false; }
        }
    }
    
    return true;
}

// // // // // // // // // //
/* Union-find Solution     */
/* Time:  O(N + E)         */
/* Space: O(N + E)         */
// // // // // // // // // //

class Solution3 {
public:
    bool possibleBipartition(int n, const std::vector<std::vector<int>> &dislikes) {
        createParentVec(n, dislikes);
        createAdjacencyList(n, dislikes);
        
        return canAssignColours(n);
    }
private:
    std::vector<std::vector<int>> adj;
    std::vector<int> parents;
    
    void createParentVec(const int&, const std::vector<std::vector<int>>&);
    void createAdjacencyList(const int&, const std::vector<std::vector<int>>&);
    
    bool canAssignColours(const int&);
    int find(int&);
    void setParent(int&, int&);
    
    void printParentVec(const std::vector<int>&);
    void printAdjacencyList(const std::vector<std::vector<int>>&);
};

inline void Solution3::createAdjacencyList(const int &n, const std::vector<std::vector<int>> &dislikes)
{
    adj.resize(n);
    
    for (const auto &dislike : dislikes) {
        adj[dislike.front() - 1].push_back(dislike.back());
        adj[dislike.back() - 1].push_back(dislike.front());
    }
    
    // printAdjacencyList(adj);
}

inline void Solution3::createParentVec(const int &n, const std::vector<std::vector<int>> &dislikes)
{
    parents.resize(n);
    std::iota(parents.begin(), parents.end(), 1);
    // printParentVec(parents);
}

inline int Solution3::find(int &x)
{
     return parents[x - 1] == x ? x : find(parents[x - 1]);
}

inline void Solution3::setParent(int &x, int &y)
{
    if (x != y) {
        int a = find(x), b = find(y);
        parents[a - 1] = b;
    }
}

inline bool Solution3::canAssignColours(const int &n)
{
    for (int i = 1; i != n + 1; ++i) {
        for (auto &neighbour : adj[i - 1]) {
            if (find(i) == find(neighbour)) { return false; }
            
            setParent(adj[i - 1][0], neighbour);
        }
    }
    return true;
}

inline void Solution3::printParentVec(const std::vector<int> &parents) {
    for (const auto &parent : parents) {
        std::cout << parent << " ";
    } std::cout << std::endl;
}

inline void Solution3::printAdjacencyList(const std::vector<std::vector<int>> &adj)
{
    int i = 1;
    for (const auto &node : adj) {
        std::cout << i << ": ";
        for (const auto &neighbour : node) {
            std::cout << neighbour << " ";
        } std::cout << std::endl; ++i;
    } std::cout << std::endl;
}

// // // // // // // // // //
/* Union-find Solution     */
/* using link-by-rank and  */
/* ...path compression     */
/* Time:  O(N + E)         */
/* Space: O(N + E)         */
// // // // // // // // // //

class Solution4 {
public:
    bool possibleBipartition(int n, const std::vector<std::vector<int>> &dislikes) {
        createParentVec(n, dislikes);
        createAdjacencyList(n, dislikes);
        
        return canAssignColours(n);
    }
private:
    std::vector<std::vector<int>> adj;
    std::vector<int> parents, rank;
    
    void createParentVec(const int&, const std::vector<std::vector<int>>&);
    void createAdjacencyList(const int&, const std::vector<std::vector<int>>&);
    
    bool canAssignColours(const int&);
    int find(int&);
    void setParent(int&, int&);
    
    void printParentVec(const std::vector<int>&);
    void printAdjacencyList(const std::vector<std::vector<int>>&);
};

inline void Solution4::createAdjacencyList(const int &n, const std::vector<std::vector<int>> &dislikes)
{
    adj.resize(n);
    
    for (const auto &dislike : dislikes) {
        adj[dislike.front() - 1].push_back(dislike.back());
        adj[dislike.back() - 1].push_back(dislike.front());
    }
    
    // printAdjacencyList(adj);
}

inline void Solution4::createParentVec(const int &n, const std::vector<std::vector<int>> &dislikes)
{
    parents.resize(n);
    std::iota(parents.begin(), parents.end(), 1);
    // printParentVec(parents);
    
    rank.resize(n, 0);
    
}

inline int Solution4::find(int &x)
{
     return parents[x - 1] == parents[x - 1] ? parents[x - 1] : find(parents[x - 1]);
}

inline void Solution4::setParent(int &x, int &y)
{
    if (x != y) {
        int a = find(x), b = find(y);
        if (rank[a - 1] < rank[b - 1]) { std::swap(a, b); }
        parents[a - 1] = b;
        if (rank[a - 1] == rank[b - 1]) { ++rank[a - 1]; }
    }
}

inline bool Solution4::canAssignColours(const int &n)
{
    for (int i = 1; i != n + 1; ++i) {
        for (auto &neighbour : adj[i - 1]) {
            if (find(i) == find(neighbour)) { return false; }
            
            setParent(adj[i - 1][0], neighbour);
        }
    }
    return true;
}

inline void Solution4::printParentVec(const std::vector<int> &parents) {
    for (const auto &parent : parents) {
        std::cout << parent << " ";
    } std::cout << std::endl;
}

inline void Solution4::printAdjacencyList(const std::vector<std::vector<int>> &adj)
{
    int i = 1;
    for (const auto &node : adj) {
        std::cout << i << ": ";
        for (const auto &neighbour : node) {
            std::cout << neighbour << " ";
        } std::cout << std::endl; ++i;
    } std::cout << std::endl;
}

int main()
{
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    std::vector<std::vector<int>> test1 = { { 1, 2 }, { 1, 3 }, { 2, 4 } };
    std::vector<std::vector<int>> test2 = { { 1, 2 }, { 1, 3 }, { 2, 3 } };
    std::vector<std::vector<int>> test3 = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 5 }, { 1, 5 } };
    std::vector<std::vector<int>> test4 = { { 1, 2 }, { 2, 3 }, { 1, 3 }, { 2, 4 } };
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    std::cout << "Solution():  ";
    std::cout << Solution().possibleBipartition(4, test1) << ", ";
    std::cout << Solution().possibleBipartition(3, test2) << ", ";
    std::cout << Solution().possibleBipartition(5, test3) << ", ";
    std::cout << Solution().possibleBipartition(4, test4) << std::endl;

    std::cout << "Solution2(): ";
    std::cout << Solution2().possibleBipartition(4, test1) << ", ";
    std::cout << Solution2().possibleBipartition(3, test2) << ", ";
    std::cout << Solution2().possibleBipartition(5, test3) << ", ";
    std::cout << Solution2().possibleBipartition(4, test4) << std::endl;
    
    std::cout << "Solution3(): ";
    std::cout << Solution3().possibleBipartition(4, test1) << ", ";
    std::cout << Solution3().possibleBipartition(3, test2) << ", ";
    std::cout << Solution3().possibleBipartition(5, test3) << ", ";
    std::cout << Solution3().possibleBipartition(4, test4) << std::endl;
    
    std::cout << "Solution4(): ";
    std::cout << Solution4().possibleBipartition(4, test1) << ", ";
    std::cout << Solution4().possibleBipartition(3, test2) << ", ";
    std::cout << Solution4().possibleBipartition(5, test3) << ", ";
    std::cout << Solution4().possibleBipartition(4, test4) << "\n" << std::endl;
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    auto t1 = std::chrono::high_resolution_clock::now();
    auto t2 = std::chrono::high_resolution_clock::now();
    
    std::priority_queue<std::pair<double, std::string>, std::vector<std::pair<double, std::string>>, std::greater<>> min_heap;
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    t1 = std::chrono::high_resolution_clock::now();
    Solution().possibleBipartition(4, test1);
    Solution().possibleBipartition(3, test2);
    Solution().possibleBipartition(5, test3);
    Solution().possibleBipartition(4, test4);
    t2 = std::chrono::high_resolution_clock::now();
    auto result1 = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    min_heap.push( { result1, "Solution()" } );
    
    t1 = std::chrono::high_resolution_clock::now();
    Solution2().possibleBipartition(4, test1);
    Solution2().possibleBipartition(3, test2);
    Solution2().possibleBipartition(5, test3);
    Solution2().possibleBipartition(4, test4);
    t2 = std::chrono::high_resolution_clock::now();
    auto result2 = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    min_heap.push( { result2, "Solution2()" } );
    
    t1 = std::chrono::high_resolution_clock::now();
    Solution3().possibleBipartition(4, test1);
    Solution3().possibleBipartition(3, test2);
    Solution3().possibleBipartition(5, test3);
    Solution3().possibleBipartition(4, test4);
    t2 = std::chrono::high_resolution_clock::now();
    auto result3 = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    min_heap.push( { result3, "Solution3()" } );
    
    t1 = std::chrono::high_resolution_clock::now();
    Solution3().possibleBipartition(4, test1);
    Solution3().possibleBipartition(3, test2);
    Solution3().possibleBipartition(5, test3);
    Solution3().possibleBipartition(4, test4);
    t2 = std::chrono::high_resolution_clock::now();
    auto result4 = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    min_heap.push( { result4, "Solutio4()" } );
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    std::cout << "Solution()  took " << result1 << " nanoseconds." << "\n";
    std::cout << "Solution2() took " << result2 << " nanoseconds." << "\n";
    std::cout << "Solution3() took " << result3 << " nanoseconds." << "\n";
    std::cout << "Solution4() took " << result4 << " nanoseconds." << "\n" << std::endl;
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    std::cout << min_heap.top().second << " was the fastest solution" << "\n";
    
    double fastest = min_heap.top().first;
    min_heap.pop();
    
    while (!min_heap.empty()) {
        std::cout << "(" << min_heap.top().first / fastest
        << " times faster than "<< min_heap.top().second << "\n";
        min_heap.pop();
    }
    
    std::cout << std::endl;
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    return 0;
}
```
```
output:
Solution():  1, 0, 0, 0
Solution2(): 1, 0, 0, 0
Solution3(): 1, 0, 0, 0
Solution4(): 1, 0, 0, 0

Solution()  took 27062 nanoseconds.
Solution2() took 19644 nanoseconds.
Solution3() took 18944 nanoseconds.
Solution4() took 18739 nanoseconds.

Solutio4() was the fastest solution
(1.01094 times faster than Solution3()
(1.04829 times faster than Solution2()
(1.44415 times faster than Solution()

Program ended with exit code: 0
```
