// very slow recursie solution
class Solution {
public:
    // fibonacci
    int climbStairs(int n) {
        if (n < 4) { return n; }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// memoisation solution
// avoid unnecessary recusrive calculations by storing them for future referecne
std::vector<int> memo(46);

class Solution2 {
public:
    int climbStairs(int n) {
        if (n < 4)   { return memo[n] = n; }
        if (memo[n]) { return memo[n]; }
        return memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};
