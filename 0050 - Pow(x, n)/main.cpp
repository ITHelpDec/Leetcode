// non-recursive solution e.g.
// x, n, a, y
// 2, 3, 1, 3
// 4, 3, 2, 1
// 16, 3, 8, 0

class Solution {
public:
    double myPow(double x, int n) {
        double answer = 1.0;
        int y = std::abs(n);
        
        while (y) {
            if (y % 2) { answer *= x; } // odd number
            x *= x;
            y /= 2;
        }

        return n < 0 ? 1 / answer : answer;
    }
};

// recursive solution taking advantage of switch cases (originally based off of multiple if statements)
// second case looks to be gcc-specific syntax

class Solution {
public:
    double myPow(double x, long n) {
        switch (n) {
            case 0:
                return 1;
                break;
            case std::numeric_limits<long>::min() ... -1:
                return 1 / myPow(x, -n);
                break;
            default:
                return n % 2 == 1
                    ? x * myPow(x, n - 1)
                    : myPow(x * x, n / 2);
        }
    }
};
