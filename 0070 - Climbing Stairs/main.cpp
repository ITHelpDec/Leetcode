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

// bottom-up solutiuo
class Solution3 {
public:
    int climbStairs(int n) {
        if (n < 4) { return n; }
        
        int a = 2;
        int b = 3;

        for (int i = 4; i != n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }

        return a + b;
    }
};

// another bottom-up solition with fewer variables and operations in the loop
class Solution {
public:
    int climbStairs(int n) {
        if (n < 4) { return n; }
        
        int previous = 2;
        int current  = 3;

        for (int i = 3; i != n; ++i) {
            current += previous;
            previous = current - previous;
        }

        return current;
    }
};
