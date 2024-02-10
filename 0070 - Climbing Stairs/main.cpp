// very slow recursie solution
class Solution {
public:
    // fibonacci
    int climbStairs(int n) {
        if (n < 4) { return n; }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
