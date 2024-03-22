// use two stacks to create a queue
// best to think of it like a stack of plates - pile everything up, then put it on to another stack

class MyQueue {
public:
    MyQueue() = default;

    void push(int x) { main_.push(x); }

    int pop() {
        transfer();
        int topElement = backup_.top();
        backup_.pop();
        return topElement;
    }

    int peek() {
        transfer();
        return backup_.top();
    }

    bool empty() { return main_.empty() && backup_.empty(); }
private:
    std::stack<int> main_;
    std::stack<int> backup_;

    void transfer() {
        if (backup_.empty()) {
            while (!main_.empty()) {
                int element = main_.top();
                main_.pop();
                backup_.push(element);
            }
        }
    }
};
