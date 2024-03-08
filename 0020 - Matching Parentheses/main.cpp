// nice solution with a std::stack and switch cases
// if we find an opening parenthesis, we add it to the stack
// if we encounter a closing parenthesis, make sure we have a matching open parenthesis; pop and break if we do - otherwise, return false
// we should have an empty stack by the time we finish traversing the string

class Solution {
public:
    bool isValid(const std::string &s) {
        std::stack<char> cstk;

        for (const char c : s) {
            switch (c) {
                case '(':
                case '[':
                case '{':
                    cstk.push(c);
                    break;
                case ')':
                    if (cstk.empty() || cstk.top() != '(') { return false; }
                    cstk.pop();
                    break;
                case ']':
                    if (cstk.empty() || cstk.top() != '[') { return false; }
                    cstk.pop();
                    break;
                case '}':
                    if (cstk.empty() || cstk.top() != '{') { return false; }
                    cstk.pop();
                    break;
            }
        }
        
        return cstk.empty();
    }
};
