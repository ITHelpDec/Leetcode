// O(n) solution
// keep a set of the operators to refer to, and iterate through the tokens
// if we can't find any of the token, we assume the token is a number and add it to our stack
// otherwise we follow through with the switch case statement for whichever operator we land on, and push the result to our stack
// the top of the stack will return our answer
// NB: a lot of other solutions used multiple if-else statements - a switch statement felt more appropriate

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stk;
        std::unordered_set<std::string> ops = { "+", "-", "*", "/" };

        for (const auto &token : tokens) {
            if (!ops.count(token)) {
                stk.push(std::stoi(token));
            } else {
                int k1 = stk.top();
                stk.pop();

                int k2 = stk.top();
                stk.pop();

                switch (token[0]) {
                    case '+':
                        stk.push(k1 + k2);
                        break;
                    case '-':
                        stk.push(k2 - k1);
                        break;
                    case '*':
                        stk.push(k1 * k2);
                        break;
                    case '/':
                        stk.push(k2 / k1);
                        break;
                }
            }
        }
        
        return stk.top();
    }
};
