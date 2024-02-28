// in order for the number to be palindromic, we need matching pairs
//
// first, we capture how many instances of each number there are from 0-9
// the end goal is to have two identical strings; one of which we flip, before joining the two strings together to create a palindrome
// we want the LARGEST number possible, so we start from '9' and work our way down to '0'
// each time we find a matching pair of a given number, we reduce the instances of that number by 2
// go through the remaining non-pairs and add the highest number in the middle (to the end of the lhs string)

class Solution {
public:
    std::string largestPalindromic(const std::string &num) {
        int count[10];
        for (const char digit : num) { ++count[digit - '0']; }

        std::string lhs;
        std::string rhs;

        for (const int i : num) {
            for (int j = 9; ~j; --j) {
                if (count[j] > 1 && (j > 0 || lhs.size())) {
                    lhs += '0' + j;
                    rhs += '0' + j;
                    count[j] -= 2;
                    break;
                }
            }
        }

        for (int i = 9; ~i; --i) {
            if (count[i]) {
                lhs += '0' + i;
                break;
            }
        }

        std::reverse(rhs.begin(), rhs.end());

        return lhs + rhs;
    }
};
